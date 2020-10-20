/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_0_or_32_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:57:33 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/13 12:45:18 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	count_p(size_t num_long)
{
	int i;

	i = 2;
	if (num_long == 0)
		i++;
	while (num_long != 0)
	{
		num_long /= 16;
		i++;
	}
	return (i);
}

void		put_0_or_32_p(size_t num_long, int *counter)
{
	if (((counter[7] || !counter[2]) && counter[5]) ||
counter[2] <= count_p(num_long))
	{
		while (counter[6] > count_p(num_long))
		{
			ft_putchar_fd(' ', 1, counter);
			counter[6]--;
			if (counter[2])
				counter[2]--;
		}
	}
	while (counter[2] > count_p(num_long) && !counter[7])
	{
		if ((counter[4] && !counter[5]) || counter[6] >= counter[2])
			ft_putchar_fd(' ', 1, counter);
		else
			ft_putchar_fd(' ', 1, counter);
		counter[2]--;
	}
}
