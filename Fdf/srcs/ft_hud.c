/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:12:37 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/14 17:12:40 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_square(t_coord *e, int m_x, int m_y)
{
	int		tmp_x;
	int		tmp_y;
	int		x;
	int		y;

	x = e->sqr_x;
	y = e->sqr_y;
	tmp_x = e->sqr_x;
	tmp_y = e->sqr_y;
	while (x != m_x)
		ft_put_p(e, (x++ - e->move_x), (y - e->move_y), HUD_COLOR);
	while (y != m_y)
		ft_put_p(e, (x - e->move_x), (y++ - e->move_y), HUD_COLOR);
	while (x != tmp_x)
		ft_put_p(e, (x-- - e->move_x), (y - e->move_y), HUD_COLOR);
	while (y != tmp_y)
		ft_put_p(e, (x - e->move_x), (y-- - e->move_y), HUD_COLOR);
}

void		ft_write_op(t_coord *e)
{
	mlx_string_put(e->mlx, e->win, 35, 35, HUD_COLOR, "Quit = ESC");
	mlx_string_put(e->mlx, e->win, 35, 55, HUD_COLOR, "Move = ^ v < >");
	mlx_string_put(e->mlx, e->win, 35, 75, HUD_COLOR, "Zoom = + -");
	ft_put_hud(e);
}

void		ft_put_hud(t_coord *e)
{
	e->sqr_x = 102;
	e->sqr_y = 38;
	ft_put_square(e, 138, 54);
	e->sqr_x = 102;
	e->sqr_y = 58;
	ft_put_square(e, 118, 74);
	e->sqr_x = 122;
	e->sqr_y = 58;
	ft_put_square(e, 138, 74);
	e->sqr_x = 142;
	e->sqr_y = 58;
	ft_put_square(e, 158, 74);
	e->sqr_x = 162;
	e->sqr_y = 58;
	ft_put_square(e, 178, 74);
	e->sqr_x = 102;
	e->sqr_y = 78;
	ft_put_square(e, 118, 94);
	e->sqr_x = 122;
	e->sqr_y = 78;
	ft_put_square(e, 138, 94);
	e->sqr_x = 25;
	e->sqr_y = 30;
	ft_put_square(e, 188, 104);
}
