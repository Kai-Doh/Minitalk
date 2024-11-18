/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:56:18 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:41 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pf_atoi(const char **format)
{
	int	value;

	value = 0;
	while (check(NUMBERS, **format))
		value = (value * 10) + (*(*format)++ - '0');
	return (value);
}

static void	parse_flags(t_data *data, const char **format)
{
	char	flag;

	while (check(FLAGS, **format))
	{
		flag = **format;
		if ('0' == flag)
			data->format.zero = 1;
		else if ('+' == flag)
			data->format.plus = 1;
		else if (' ' == flag)
			data->format.space = 1;
		else if ('#' == flag)
			data->format.hashtag = 1;
		else if ('-' == flag)
			data->format.left_justified = 1;
		(*format)++;
	}
}

static void	get_value(int *value, const char **format)
{
	*value = pf_atoi(format);
}

int	format_parsing(t_data *data, const char **format)
{
	ft_memset(&data->format, 0, sizeof(t_format));
	data->format.precision_value = -1;
	parse_flags(data, format);
	get_value(&data->format.width_value, format);
	if (**format == '.' && ++(*format))
		get_value(&data->format.precision_value, format);
	if (!check(TYPE, **format))
		return (PARSE_ERROR);
	else
		data->format.specifier = **format;
	return (OK);
}
