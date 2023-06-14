/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:48 by elrichar          #+#    #+#             */
/*   Updated: 2023/06/14 13:54:53 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int	octet;
	static int	i;

	(void)context;
	if (signum == SIGUSR1)
	{
		octet <<= 1;
		octet |= 1;
	}
	else
		octet <<= 1;
	i++;
	if (i == 8)
	{
		if (octet == '\0')
		{
			kill(siginfo->si_pid, SIGUSR1);
			usleep(100);
			ft_printf("\n");
		}
		else
			ft_printf("%c", i);
		octet = 0;
		i = 0;
	}
}

/* Notre fonction de gestion du signal. 
On déclare 2 variables statiques pour pouvoir garder leur valeur au fil des appels à la fonction.
i : notre compteur de 1 à 8 pour savoir où on est dans l'octet
octet : notre octet, sous forme de int, qui est notre caractère
Si on reçoit le bit 1, on décale tous les bits déjà écrits sur la gauche et à l'aide d'un masque
on met 1 tout à droite 
Si on reçoit le bit 0 on se contente de décaler tous les bits, le nouveau sera automatiquement
mis à 0
on incrémente i à chaque tour 
Si i = 8 alors on a un octet complet. On l'affiche et on remet nos variables à 0
Si l'octet qu'on a reçu et écrit était \0 alors on a fini d'afficher le message
On envoie alors un signal au client pour l'informer de la bonne réception du message 
*/

int	main(void)
{
	pid_t	pid;
	struct sigaction	sa;

	pid = getpid();
	printf("Welcome ! Current PID : %d\n", pid);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			printf("Sigaction failure\n");
			exit (EXIT_FAILURE);
		}
		pause();
	}
	return (0);
}

/* Le main. On a notre PID et la structure sa utilisée pour la fonction sigaction.
On initialise les composantes de la struct qui nous intéressent :
sa_sigaction : la fonction qu'on utilisera pour traiter le signal avec les infos supp
sa_flags : SIGINFO pour indiquer qu'on veut initialiser la struct siginfo contenant les infos supp
On crée une boucle infinie qui nous permet de rester en permanence à l'écoute des signaux 1 et 2
On initialise sigaction pour les 2 signaux (on utilise la même struct mais on aurait pu en créer 2
avec chacune une fonction de traitement différent pour le signal)
On vérifie qu'il n'y a pas d'erreur (donc 2 actions en une)
chaque fois qu'on reçoit un signal on reste en pause() jusqu'à ce qu'on en reçoive un nouveau
On n'en sort que s'il y a un échec de sigaction.
On n'aurait pas pu initialiser d'abord sigaction car le faire 2 fois est inutile. 
*/