/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:42:23 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 09:10:46 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		analyse_arg(char *str)
{
	if (ft_strcmp(str, "julia") != 0 && ft_strcmp(str, "mandelbrot") != 0 &&
		ft_strcmp(str, "manual") != 0)
		instructions();
	else
	{
		if (ft_strcmp(str, "julia") == 0)
			return (1);
		else if (ft_strcmp(str, "mandelbrot") == 0)
			return (2);
		else if (ft_strcmp(str, "manual") == 0)
			return (3);
	}
	return (0);
}
