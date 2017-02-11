/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:42:06 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 11:46:25 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "libft.h"
# include <math.h>

# define NAME "Fractol"
# define ZOOM 1
# define MOTION 1
# define WIDTH 780
# define HEIGHT 520

typedef struct		s_julia
{
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	int				color;
}					t_julia;

typedef struct		s_mand
{
	double			pr;
	double			pi;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	int				color;
}					t_mand;

typedef struct		s_mlx
{
	double			zoom;
	void			*init;
	void			*win;
	int				choice;
	int				edn;
	int				bpp;
	int				s_l;
	char			*new_img;
	char			*add;
	double			x;
	double			y;
	double			offset_x;
	double			offset_y;
	double			width;
	double			height;
	int				motion;
	int				maxiter;
}					t_mlx;

void				set_julia(t_julia *ju, t_mlx *mlx);
void				set_mandelbrot(t_mand *mand);
void				set_manu(t_julia *ju, t_mlx *mlx);
int					hsv_to_rgb(int h, int s, int v);
int					rgb_to_int(int r, int g, int b);
void				img_pixel_put(int x, int y, int color, t_mlx *mlx);
void				instructions(void);
int					analyse_arg(char *str);
void				ft_mlx(t_mlx mlx);
int					mouse_motion_hook(int x, int y, t_mlx *mlx);
int					key_hook(int keycode, t_mlx *mlx);
int					mouse_key_hook(int button, int x, int y, t_mlx *mlx);
int					julia(t_mlx *mlx, t_julia *ju);
void				mandelbrot(t_mlx *mlx, t_mand *mand);
void				manu(t_mlx *mlx, t_julia *ju);
void				zoom_out(int x, int y, t_mlx *mlx);
void				zoom_set(int x, int y, t_mlx *mlx);

#endif
