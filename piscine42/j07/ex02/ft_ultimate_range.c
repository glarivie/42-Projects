/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 13:45:28 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 09:16:53 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*int_tab;
	int		i;

	i = 0;
	if (min >= max)
		return (NULL);
	else
	{
		int_tab = (int *)malloc(sizeof(int) * (max - min));
		while (i < max)
		{
			int_tab[i] = min + i;
			i++;
		}
		return (int_tab);
	}
}

int		ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (min >= max)
		return (NULL);
	else
		return (max - min);
}
