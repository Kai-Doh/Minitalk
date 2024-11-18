/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:58:54 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 16:04:50 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_send(char c, pid_t server);
void	ack_handler(void);
void	end_handler(void);

volatile sig_atomic_t	g_server = SERVER_BUSY;

int	main(int ac, char **av)
{
	pid_t	server;
	char	*content;

	if (ac != 3)
	{
		ft_printf("\033[1;31mUsage = ./client <PID> \"Message\"\033[0m\n");
		exit(1);
	}
	server = ft_atoi(av[1]);
	if (server <= 0 || kill(server, 0) < 0)
	{
		ft_printf("\033[31mInvalid PID\033[0m\n");
		exit (EXIT_FAILURE);
	}
	content = av[2];
	mt_signal(SIGUSR1, ack_handler, false);
	mt_signal(SIGUSR2, end_handler, false);
	while (*content)
		char_send(*content++, server);
	char_send('\0', server);
	while (g_server == SERVER_BUSY)
		pause ();
}

void	char_send(char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x80 >> bit))
			mt_kill(server, SIGUSR1);
		else
			mt_kill(server, SIGUSR2);
		++bit;
		usleep(100);
		g_server = SERVER_BUSY;
	}
}

void	ack_handler(void)
{
	g_server = SERVER_READY;
}

void	end_handler(void)
{
	ft_printf("\033[32m✔ Message sent and received by the server!\033[0m\n");
	exit(0);
}
