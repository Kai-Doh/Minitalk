/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:40 by ktiomico          #+#    #+#             */
/*   Updated: 2025/03/21 00:45:39 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char		c;
	static int		bit_pos;
	static pid_t	pid_client;

	(void)context;
	if (info->si_pid != 0)
		pid_client = info->si_pid;
	if (sig == SIGUSR1)
		c |= (0b10000000 >> bit_pos);
	else if (sig == SIGUSR2)
		c &= ~(0b10000000 >> bit_pos);
	bit_pos++;
	if (bit_pos == 8)
	{
		bit_pos = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(pid_client, SIGUSR2);
			return ;
		}
		write(1, &c, 1);
	}
	kill(pid_client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_action;

	ft_memset(&s_action, 0, sizeof(s_action));
	ft_printf("\033[1;32mSERVER ONLINE\nPID: [%d]\n\033[0m", getpid());
	ft_printf("\033[1;32m-------------------\n\033[0m");
	s_action.sa_sigaction = handle_signal;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, 0);
	sigaction(SIGUSR2, &s_action, 0);
	while (1)
		pause();
	return (0);
}
