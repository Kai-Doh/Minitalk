/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:18:46 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:13 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_prec_zero(t_data *data)
{
	int	precision;

	precision = data->format.precision_value;
	while (precision > 0)
	{
		write_print(data, '0');
		precision--;
	}
}

static void	render_conversion(t_data *data)
{
	char	type;

	type = data->format.specifier;
	if ('%' == type)
		ft_printf_char(data, '%');
	else if ('c' == type)
		ft_printf_char(data, va_arg(data->ap, int));
	else if ('s' == type)
		print_str(data, va_arg(data->ap, char *));
	else if ('d' == type || 'i' == type)
		ft_printf_int(data, va_arg(data->ap, int));
	else if ('u' == type)
		ft_printf_unint(data, va_arg(data->ap, unsigned int));
	else if ('x' == type || 'X' == type)
		ft_printf_hex(data, va_arg(data->ap, unsigned int));
	else if ('p' == type)
		ft_printf_add(data, (void *)va_arg(data->ap, void *));
}

static int	init_data(t_data *data)
{
	data->chars_written = 0;
	return (OK);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	if (init_data(&data))
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			if (format_parsing(&data, &format))
				return (PARSE_ERROR);
			render_conversion(&data);
		}
		else
			if (write_print(&data, *format) == -1)
				return (-1);
		++format;
	}
	va_end(data.ap);
	return (data.chars_written);
}
