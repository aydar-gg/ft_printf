/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_function_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:42:32 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/12 19:15:54 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		count_num(unsigned int num_copy, int *counter)
{
	int num_i;

	num_i = 0;
	if (counter[5] && !counter[6] && num_copy == 0)
		return (0);
	if (num_copy == 0)
		num_i++;
	if (num_copy != 0 && (counter[2] || counter[5]))
	{
		while (num_copy != 0)
		{
			num_i++;
			num_copy /= 10;
		}
	}
	return (num_i);
}

static void		u_putnbr_fd(unsigned int num, int fd, int *counter)
{
	if (num > 9)
		u_putnbr_fd(num / 10, fd, counter);
	ft_putchar_fd((num % 10) + '0', fd, counter);
}

static void		put_dif_num(int *counter, int num_int)
{
	if (counter[7])
	{
		while (counter[2] > count_num(num_int, counter))
		{
			ft_putchar_fd(' ', 1, counter);
			counter[2]--;
		}
	}
}

static void		zero_32_num(unsigned int num, int *counter)
{
	if (((counter[7] || !counter[2]) && counter[5]) ||
counter[2] <= count_num(num, counter) || counter[6] >= counter[2])
	{
		while (counter[6] > count_num(num, counter))
		{
			ft_putchar_fd('0', 1, counter);
			counter[6]--;
			if (counter[2])
				counter[2]--;
		}
	}
	while (counter[2] > count_num(num, counter) && !counter[7])
	{
		if ((counter[4] && !counter[5]) || counter[6] >= counter[2])
			ft_putchar_fd('0', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
}

void			u_function_part2(int *counter, int num_int)
{
	unsigned int num;

	num = num_int + 4294967295 + 1;
	zero_32_num(num, counter);
	if (counter[5] && !counter[6] && num == 0)
	{
		put_dif_num(counter, num);
		return ;
	}
	u_putnbr_fd(num, 1, counter);
	put_dif_num(counter, num);
}
