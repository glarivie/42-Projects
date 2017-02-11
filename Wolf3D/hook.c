/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:27:53 by glarivie          #+#    #+#             */
/*   Updated: 2016/11/13 18:14:15 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_block(t_block *block)
{
	mlx_destroy_window(block->mlx, block->window);
	free(block->mlx);
	free(block->img);
	free(block->imgbuff);
	exit(EXIT_SUCCESS);
}

void		key_hook2(int key, t_block *block)
{
	if (key == 124)
	{
		block->olddirx = block->dirx;
		block->dirx = block->dirx * cos(-0.1) - block->diry * sin(-0.1);
		block->diry = block->olddirx * sin(-0.1) + block->diry * cos(-0.1);
		block->oldplanex = block->planex;
		block->planex = block->planex * cos(-0.1) - block->planey * sin(-0.1);
		block->planey = block->oldplanex * sin(-0.1) +
			block->planey * cos(-0.1);
	}
	if (key == 123)
	{
		block->olddirx = block->dirx;
		block->dirx = block->dirx * cos(0.1) - block->diry * sin(0.1);
		block->diry = block->olddirx * sin(0.1) + block->diry * cos(0.1);
		block->oldplanex = block->planex;
		block->planex = block->planex * cos(0.1) - block->planey * sin(0.1);
		block->planey = block->oldplanex * sin(0.1) + block->planey * cos(0.1);
	}
	if (key == 53)
		free_block(block);
}

int			key_hook(int key, t_block *b)
{
	if (key == 126)
	{
		if (!(b->map[(int)(b->posx + b->dirx * 0.15)][(int)(b->posy)]))
			b->posx += b->dirx * 0.15;
		if (!(b->map[(int)(b->posx)][(int)(b->posy + b->diry * 0.15)]))
			b->posy += b->diry * 0.15;
	}
	if (key == 125)
	{
		if (!(b->map[(int)(b->posx - b->dirx * 0.15)][(int)(b->posy)]))
			b->posx -= b->dirx * 0.15;
		if (!(b->map[(int)(b->posx)][(int)(b->posy - b->diry * 0.15)]))
			b->posy -= b->diry * 0.15;
	}
	else if (key == 124 || key == 123 || key == 53)
		key_hook2(key, b);
	mlx_destroy_image(b->mlx, b->img);
	b->img = mlx_new_image(b->mlx, b->width, b->height);
	test(b);
	mlx_put_image_to_window(b->mlx, b->window, b->img, 0, 0);
	return (1);
}
