/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:43:13 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 09:08:10 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instructions(void)
{
	ft_putendl("[USAGE] ./fractol julia");
	ft_putendl("[USAGE] ./fractol mandelbrot");
	ft_putendl("[USAGE] ./fractol manual");
	exit(EXIT_FAILURE);
}
