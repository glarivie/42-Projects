/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:26:39 by glarivie          #+#    #+#             */
/*   Updated: 2016/11/13 16:43:25 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_new(t_block *block)
{
	block->camerax = 2 * block->x / (double)block->width - 1;
	block->rayposx = block->posx;
	block->rayposy = block->posy;
	block->raydirx = block->dirx + block->planex * block->camerax;
	block->raydiry = block->diry + block->planey * block->camerax;
	block->mapx = (int)block->rayposx;
	block->mapy = (int)block->rayposy;
	block->deltadistx = sqrt(1 + (block->raydiry * block->raydiry) /
			(block->raydirx * block->raydirx));
	block->deltadisty = sqrt(1 + (block->raydirx * block->raydirx) /
			(block->raydiry * block->raydiry));
	block->hit = 0;
}

void		init_pos(t_block *block)
{
	if (block->raydirx < 0)
	{
		block->stepx = -1;
		block->sidedistx = (block->rayposx - block->mapx) * block->deltadistx;
	}
	else
	{
		block->stepx = 1;
		block->sidedistx = (block->mapx + 1.0 - block->rayposx) *
			block->deltadistx;
	}
	if (block->raydiry < 0)
	{
		block->stepy = -1;
		block->sidedisty = (block->rayposy - block->mapy) * block->deltadisty;
	}
	else
	{
		block->stepy = 1;
		block->sidedisty = (block->mapy + 1.0 - block->rayposy) *
			block->deltadisty;
	}
}

void		init_side(t_block *block)
{
	while (block->hit == 0)
	{
		if (block->sidedistx < block->sidedisty)
		{
			block->sidedistx += block->deltadistx;
			block->mapx += block->stepx;
			block->side = 0;
		}
		else
		{
			block->sidedisty += block->deltadisty;
			block->mapy += block->stepy;
			block->side = 1;
		}
		if (block->map[block->mapx][block->mapy] > 0)
			block->hit = 1;
	}
}

void		test(t_block *block)
{
	block->x = -1;
	while (++(block->x) < block->width)
	{
		init_new(block);
		init_pos(block);
		init_side(block);
		if (block->side == 0)
			block->perpwalldist = (block->mapx - block->rayposx +
					(1 - block->stepx) / 2) / block->raydirx;
		else
			block->perpwalldist = (block->mapy - block->rayposy +
					(1 - block->stepy) / 2) / block->raydiry;
		block->lineheight = (int)(block->height / block->perpwalldist);
		block->drawstart = -block->lineheight / 2 + block->height / 2;
		if (block->drawstart < 0)
			block->drawstart = 0;
		block->drawend = block->lineheight / 2 + block->height / 2;
		if (block->drawend >= block->height)
			block->drawend = block->height - 1;
		if (block->map[block->mapx][block->mapy] == 1)
			color(block, block->raydirx, block->raydiry);
		create_color(block);
	}
	mlx_put_image_to_window(block->mlx, block->window, block->img, 0, 0);
}
