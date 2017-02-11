/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:12:58 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/19 09:00:40 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_c(int *x, int *y, int *index, int **val)
{
	float	tmp;

	tmp = 15. + (35. + index[2]) * (0.82 * index[0] + 0.57 * index[1]);
	*x = (int)(tmp + 0.5);
	tmp = 0.57 * (0.57 * index[0] - 0.82 * index[1]);
	tmp -= 0.06 * val[index[0]][index[1]];
	tmp *= (35. + index[2]);
	tmp += 533.;
	*y = (int)(tmp + 0.5);
}

void		ft_verif_value(int **val, int length, int width)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (i != length)
	{
		j = 0;
		while (j != width)
		{
			if (val[i][j] > 1000 || val[i][j] < -1000)
			{
				ft_putstr("Incorect value in file.\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int			***ft_init_coord(int **val, int length, int width, t_coord *e)
{
	int		***coord;
	int		index[3];

	index[2] = e->zoom;
	if (!(coord = (int***)malloc(sizeof(coord) * (length + 1))))
		return (NULL);
	index[0] = 0;
	ft_verif_value(val, length, width);
	while (index[0] < length)
	{
		if (!(coord[index[0]] = (int**)malloc(sizeof(coord) * (width + 1))))
			return (NULL);
		index[1] = 0;
		while (index[1] != width)
		{
			if (!(coord[index[0]][index[1]] = malloc(sizeof(coord) * 2)))
				return (NULL);
			ft_init_c(&coord[index[0]][index[1]][0],
				&coord[index[0]][index[1]][1], index, val);
			index[1]++;
		}
		index[0]++;
	}
	return (coord);
}
