/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:44:22 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 08:44:23 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_mandelbrot(t_mand *mand)
{
	mand->newre = 0;
	mand->newim = 0;
	mand->oldre = 0;
	mand->oldim = 0;
	mand->pr = 0;
	mand->pi = 0;
}
