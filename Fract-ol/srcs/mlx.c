/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:43:53 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 09:05:08 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_setup(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->maxiter = 30;
	mlx->width = WIDTH;
	mlx->height = HEIGHT;
	mlx->zoom = ZOOM;
	mlx->motion = MOTION;
	mlx->x = 0;
	mlx->y = 0;
	mlx->offset_x = 0;
	mlx->offset_y = 0;
	mlx->win = mlx_new_window(mlx->init, mlx->width, mlx->height, NAME);
	mlx->new_img = mlx_new_image(mlx->init, mlx->width, mlx->height);
}

void	ft_mlx(t_mlx mlx)
{
	mlx_setup(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_key_hook, &mlx);
	mlx_hook(mlx.win, 6, 64, mouse_motion_hook, &mlx);
	mlx_loop(mlx.init);
}
