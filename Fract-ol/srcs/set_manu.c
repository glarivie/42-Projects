/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_manu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:44:29 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 10:04:36 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_manu(t_julia *ju, t_mlx *mlx)
{
	ju->cre = mlx->x / 100;
	ju->cim = mlx->y / 100;
	ju->newre = 1;
	ju->newim = 1;
	mlx->maxiter = 45;
	ju->oldre = 0.43;
	ju->oldim = -0.2;
	ju->color = 0x000000;
}
