/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:40 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/19 19:10:16 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit_pos;
	pid_t		sender_pid;

	(void)(context);
	(void)(info);
	sender_pid = info->si_pid;
	c |= (sig == SIGUSR2) << (7 - bit_pos);
	bit_pos++;
	if (bit_pos == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(sender_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		c = 0;
		bit_pos = 0;
	}
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
	{
		pause();
	}
	return (0);
}
