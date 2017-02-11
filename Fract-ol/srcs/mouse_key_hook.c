/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:44:00 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 11:45:23 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		zoom_julia_or_manu(int x, int y, t_mlx *mlx)
{
	t_julia		ju;
	t_mand		mand;

	mlx->offset_x = mlx->offset_x + ((x - mlx->width / 2) / (0.5 * mlx->zoom *
		mlx->width));
	mlx->offset_y = mlx->offset_y + ((y - mlx->height / 2) / (0.5 * mlx->zoom *
		mlx->height));
	mlx->add = mlx_get_data_addr(mlx->new_img, &mlx->bpp, &mlx->s_l, &mlx->edn);
	if (mlx->choice == 1)
	{
		set_julia(&ju, mlx);
		julia(mlx, &ju);
	}
	else if (mlx->choice == 2)
	{
		set_mandelbrot(&mand);
		mandelbrot(mlx, &mand);
	}
	else
	{
		set_julia(&ju, mlx);
		manu(mlx, &ju);
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->new_img, 0, 0);
}

void			zoom_set(int x, int y, t_mlx *mlx)
{
	mlx->zoom *= ZOOM;
	zoom_julia_or_manu(x, y, mlx);
}

void			zoom_out(int x, int y, t_mlx *mlx)
{
	mlx->zoom /= ZOOM;
	zoom_julia_or_manu(x, y, mlx);
}

int				mouse_key_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
		zoom_set(x, y, mlx);
	if (button == 5)
		zoom_out(x, y, mlx);
	return (0);
}
