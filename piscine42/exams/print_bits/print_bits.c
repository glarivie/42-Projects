/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 17:32:00 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 17:46:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		result[8];
	int		i;
	int		swap;

	swap = octet;
	i = 7;

	while (i >= 0)
	{
		result[i] = swap % 2 + '0';
		swap = swap / 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		write(1, &result[i], 1);
		i++;
	}
}
