/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:11:52 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/19 09:08:28 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

# define HUD_COLOR	0x333333
# define BASE_COLOR	0xCCCCCC

typedef struct	s_coord
{
	int			***val;
	int			length;
	int			width;
	int			indice;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			max;
	int			move_x;
	int			move_y;
	int			move_y_z;
	int			move_x_z;
	int			zoom;
	int			**t_val;
	int			sqr_x;
	int			sqr_y;
}				t_coord;

int				ft_start(int argc, char **argv, char **str, int *ver);
int				ft_open_file(int fd, char **file);
int				*ft_atoi_line(char *str, int *i);
int				**ft_create_tab(char **str, int *i, int *len);
int				ft_init(int **val, int length, int width);
int				ft_key_hook(int keycode, t_coord *e);
int				ft_key_h(int keycode, t_coord *e);
int				***ft_init_coord(int **val, int length, int width, t_coord *e);
void			ft_init_c(int *x, int *y, int *index, int **val);
int				ft_put_p(t_coord *e, int x, int y, int color);
void			ft_init_put_p(t_coord *e);
void			ft_set_coord(int *x, int *start, int nb1, int nb2);
void			ft_draw_line_x(t_coord *e, int i, int j);
void			ft_draw_line_y(t_coord *e, int i, int j);
void			ft_init_line_x(t_coord *e);
void			ft_init_line_y(t_coord *e);
int				ft_expose_hook(t_coord *e);
int				ft_mouse_hook(int button, int x, int y, t_coord *e);
void			ft_put_square(t_coord *e, int m_x, int m_y);
void			ft_write_op(t_coord *e);
void			ft_put_hud(t_coord *e);
void			ft_verif_value(int **val, int length, int width);

#endif
