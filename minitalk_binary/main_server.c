/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:15:54 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/17 15:33:09 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *empty)

{
	(void)info;
	(void)empty;
	static int bit = 0;
	if (signum == SIGUSR1)
	{
		write(1, "1", 1);
		bit++;
	}
	else
	{
		write(1, "0", 1);
		bit++;
	}
	if (bit == 8)
	{
		write(1, "\n", 1);
		bit = 0;
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
