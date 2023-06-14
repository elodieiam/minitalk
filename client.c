/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:17:29 by elrichar          #+#    #+#             */
/*   Updated: 2023/06/14 11:16:27 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
	sign = -1;
	i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9' )
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_end_signal(int signum)
{
	if (signum == SIGUSR1)
	printf("The message has been fully transmitted.\n");
}

void	ft_send_bits(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & 1 << i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

/* On envoie les bits de gauche à droite car ils sont
récupérés dans cet ordre par le serveur puis progressivement
décalés vers la gauche. On commence donc par le bit le + significatif
on compare à chaque tour notre octet avec l'octet 1
décalé de i vers la gauche.
Ex : au 1er tour : 1010 1010 & 1000 0000
& donne 1 si les 2 bits valent 1. c'est donc un test qui permet
de savoir si le bit est 1 ou 0
il est important laisser usleep et i-- dans cet ordre.
i-- prend forcément un peu de temps pr s'exécuter et c'est décompté du temps de usleep.
*/

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	sa.sa_handler = ft_end_signal;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
		{
			printf("Sigaction failure\n");
			exit (EXIT_FAILURE);
		}
		while (argv[2][i])
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\0');
		return (0);
	}
}

/* Dans notre main on récupère le pid du serveur dont on a besoin pr pouvoir lui envoyer des signaux
Pour cela, on utilise notre fonction atoi appliquée à argv[1] qui contient le pid
On parcourt argv[2] et on envoie chaque bit à ft_send_bit
On envoie le caractère NULL à la fin pour indiquer la fin du message 
On utilise une nouvelle fois la fonction sigaction pour définir le comportement 
à tenir si l'on reçoit le signal SIGUSR1. 
Dans notre structure sigaction on utilise la composante sa_handler car on n'a pas besoin 
des infos supp et de la struc siginfo.

En C, lorsqu'on utilise le nom d'une fonction sans les parenthèses (), 
cela représente un pointeur sur cette fonction.

La structure struct sigaction possède un membre sa_handler qui doit être un pointeur 
de type void (*)(int), c'est-à-dire un pointeur vers une fonction prenant un paramètre 
de type int et renvoyant void. En assignant ft_end_signal à sa.sa_handler, 
vous lui donnez l'adresse de cette fonction pour qu'elle puisse être utilisée 
comme gestionnaire de signal.
*/