/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:28:01 by glarivie          #+#    #+#             */
/*   Updated: 2016/11/13 13:28:02 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_pixel(t_block *b, int x, int y, t_color *color)
{
	b->imgbuff = mlx_get_data_addr(b->img, &(b->bpp), &(b->sizelen), &(b->end));
	b->imgbuff[x * b->bpp / 8 + y * b->sizelen] = (unsigned char)color->b;
	b->imgbuff[x * b->bpp / 8 + 1 + y * b->sizelen] = (unsigned char)color->g;
	b->imgbuff[x * b->bpp / 8 + 2 + y * b->sizelen] = (unsigned char)color->r;
}
