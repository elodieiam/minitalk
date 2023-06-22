/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:00:24 by elrichar          #+#    #+#             */
/*   Updated: 2023/06/22 16:48:08 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		ft_printf("The message has been fully transmitted.\n");
}

void	ft_send_bits(int pid, char c)
{
	int	i;

	if (pid <= 0)
	{
		ft_printf("PID error.\n");
		exit (EXIT_FAILURE);
	}
	i = 7;
	while (i >= 0)
	{
		if (c & 1 << i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Invalid number of arguments\n");
		exit (EXIT_FAILURE);
	}
	i = 0;
	sa.sa_handler = ft_end_signal;
	pid = ft_atoi(argv[1]);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Sigaction failure\n");
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
