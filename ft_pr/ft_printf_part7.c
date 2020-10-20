/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_part7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:24:03 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/12 13:52:20 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_printf_part8(const char *format, va_list ap,
int *counter)
{
	unsigned int num;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'X')
	{
		num = va_arg(ap, unsigned int);
		put_0_or_32_xx(num, counter);
		if (counter[5] && !counter[6] && num == 0)
		{
			put_dif(counter, num);
			counter[0]++;
			return (1);
		}
		x_big(num, counter);
		put_dif_xx(counter, num);
		counter[0]++;
		return (1);
	}
	return (0);
}

int				ft_printf_part7(const char *format, va_list ap,
int *counter)
{
	int num_int;
	int num_int_copy;

	if (format[counter[1]] == '%' && (format[counter[0] + 1] == 'd'
	|| format[counter[0] + 1] == 'i'))
	{
		num_int = va_arg(ap, int);
		num_int_copy = num_int;
		num_int = put_0_or_32(counter, num_int_copy);
		if (counter[5] && !counter[6] && num_int == 0)
		{
			put_dif(counter, num_int_copy);
			counter[0]++;
			return (1);
		}
		ft_putnbr_fd(num_int, 1, counter);
		put_dif(counter, num_int_copy);
		counter[0]++;
		return (1);
	}
	return (ft_printf_part8(format, ap, counter));
}
