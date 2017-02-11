/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:44:15 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 11:48:02 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_julia(t_julia *ju, t_mlx *mlx)
{
	ju->cre = -0.7 + mlx->x / 750;
	ju->cim = 0.27015 + mlx->y / 750;
	ju->newre = 0;
	ju->newim = 0;
	ju->oldre = 0;
	ju->oldim = 0;
	ju->color = 0x000000;
}
