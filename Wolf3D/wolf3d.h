/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:26:52 by glarivie          #+#    #+#             */
/*   Updated: 2016/11/13 18:12:20 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_block
{
	void		*mlx;
	void		*window;
	void		*img;
	int			map[21][21];
	char		*imgbuff;
	int			bpp;
	int			sizelen;
	int			end;
	int			width;
	int			height;
	int			drawend;
	int			drawstart;
	int			side;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			done;
	int			x;
	double		movespeed;
	double		rotspeed;
	double		olddirx;
	double		oldplanex;
	int			lineheight;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	t_color		color;
	t_color		color2;
	t_color		color3;
}				t_block;

void			draw_pixel(t_block *b, int x, int y, t_color *color);
void			color(t_block *block, double raydirx, double raydiry);
void			create_color(t_block *block);
void			init_new(t_block *block);
void			init_pos(t_block *block);
void			init_side(t_block *block);
void			test(t_block *block);
void			key_hook2(int key, t_block *block);
int				key_hook(int key, t_block *block);
int				close_window(void *param);
void			init_mlx(t_block *block);
void			init_sky_floor(t_block *block);
void			free_block(t_block *block);

#endif
