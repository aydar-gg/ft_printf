/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:50:27 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/12 13:51:42 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_printf_part6(const char *format, va_list ap,
int *counter)
{
	unsigned int num;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'x')
	{
		num = va_arg(ap, unsigned int);
		put_0_or_32_xx(num, counter);
		if (counter[5] && !counter[6] && num == 0)
		{
			put_dif(counter, num);
			counter[0]++;
			return (1);
		}
		x_littel(num, counter);
		put_dif_xx(counter, num);
		counter[0]++;
		return (1);
	}
	return (ft_printf_part7(format, ap, counter));
}

static int		ft_printf_part5(const char *format, va_list ap,
int *counter)
{
	size_t num_long;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'p')
	{
		num_long = va_arg(ap, size_t);
		put_0_or_32_p(num_long, counter);
		ft_putstr_fd("0x", 1, counter);
		if (num_long == 0)
			ft_putchar_fd('0', 1, counter);
		p_function(num_long, counter);
		put_dif_p(num_long, counter);
		counter[0]++;
		return (1);
	}
	return (ft_printf_part6(format, ap, counter));
}

static int		ft_printf_part4(const char *format, va_list ap,
int *counter)
{
	unsigned char c;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		put_0_or_32_c_pr(counter);
		ft_putchar_fd(c, 1, counter);
		put_dif_c_pr(counter);
		counter[0]++;
		return (1);
	}
	return (ft_printf_part5(format, ap, counter));
}

static int		ft_printf_part3(const char *format, va_list ap,
int *counter)
{
	char *str;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 's')
	{
		str = va_arg(ap, char*);
		put_0_or_32_s(str, counter);
		return (1);
	}
	return (ft_printf_part4(format, ap, counter));
}

void			ft_printf_part2(const char *format, va_list ap,
int *counter)
{
	int num_int;

	if (format[counter[1]] == '%' && format[counter[0] + 1] == 'u')
	{
		num_int = va_arg(ap, int);
		u_function(num_int, counter);
		counter[0]++;
	}
	else if (format[counter[1]] == '%' && format[counter[0] + 1] == '%')
	{
		put_0_or_32_c_pr(counter);
		ft_putchar_fd('%', 1, counter);
		put_dif_c_pr(counter);
		counter[0]++;
	}
	else if (ft_isascii((unsigned char)format[counter[0]]) &&
!ft_printf_part3(format, ap, counter))
		ft_putchar_fd(format[counter[0]], 1, counter);
}
