/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:32:19 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:53 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	struct_int_zero(t_data *data, int nbr)
{
	if (nbr < 0 || data->format.plus || data->format.space)
	{
		sign_space(data, nbr);
		data->format.width_value--;
	}
	if (nbr < 0)
		nbr *= -1;
	data->format.width_value -= numlen(nbr);
	zero_space(data, data->format.width_value);
	print_nbr(data, nbr);
}

void	print_prec(t_data *data, int nbr, int precision)
{
	zero_space(data, data->format.width_value);
	sign_space(data, nbr);
	if (precision > 0)
		print_prec_zero_d(data, precision);
	if (!(data->format.precision_value == 0 && nbr == 0))
		print_nbr(data, nbr);
}

void	print_prec_left(t_data *data, int nbr, int precision)
{
	sign_space(data, nbr);
	if (precision > 0)
		print_prec_zero_d(data, precision);
	if (!(data->format.precision_value == 0 && nbr == 0))
		print_nbr(data, nbr);
	zero_space(data, data->format.width_value);
}

void	struct_int_prec(t_data *data, int nbr)
{
	int	precision;

	precision = data->format.precision_value;
	if (data->format.zero == 1)
		data->format.zero = 0;
	if (nbr < 0 || data->format.plus || data->format.space)
		data->format.width_value--;
	if (precision > numlen(nbr))
		data->format.width_value -= precision;
	else if (!(data->format.precision_value == 0 && nbr == 0))
		data->format.width_value -= numlen(nbr);
	precision -= numlen(nbr);
	if (data->format.left_justified)
		print_prec_left(data, nbr, precision);
	else
		print_prec(data, nbr, precision);
}

void	ft_printf_int(t_data *data, int nbr)
{
	if (data->format.zero == 1 && data->format.precision_value == -1)
		struct_int_zero(data, nbr);
	else if (data->format.precision_value >= 0)
		struct_int_prec(data, nbr);
	else
	{
		if (nbr < 0 || data->format.plus || data->format.space)
			data->format.width_value--;
		data->format.width_value -= numlen(nbr);
		if (data->format.left_justified)
		{
			sign_space(data, nbr);
			print_nbr(data, nbr);
			zero_space(data, data->format.width_value);
		}
		else
		{
			zero_space(data, data->format.width_value);
			sign_space(data, nbr);
			print_nbr(data, nbr);
		}
	}
}
