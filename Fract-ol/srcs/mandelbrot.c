/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:43:42 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 11:31:53 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		do_stuff(int x, int y, t_mlx *mlx, t_mand *mand)
{
	int		i;

	i = -1;
	mand->pr = 1.50 * (x - mlx->width / 2) / (0.5 * mlx->zoom * mlx->width) +
		mlx->offset_x - 0.55;
	mand->pi = (y - mlx->height / 2) / (0.5 * mlx->zoom * mlx->height) +
		mlx->offset_y;
	mand->newre = mlx->x / 1000;
	mand->newim = mlx->y / 1000;
	mand->oldre = 0;
	mand->oldim = 0;
	while (++i < mlx->maxiter && (mand->newre * mand->newre + mand->newim
				* mand->newim) < 4)
	{
		mand->oldre = mand->newre;
		mand->oldim = mand->newim;
		mand->newre = mand->oldre * mand->oldre - mand->oldim * mand->oldim
			+ mand->pr;
		mand->newim = 2 * mand->oldre * mand->oldim + mand->pi;
	}
	return (i);
}

void			mandelbrot(t_mlx *mlx, t_mand *mand)
{
	t_coord		c;
	int			i;

	c.y = -1;
	while (++(c.y) < mlx->height)
	{
		c.x = -1;
		while (++(c.x) < mlx->width)
		{
			i = do_stuff(c.x, c.y, mlx, mand);
			if (i < mlx->maxiter)
				mand->color = hsv_to_rgb(i % 256, 255, 255 *
						(i < mlx->maxiter));
			else
				mand->color = 0x000000;
			img_pixel_put(c.x, c.y, mand->color, mlx);
		}
	}
}
