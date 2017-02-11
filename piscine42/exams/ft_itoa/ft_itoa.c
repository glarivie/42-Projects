/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 15:38:40 by exam              #+#    #+#             */
/*   Updated: 2015/08/29 16:10:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*ret;
	int		mod;
	int		count;
	int		test;

	count = 0;
	test = 0;
	mod = 1000000000;
	while (mod > 0)
	{
		if (nbr / mod != 0)
			count++;
		mod = mod / 10;
	}
	ret = (char *)malloc(sizeof(char) * count + 1);
	mod = 1000000000;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ret[0] = '-';
		count++;
	}

	while ((nbr / mod) == 0)
		mod = mod / 10;

	while (mod > 0)
	{
		
		if (nbr >= 0)
			ret[count] = (nbr / mod) + '0';
		nbr = (nbr - (nbr / mod) * mod);
		mod = mod / 10;
		count++;
	}
	ret[count] = '\0';

	return (ret);
}
