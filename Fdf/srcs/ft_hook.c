/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:11:46 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/14 17:18:35 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_expose_hook(t_coord *e)
{
	ft_init_put_p(e);
	ft_init_line_x(e);
	ft_init_line_y(e);
	ft_write_op(e);
	return (0);
}

int		ft_key_h(int keycode, t_coord *e)
{
	if (keycode == 126)
	{
		e->move_y = e->move_y - 30;
		mlx_clear_window(e->mlx, e->win);
		ft_expose_hook(e);
	}
	if (keycode == 69)
	{
		e->zoom = (e->zoom + 5) == 100 ? 95 : e->zoom + 5;
		e->move_x_z += 15;
		e->move_y_z += 15;
		mlx_clear_window(e->mlx, e->win);
		e->val = ft_init_coord(e->t_val, e->length, e->width, e);
		ft_expose_hook(e);
	}
	if (keycode == 78)
	{
		e->zoom = ((e->zoom - 5) == -35 ? -30 : e->zoom - 5);
		mlx_clear_window(e->mlx, e->win);
		e->val = ft_init_coord(e->t_val, e->length, e->width, e);
		ft_expose_hook(e);
	}
	return (0);
}

int		ft_key_hook(int keycode, t_coord *e)
{
	int	i;

	i = e->length;
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
	{
		e->move_x = e->move_x + 30;
		mlx_clear_window(e->mlx, e->win);
		ft_expose_hook(e);
	}
	if (keycode == 123)
	{
		e->move_x = e->move_x - 30;
		mlx_clear_window(e->mlx, e->win);
		ft_expose_hook(e);
	}
	if (keycode == 125)
	{
		e->move_y = e->move_y + 30;
		mlx_clear_window(e->mlx, e->win);
		ft_expose_hook(e);
	}
	ft_key_h(keycode, e);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_coord *e)
{
	int		i;

	i = e->length;
	x = y;
	if (button == 1 || button == 5)
	{
		e->zoom = e->zoom + 5;
		if (e->zoom == 100)
			e->zoom = 95;
		mlx_clear_window(e->mlx, e->win);
		e->val = ft_init_coord(e->t_val, e->length, e->width, e);
		ft_expose_hook(e);
	}
	if (button == 3 || button == 4)
	{
		e->zoom -= 5;
		if (e->zoom == -35)
			e->zoom = -30;
		mlx_clear_window(e->mlx, e->win);
		e->val = ft_init_coord(e->t_val, e->length, e->width, e);
		ft_expose_hook(e);
	}
	return (0);
}
