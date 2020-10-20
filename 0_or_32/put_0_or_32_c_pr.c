/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_0_or_32_c_%.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psabreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:11:50 by psabreto          #+#    #+#             */
/*   Updated: 2020/07/11 11:19:28 by psabreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_0_or_32_c_pr(int *counter)
{
	if (counter[2] && !counter[7])
	{
		while (counter[2] - 1)
		{
			if (counter[4])
				ft_putchar_fd('0', 1, counter);
			else
				ft_putchar_fd(' ', 1, counter);
			counter[2]--;
		}
	}
}
