/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:45:40 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 14:56:58 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdbool.h>

enum e_server_state
{
	SERVER_READY,
	SERVER_BUSY,
};

void	mt_kill(pid_t server, int sig_nb);
void	mt_signal(int sig_nb, void *handler, bool other_info);

#endif
