/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_0_or_32_xx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:26:12 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/12 20:10:33 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	count_xx(unsigned int num_copy, int *counter)
{
	int num_i;

	num_i = 0;
	if (counter[5] && !counter[6] && num_copy == 0)
		return (0);
	if (num_copy <= 0)
		num_i++;
	if (num_copy != 0 && (counter[2] || counter[5]))
	{
		while (num_copy != 0)
		{
			num_i++;
			num_copy /= 16;
		}
	}
	return (num_i);
}

void		put_0_or_32_xx(unsigned int num, int *counter)
{
	if (((counter[7] || !counter[2]) && counter[5]) ||
counter[2] <= count_xx(num, counter) || counter[6] >= counter[2])
	{
		while (counter[6] > count_xx(num, counter))
		{
			ft_putchar_fd('0', 1, counter);
			counter[6]--;
			if (counter[2])
				counter[2]--;
		}
	}
	while (counter[2] > count_xx(num, counter) && !counter[7])
	{
		if ((counter[4] && (!counter[5] || counter[6] < 0)) ||
counter[6] >= counter[2])
			ft_putchar_fd('0', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
	if (num == 0 && !(counter[5] && !counter[6]))
		ft_putchar_fd('0', 1, counter);
}
