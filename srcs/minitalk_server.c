/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:03:40 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 15:47:01 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info);

int	main(void)
{
	ft_printf("\033[1;32mSERVER ONLINE\nPID: [%d]\n\033[0m", getpid());
	mt_signal(SIGUSR1, handler, true);
	mt_signal(SIGUSR2, handler, true);
	while (1)
		pause ();
	return (0);
}

void	process_message(char *message, pid_t client)
{
	ft_printf("\033[36mClient:\033[0m %s\n", message);
	mt_kill(client, SIGUSR2);
}

void	handler(int sig_nb, siginfo_t *info)
{
	static char		message[1024];
	static int		bit = 0;
	static int		index = 0;
	static pid_t	client;

	if (info->si_pid)
		client = info->si_pid;
	message[index] |= (sig_nb == SIGUSR1) << (7 - bit);
	bit++;

	if (bit == 8)
	{
		bit = 0;
		if (message[index] == '\0')
		{
			process_message(message, client);
			index = 0;
			return;
		}
		index++;
	}
	mt_kill(client, SIGUSR1);
}
