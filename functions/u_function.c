/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 00:17:12 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/12 19:14:47 by psabreto         ###   ########.fr       */
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

static void		zero_32_num_int(int num_int, int *counter)
{
	if (((counter[7] || !counter[2]) && counter[5]) ||
counter[2] <= count_num(num_int, counter) || counter[6] >= counter[2])
	{
		while (counter[6] > count_num(num_int, counter))
		{
			ft_putchar_fd('0', 1, counter);
			counter[6]--;
			if (counter[2])
				counter[2]--;
		}
	}
	while (counter[2] > count_num(num_int, counter) && !counter[7])
	{
		if ((counter[4] && !counter[5]) || counter[6] >= counter[2])
			ft_putchar_fd('0', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
}

void			u_function(int num_int, int *counter)
{
	if (num_int >= 0)
	{
		zero_32_num_int(num_int, counter);
		if (counter[5] && !counter[6] && num_int == 0)
		{
			put_dif(counter, num_int);
			return ;
		}
		ft_putnbr_fd(num_int, 1, counter);
		put_dif(counter, num_int);
	}
	else
		u_function_part2(counter, num_int);
}
