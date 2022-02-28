/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:03:21 by rmonney           #+#    #+#             */
/*   Updated: 2021/11/16 13:38:28 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	whatflag(const char *str, int i)
{
	char	flag;

	flag = 0;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		flag = 0;
	else
		flag = str[i + 1];
	return (flag);
}

int	printer(const char *str, int i)
{
	while (str[i] != '%' && str[i] != '\0')
		write(1, &str[i++], 1);
	if (str[i] == '%')
		i += 2;
	return (i);
}

int	printcounter(const char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] != '%' && str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

int	flag_handler(char flag, long int spec)
{
	int	count;

	count = 0;
	if (flag == 'c')
		count += ft_putchar((int)spec);
	if (flag == 's')
		count += ft_putstr((char *)spec);
	if (flag == 'p')
		count += ptrprint((unsigned long)spec);
	if (flag == 'd' || flag == 'i' || flag == 'u')
		count += which_putnbr((int)spec, flag);
	if (flag == 'x' || flag == 'X')
		count += which_hexa((int)spec, flag);
	if (flag != 'c' && flag != 's' && flag != 'p' && flag != 'd' && flag != 'i'
		&& flag != 'u' && flag != 'x' && flag != 'X' && flag != 0)
		count = -1;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	char	flag;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0' && count != -1)
	{
		flag = whatflag(str, i);
		count += printcounter(str, i);
		i = printer(str, i);
		if (flag == '%')
			count += ft_putchar(flag);
		else
			count += flag_handler(flag, va_arg(args, long int));
	}
	va_end(args);
	return (count);
}
