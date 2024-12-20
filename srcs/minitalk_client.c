/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:58:54 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/19 19:09:54 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	received_messaged(int sig)
{
	if (sig)
		ft_printf("\033[32m✔ Message sent and received!\033[0m\n");
}

void	str_to_bin(char *str, int pid)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;

	signal(SIGUSR1, received_messaged);
	if (argc != 3)
	{
		ft_printf("\033[1;31mUsage = ./client <PID> \"Message\"\033[0m\n");
		return (0);
	}
	server_pid = atoi(argv[1]);
	str_to_bin(argv[2], server_pid);
	return (0);
}
