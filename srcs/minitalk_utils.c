/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:18:19 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 15:08:48 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_kill(pid_t server, int sig_nb)
{
	if (kill(server, sig_nb) < 0)
	{
		ft_printf("\033[31mKill failed\033[0m\n");
		exit(EXIT_FAILURE);
	}
}

void	mt_signal(int sig_nb, void *handler, bool other_info)
{
	struct sigaction	sa;

	ft_memset (&sa, 0, sizeof(sa));
	if (other_info)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(sig_nb, &sa, NULL) < 0)
	{
		ft_printf("\033[31mSigaction failed\033[0m\n");
		exit(1);
	}
}
