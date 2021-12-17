/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:15:54 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/16 23:54:06 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *empty)

{
	static int	value = 0;
	static int	bit = 0;

	(void)info;
	(void)empty;
	if (signum == SIGUSR1)
		value += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &value, 1);
		bit = 0;
		value = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	pid = getpid();
	printf("pid = %d\n", pid);
	while (1)
		pause();
	return (0);
}
