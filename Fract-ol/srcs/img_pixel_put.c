/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:43:07 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 08:43:09 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		img_pixel_put(int x, int y, int color, t_mlx *mlx)
{
	unsigned char	r;
	unsigned char	b;
	unsigned char	g;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
	{
		mlx->add[(y * mlx->s_l) + ((mlx->bpp / 8) * x)] = b;
		mlx->add[(y * mlx->s_l) + ((mlx->bpp / 8) * x) + 1] = g;
		mlx->add[(y * mlx->s_l) + ((mlx->bpp / 8) * x) + 2] = r;
	}
}
