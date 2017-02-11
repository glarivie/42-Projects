/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:28:12 by glarivie          #+#    #+#             */
/*   Updated: 2016/11/13 17:01:14 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	color(t_block *block, double raydirx, double raydiry)
{
	if (block->side && raydiry > 0)
	{
		block->color.r = 168;
		block->color.g = 113;
		block->color.b = 34;
	}
	else if (block->side && raydiry < 0)
	{
		block->color.r = 119;
		block->color.g = 148;
		block->color.b = 96;
	}
	else if (!block->side && raydirx > 0)
	{
		block->color.r = 125;
		block->color.g = 84;
		block->color.b = 124;
	}
	else
	{
		block->color.r = 158;
		block->color.g = 51;
		block->color.b = 54;
	}
}

void	create_color(t_block *block)
{
	int tmpy;
	int i;

	i = -1;
	tmpy = block->drawstart - 1;
	while (++i < block->drawstart)
		draw_pixel(block, block->x, i, &block->color2);
	while (++tmpy < block->drawend)
		draw_pixel(block, block->x, tmpy, &block->color);
	while (block->drawend < block->height - 1)
	{
		draw_pixel(block, block->x, block->drawend, &block->color3);
		block->drawend++;
	}
	if (block->side == 1)
		block->color.r = block->color.r / 2;
}
