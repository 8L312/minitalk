/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:57:35 by rmonney           #+#    #+#             */
/*   Updated: 2021/11/12 14:45:22 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		flaghandler(char flag, long int spec);
char	whatflag(const char *str, int i);
int		printer(const char *str, int i);
int		printcounter(const char *str, int i);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		which_putnbr(int n, char flag);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ptrprint(unsigned long ptr);
int		which_hexa(int n, char flag);
int		hexaprint(long nbr, char *base);

#endif
