/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:25:17 by rmonney           #+#    #+#             */
/*   Updated: 2021/11/12 17:33:49 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ptrprint(unsigned long ptr)
{
	long	nbr_final[12];
	int		i;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	count = 0;
	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	while (ptr > 0)
	{
		nbr_final[i++] = ptr % 16;
		ptr /= 16;
	}
	count = i;
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (count + 2);
}

int	which_hexa(int n, char flag)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (flag == 'x')
		count = hexaprint(n, "0123456789abcdef");
	else if (flag == 'X')
		count = hexaprint(n, "0123456789ABCDEF");
	return (count);
}

int	hexaprint(long nbr, char *base)
{
	long	nbr_final[8];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (nbr < 0)
	{
		nbr += 4294967296;
		i = 0;
	}
	while (nbr > 0)
	{
		nbr_final[i++] = nbr % 16;
		nbr /= 16;
	}
	count = i;
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (count);
}
