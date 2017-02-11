/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:23:46 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:19:23 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

t_coord		ft_check_tab(char **tab, t_bsq_data data)
{
	t_coord		coord;

	coord.y = 0;
	coord.x_max = 0;
	coord.y_max = 0;
	coord.ref = 1;
	while (coord.y < data.lines)
	{
		coord.x = 0;
		while (tab[coord.y][coord.x] != '\0')
		{
			while (ft_check_square(tab, data, coord) == coord.ref)
			{
				coord.x_max = coord.x;
				coord.y_max = coord.y;
				coord.ref++;
			}
			coord.x++;
		}
		coord.y++;
	}
	if (coord.ref > 1)
		coord.ref = coord.ref - 1;
	return (coord);
}
