/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:01:15 by elrichar          #+#    #+#             */
/*   Updated: 2023/06/22 16:49:14 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
			usleep(10);
			ft_printf("\n");
		}
		else
			ft_printf("%c", octet);
		octet = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Welcome ! Current PID : %d\n", pid);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			ft_printf("Sigaction failure\n");
			exit (EXIT_FAILURE);
		}
	}
	return (0);
}
