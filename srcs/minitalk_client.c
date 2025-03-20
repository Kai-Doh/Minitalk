/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:58:54 by ktiomico          #+#    #+#             */
/*   Updated: 2025/03/21 00:38:19 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack;

void	received_message(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
		ft_printf("\033[32m✔ Message sent and received!\033[0m\n");
}

void	char_to_bin(char c, int pid)
{
	int	bit_pos;

	bit_pos = 0;
	while (bit_pos < 8)
	{
		if ((c & (0b10000000 >> bit_pos)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_pos++;
		while (g_ack == 0)
			usleep(50);
		g_ack = 0;
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*str;

	if (argc != 3)
	{
		ft_printf("\033[1;31mUsage = ./client <PID> \"Message\"\033[0m\n");
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	signal(SIGUSR1, received_message);
	signal(SIGUSR2, received_message);
	while (*str)
		char_to_bin(*str++, server_pid);
	return (0);
}
