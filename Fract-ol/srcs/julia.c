/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:43:18 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 11:34:34 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	do_stuff(int x, int y, t_mlx *mlx, t_julia *ju)
{
	int	i;

	i = -1;
	ju->newre = 1.5 * (x - mlx->width / 2) / (0.5 * mlx->zoom * mlx->width)
		+ mlx->offset_x;
	ju->newim = (y - mlx->height / 2) / (0.5 * mlx->zoom * mlx->height)
		+ mlx->offset_y;
	while (++i < mlx->maxiter && (ju->newre * ju->newre + ju->newim *
		ju->newim) < 4)
	{
		ju->oldre = ju->newre;
		ju->oldim = ju->newim;
		ju->newre = ju->oldre * ju->oldre - ju->oldim * ju->oldim + ju->cre;
		ju->newim = 2 * ju->oldre * ju->oldim + ju->cim;
	}
	return (i);
}

int			julia(t_mlx *mlx, t_julia *ju)
{
	t_coord	c;
	int		i;

	c.y = -1;
	while (++(c.y) < mlx->height)
	{
		c.x = -1;
		while (++(c.x) < mlx->width)
		{
			i = do_stuff(c.x, c.y, mlx, ju);
			if (i < mlx->maxiter)
				ju->color = hsv_to_rgb(i % 250, 255, 255 * (i < mlx->maxiter));
			else
				ju->color = 0x000000;
			img_pixel_put(c.x, c.y, ju->color, mlx);
		}
	}
	return (0);
}
