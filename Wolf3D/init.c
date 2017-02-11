/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:27:40 by glarivie          #+#    #+#             */
/*   Updated: 2016/11/13 18:25:35 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			close_window(void *param)
{
	t_block *block;

	block = (t_block*)param;
	free_block(block);
	return (1);
}

void		init_mlx(t_block *block)
{
	block->drawend = 0;
	block->drawstart = 0;
	block->side = 0;
	block->mlx = mlx_init();
	block->width = 1024;
	block->height = 768;
	block->window =
		mlx_new_window(block->mlx, block->width, block->height, "WOLF3D");
	block->img = mlx_new_image(block->mlx, block->width, block->height);
	block->posx = 13;
	block->posy = 10;
	block->dirx = -1;
	block->diry = 0;
	block->planex = 0;
	block->planey = 0.66;
	block->done = 0;
	block->x = 0;
}

void		init_sky_floor(t_block *block)
{
	block->color2.r = 202;
	block->color2.g = 197;
	block->color2.b = 209;
	block->color3.r = 69;
	block->color3.g = 79;
	block->color3.b = 55;
}
