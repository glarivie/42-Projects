/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 12:09:13 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 09:13:41 by glarivie         ###   ########.fr       */
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
