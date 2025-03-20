/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:40 by ktiomico          #+#    #+#             */
/*   Updated: 2025/03/20 15:46:46 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit_pos = 0;
	static pid_t			client_pid = 0;

	(void)(context);
	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= 1;
	if (++bit_pos == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR1);
			client_pid = 0;
		}
		else
			write(1, &c, 1);
		c = 0;
		bit_pos = 0;
	}
	else
		c <<= 1;
	usleep(50);
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
