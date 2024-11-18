/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:27:07 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:55 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_null(t_data *data)
{
	char	*str;

	str = "(null)";
	while (*str)
	{
		write_print(data, *str);
		str++;
	}
	return ;
}

void	struct_str2(t_data *data, const char *str, int width, int precision)
{
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			string_print(data, str, precision);
			zero_space(data, width);
		}
		else
		{
			zero_space(data, width);
			string_print(data, str, precision);
		}
	}
	else
		string_print(data, str, precision);
}

void	struct_str(t_data *data, const char *str)
{
	int	precision;

	precision = data->format.precision_value;
	if (precision != -1 && precision < (int)ft_strlen(str))
		data->format.width_value -= precision;
	else if (precision == -1 || precision > (int)ft_strlen(str))
		data->format.width_value -= ft_strlen(str);
	struct_str2(data, str, data->format.width_value, precision);
}

void	print_str(t_data *data, const char *str)
{
	if (!str)
		struct_str_null(data);
	else if (str[0] == '\0')
		struct_str_empty(data);
	else
		struct_str(data, str);
}
