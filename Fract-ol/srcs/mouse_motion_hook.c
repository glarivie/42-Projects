/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:44:04 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 11:45:27 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	choice_one(t_mlx *mlx)
{
	t_julia		ju;

	set_julia(&ju, mlx);
	julia(mlx, &ju);
}

int				mouse_motion_hook(int x, int y, t_mlx *mlx)
{
	t_mand		mand;
	t_julia		ju;

	if (mlx->motion == 1)
	{
		mlx->add = mlx_get_data_addr(mlx->new_img, &mlx->bpp,
				&mlx->s_l, &mlx->edn);
		mlx->x = x;
		mlx->y = y;
		if (mlx->choice == 1)
			choice_one(mlx);
		if (mlx->choice == 2)
		{
			set_mandelbrot(&mand);
			mandelbrot(mlx, &mand);
		}
		if (mlx->choice == 3)
		{
			set_julia(&ju, mlx);
			manu(mlx, &ju);
		}
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->new_img, 0, 0);
	}
	return (0);
}
