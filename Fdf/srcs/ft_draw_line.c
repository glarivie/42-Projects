/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:12:14 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/14 17:12:16 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_set_coord(int *x, int *start, int nb1, int nb2)
{
	if (nb1 < nb2)
	{
		*x = nb1;
		*start = nb2;
	}
	else
	{
		*x = nb2;
		*start = nb1;
	}
}

void		ft_draw_line_y(t_coord *e, int i, int j)
{
	float	m;
	float	p;
	int		start;
	int		y;
	int		x;

	y = e->val[i + 1][j][1] - e->val[i][j][1];
	x = e->val[i + 1][j][0] - e->val[i][j][0];
	m = (float)y / (float)x;
	p = e->val[i][j][1] - (m * e->val[i][j][0]);
	ft_set_coord(&x, &start, e->val[i][j][0], e->val[i + 1][j][0]);
	while (x < start)
	{
		y = (int)((m * x + p) + 0.5);
		ft_put_p(e, x, y, BASE_COLOR);
		x++;
	}
	ft_set_coord(&y, &start, e->val[i][j][1], e->val[i + 1][j][1]);
	while (y < start)
	{
		x = (int)((y - p) / m + 0.5);
		ft_put_p(e, x, y, BASE_COLOR);
		y++;
	}
}

void		ft_draw_line_x(t_coord *e, int i, int j)
{
	float	m;
	float	p;
	int		start;
	int		y;
	int		x;

	y = e->val[i][j + 1][1] - e->val[i][j][1];
	x = e->val[i][j + 1][0] - e->val[i][j][0];
	m = (float)y / (float)x;
	p = e->val[i][j][1] - (m * e->val[i][j][0]);
	ft_set_coord(&x, &start, e->val[i][j][0], e->val[i][j + 1][0]);
	while (x < start)
	{
		y = (int)((m * x + p) + 0.5);
		ft_put_p(e, x, y, BASE_COLOR);
		x++;
	}
	ft_set_coord(&y, &start, e->val[i][j][1], e->val[i][j + 1][1]);
	while (y < start)
	{
		x = (int)((y - p) / m + 0.5);
		ft_put_p(e, x, y, BASE_COLOR);
		y++;
	}
}

void		ft_init_line_x(t_coord *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->length)
	{
		j = 0;
		while (j < e->width - 1)
		{
			ft_draw_line_x(e, i, j);
			j++;
		}
		i++;
	}
}

void		ft_init_line_y(t_coord *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->length - 1)
	{
		j = 0;
		while (j < e->width)
		{
			ft_draw_line_y(e, i, j);
			j++;
		}
		i++;
	}
}
