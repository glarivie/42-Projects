/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:43:32 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 09:10:13 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		instructions();
	mlx.choice = analyse_arg(argv[1]);
	ft_mlx(mlx);
	return (0);
}
