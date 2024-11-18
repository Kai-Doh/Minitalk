/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:55:47 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:58 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	struct_str_null(t_data *data)
{
	if (data->format.precision_value == -1 && data->format.width_value == 0)
		str_null(data);
	else if (data->format.left_justified)
	{
		if (data->format.precision_value > 5
			|| data->format.precision_value == -1)
			str_null(data);
		if (data->format.precision_value > 5
			|| data->format.precision_value == -1)
			zero_space(data, data->format.width_value - 6);
		else
			zero_space(data, data->format.width_value);
	}
	else
	{
		if (data->format.precision_value > 5
			|| data->format.precision_value == -1)
			zero_space(data, data->format.width_value - 6);
		else
			zero_space(data, data->format.width_value);
		if (data->format.precision_value > 5
			|| data->format.precision_value == -1)
			str_null(data);
	}
}

void	struct_str_empty(t_data *data)
{
	if (data->format.width_value > 0)
	{
		if (data->format.left_justified)
		{
			zero_space(data, data->format.width_value);
		}
		else
		{
			zero_space(data, data->format.width_value);
		}
	}
	else
		return ;
}
