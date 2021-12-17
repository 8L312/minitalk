/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:56:08 by rmonney           #+#    #+#             */
/*   Updated: 2021/11/16 13:38:55 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i ++;
		}
		return (i);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

int	which_putnbr(int n, char flag)
{
	int	count;

	count = 0;
	if (flag == 'd' || flag == 'i')
		count = ft_putnbr(n);
	else if (flag == 'u')
		count = ft_putunbr((unsigned int)n);
	return (count);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = 0;
	count = 0;
	nb = n;
	if (nb < 0)
	{
		write(1, &"-", 1);
		count++;
		nb *= -1;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
		count++;
	}
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	unsigned long	nb;
	int				count;

	nb = n;
	count = 0;
	if (n < 0)
	{
		nb += 4294967295;
	}
	if (nb > 9)
	{
		count += ft_putunbr(nb / 10);
		count += ft_putunbr(nb % 10);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
		count++;
	}
	return (count);
}
