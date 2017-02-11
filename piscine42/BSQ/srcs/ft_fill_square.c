/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:26:27 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:19:43 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

char	**ft_fill_square(char **tab, t_bsq_data data, t_coord coord)
{
	int		x;
	int		y;

	y = 0;
	while (y < coord.ref)
	{
		x = 0;
		while (x < coord.ref)
		{
			if (coord.x_max + x != data.columns)
			{
				tab[coord.y_max + y][coord.x_max + x] = data.sqr_px;
				x++;
			}
			else
				x = coord.ref;
		}
		y++;
	}
	return (tab);
}
