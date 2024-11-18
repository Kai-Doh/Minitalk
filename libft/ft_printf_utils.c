/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:08:47 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:55:57 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(const char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	write_print(t_data *data, int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	data->chars_written++;
	return (1);
}

int	string_print(t_data *data, const char *str, int precision)
{
	if (precision > (int)ft_strlen(str) && data->format.width_value == 0)
	{
		while (*str)
		{
			write_print(data, *str);
			str++;
		}
	}
	else if (precision < (int)ft_strlen(str) && precision != -1)
	{
		while (precision-- > 0)
		{
			write_print(data, *str++);
		}
	}
	else
	{
		while (*str)
			write_print(data, *str++);
	}
	return (1);
}

void	fill_space(t_data *data, const char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (write_print(data, c) == -1)
			return ;
		i++;
	}
}
