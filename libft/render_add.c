/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:38:21 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:44 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_length(unsigned long long n)
{
	int	length;

	length = 1;
	if (n == 0)
		return (1);
	while (n >= 16)
	{
		n /= 16;
		length++;
	}
	return (length);
}

static void	print_nil(t_data *data, int width)
{
	char	*str;

	str = "0x0";
	if (data->format.left_justified)
	{
		while (*str)
			write_print(data, *str++);
		fill_space(data, ' ', width - 3);
	}
	else
	{
		fill_space(data, ' ', width - 3);
		while (*str)
			write_print(data, *str++);
	}
}

static void	format_add(t_data *data, unsigned long long addr_value, int width)
{
	if (addr_value == 0)
		print_nil(data, width);
	else if (width > 0 && addr_value)
	{
		if (data->format.left_justified)
		{
			write_print(data, '0');
			write_print(data, 'x');
			print_hex(data, addr_value);
			fill_space(data, ' ', width);
		}
		else
		{
			fill_space(data, ' ', width);
			write_print(data, '0');
			write_print(data, 'x');
			print_hex(data, addr_value);
		}
	}
	else
	{
		write_print(data, '0');
		write_print(data, 'x');
		print_hex(data, addr_value);
	}
}

void	ft_printf_add(t_data *data, void *address)
{
	int					width;
	int					count_hex;
	unsigned long long	addr_value;

	addr_value = (unsigned long long)address;
	count_hex = hex_length(addr_value);
	if (!address)
		width = data->format.width_value;
	else
		width = data->format.width_value - (count_hex + 2);
	format_add(data, addr_value, width);
}
