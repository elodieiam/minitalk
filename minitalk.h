/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:59:15 by elrichar          #+#    #+#             */
/*   Updated: 2023/06/10 21:05:53 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>


void	ft_send_bits(int pid, char c);
void	ft_handler(int signum, siginfo_t *siginfo, void *context);
int		ft_atoi(const char *str);
void	ft_end_signal(int signum);

#endif