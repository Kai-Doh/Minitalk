/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:48:37 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:04 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	struct_unint_zero(t_data *data, unsigned int nbr)
{
	data->format.width_value -= numlen(nbr);
	zero_space(data, data->format.width_value);
	print_nbr(data, nbr);
}

void	print_nbr(t_data *data, long long nbr)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 10)
	{
		print_nbr(data, nbr / 10);
		print_nbr(data, nbr % 10);
	}
	else
		write_print(data, nbr + '0');
}

int	numlen(long long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	zero_space_sign(t_data *data, int size, int nbr)
{
	if (nbr < 0 && data->format.zero)
	{
		write_print(data, '-');
		fill_space(data, '0', size);
	}
	else
	{
		if (data->format.zero)
			fill_space(data, '0', size);
		else
			fill_space(data, ' ', size);
	}
	return ;
}

void	print_hex(t_data *data, unsigned long long nbr)
{
	if (nbr >= 16)
	{
		print_hex(data, nbr / 16);
		print_hex(data, nbr % 16);
	}
	else
	{
		if (nbr < 10)
			write_print(data, nbr + '0');
		else
		{
			if (data->format.specifier == 'X')
				write_print(data, nbr - 10 + 'A');
			else
				write_print(data, nbr - 10 + 'a');
		}
	}
}
