/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:37:43 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:50 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_hash(t_data *data)
{
	if (data->format.hashtag == 1)
	{
		write_print(data, '0');
		if (data->format.specifier == 'X')
			write_print(data, 'X');
		else
			write_print(data, 'x');
	}
}

static void	print_hex_prec_left(t_data *data, unsigned int nbr, int precision)
{
	if (precision > 0)
		print_prec_zero_d(data, precision);
	if (data->format.hashtag && nbr > 0)
		print_hash(data);
	if (!(data->format.precision_value == 0 && nbr == 0))
		print_hex(data, nbr);
	zero_space(data, data->format.width_value);
}

static void	print_hex_prec(t_data *data, unsigned int nbr, int precision)
{
	zero_space(data, data->format.width_value);
	if (data->format.hashtag && nbr > 0)
		print_hash(data);
	if (precision > 0)
		print_prec_zero_d(data, precision);
	if (!(data->format.precision_value == 0 && nbr == 0))
		print_hex(data, nbr);
}

static void	struct_hex_prec(t_data *data, unsigned int nbr)
{
	int	precision;

	precision = data->format.precision_value;
	if (data->format.zero == 1)
		data->format.zero = 0;
	if (data->format.hashtag)
		data->format.width_value -= 2;
	if (precision > hex_length(nbr))
		data->format.width_value -= precision;
	else if (!(data->format.precision_value == 0 && nbr == 0))
		data->format.width_value -= hex_length(nbr);
	precision -= hex_length(nbr);
	if (data->format.left_justified)
		print_hex_prec_left(data, nbr, precision);
	else
		print_hex_prec(data, nbr, precision);
}

void	ft_printf_hex(t_data *data, unsigned int nbr)
{
	int	count_hex;

	count_hex = hex_length(nbr);
	if (data->format.precision_value >= 0)
		struct_hex_prec(data, nbr);
	else
	{
		data->format.width_value -= count_hex;
		if (data->format.hashtag)
			data->format.width_value -= 2;
		if (data->format.left_justified)
		{
			if (data->format.hashtag && nbr > 0)
				print_hash(data);
			print_hex(data, nbr);
			zero_space(data, data->format.width_value);
		}
		else
		{
			if (data->format.hashtag && nbr > 0)
				print_hash(data);
			zero_space(data, data->format.width_value);
			print_hex(data, nbr);
		}
	}
}
