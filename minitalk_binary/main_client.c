/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:16:47 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/17 15:29:23 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_isdigit(int c)
{
	int	a;

	a = 0;
	if (47 < c && c <= 57)
		a++;
	return (a);
}

void	send(int pid, char byte)
{
	static int	j;

	j = 0;
	while (j < 8)
	{
		if ((byte >> j) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				printf("Bad PID\n");
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				printf("Bad PID\n");
				exit(0);
			}
		}
		j++;
		usleep(50);
	}
}

void	sender(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send(pid, msg[i]);
		i++;
	}
//	send(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("wrong usage : ./client [PID] [message]\n");
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf("wrong usage : ./client [PID] [message]\n");
			return (0);
		}
	}
	sender(ft_atoi(argv[1]), argv[2]);
	return (0);
}
