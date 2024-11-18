/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_unint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:39:33 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:57:16 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_unint_prec(t_data *data, unsigned int nbr, int precision)
{
	zero_space(data, data->format.width_value);
	sign_space(data, nbr);
	if (precision > 0)
		print_prec_zero_d(data, precision);
	if (!(data->format.precision_value == 0 && nbr == 0))
		print_nbr(data, nbr);
}

void	print_unint_prec_left(t_data *data, unsigned int nbr, int precision)
{
	sign_space(data, nbr);
	if (precision > 0)
		print_prec_zero_d(data, precision);
	if (!(data->format.precision_value == 0 && nbr == 0))
		print_nbr(data, nbr);
	zero_space(data, data->format.width_value);
}

void	struct_unint_prec(t_data *data, unsigned int nbr)
{
	int	precision;

	precision = data->format.precision_value;
	if (data->format.zero == 1)
		data->format.zero = 0;
	if (precision > numlen(nbr))
		data->format.width_value -= precision;
	else if (!(data->format.precision_value == 0 && nbr == 0))
		data->format.width_value -= numlen(nbr);
	precision -= numlen(nbr);
	if (data->format.left_justified)
		print_unint_prec_left(data, nbr, precision);
	else
		print_unint_prec(data, nbr, precision);
}

void	print_unint_strct(t_data *data, unsigned int nbr, int width)
{
	if (data->format.left_justified)
	{
		print_prec_zero(data);
		print_nbr(data, nbr);
		if (width > 0)
			zero_space(data, width);
	}
	else
	{
		if (width > 0)
			zero_space(data, width);
		print_prec_zero(data);
		print_nbr(data, nbr);
	}
}

void	ft_printf_unint(t_data *data, unsigned int nbr)
{
	if (data->format.zero == 1 && data->format.precision_value == -1)
		struct_unint_zero(data, nbr);
	else if (data->format.precision_value >= 0)
		struct_unint_prec(data, nbr);
	else
	{
		data->format.width_value -= numlen(nbr);
		if (data->format.left_justified)
		{
			print_nbr(data, nbr);
			zero_space(data, data->format.width_value);
		}
		else
		{
			zero_space(data, data->format.width_value);
			print_nbr(data, nbr);
		}
	}
}
