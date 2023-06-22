/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:42:13 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/17 14:51:23 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ulen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int n, const char c)
{
	char	*hex1;
	char	*hex2;
	int		len_el;

	hex1 = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	len_el = ft_ulen(n);
	if (n >= 16)
		ft_puthex((n / 16), c);
	n = n % 16;
	if (c == 'x')
		write(1, &hex1[n], 1);
	else if (c == 'X')
		write(1, &hex2[n], 1);
	return (len_el);
}

static int	ft_ualen(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_putaddr(unsigned long n)
{
	char	*hex;
	int		len_el;

	hex = "0123456789abcdef";
	len_el = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		len_el = 5;
		return (len_el);
	}
	len_el = ft_ualen(n);
	if (n >= 16)
		ft_putaddr((n / 16));
	n = n % 16;
	write(1, &hex[n], 1);
	return (len_el);
}
