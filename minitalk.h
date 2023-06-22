/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:59:15 by elrichar          #+#    #+#             */
/*   Updated: 2023/06/18 14:54:01 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

void	ft_send_bits(int pid, char c);
void	ft_handler(int signum, siginfo_t *siginfo, void *context);
int		ft_atoi(const char *str);
void	ft_end_signal(int signum);

#endif