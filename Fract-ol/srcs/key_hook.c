/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:43:24 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 11:47:50 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	choice(t_mlx *mlx)
{
	t_julia	ju;
	t_mand	mand;

	mlx->add = mlx_get_data_addr(mlx->new_img, &mlx->bpp, &mlx->s_l, &mlx->edn);
	if (mlx->choice == 2)
	{
		set_mandelbrot(&mand);
		mandelbrot(mlx, &mand);
	}
	else if (mlx->choice == 1)
	{
		set_julia(&ju, mlx);
		julia(mlx, &ju);
	}
	else
	{
		set_manu(&ju, mlx);
		manu(mlx, &ju);
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->new_img, 0, 0);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 18)
		mlx->motion = 1;
	if (keycode == 19)
		mlx->motion = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 20)
	{
		mlx->maxiter -= 10;
		choice(mlx);
	}
	if (keycode == 21)
	{
		mlx->maxiter += 10;
		choice(mlx);
	}
	if (keycode == 69)
		zoom_set(ZOOM, ZOOM, mlx);
	if (keycode == 78)
		zoom_out(ZOOM, ZOOM, mlx);
	return (0);
}
