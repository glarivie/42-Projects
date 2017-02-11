/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:27:30 by glarivie          #+#    #+#             */
/*   Updated: 2016/11/13 18:12:22 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		copy_map2(t_block *block)
{
	block->map[10][1] = 1;
	block->map[10][6] = 1;
	block->map[10][7] = 1;
	block->map[10][8] = 1;
	block->map[10][9] = 1;
	block->map[10][5] = 1;
	block->map[10][10] = 1;
	block->map[6][7] = 1;
	block->map[6][18] = 1;
	block->map[11][7] = 1;
	block->map[13][6] = 1;
	block->map[19][4] = 1;
	block->map[13][4] = 1;
	block->map[15][1] = 1;
	block->map[4][20] = 1;
	block->map[5][10] = 1;
	block->map[20][5] = 1;
	block->map[17][11] = 1;
	block->map[11][11] = 1;
	block->map[12][12] = 1;
	block->map[10][9] = 1;
	block->map[8][19] = 1;
	block->map[3][12] = 1;
	block->map[1][4] = 1;
	block->map[2][13] = 1;
}

static void		copy_map(t_block *block)
{
	block->map[4][5] = 1;
	block->map[4][6] = 1;
	block->map[4][7] = 1;
	block->map[4][8] = 1;
	block->map[4][9] = 1;
	block->map[5][5] = 1;
	block->map[5][9] = 1;
	block->map[6][12] = 1;
	block->map[6][8] = 1;
	block->map[12][7] = 1;
	block->map[12][6] = 1;
	block->map[20][4] = 1;
	block->map[12][4] = 1;
	block->map[14][1] = 1;
	block->map[3][20] = 1;
	block->map[4][10] = 1;
	block->map[19][5] = 1;
	block->map[19][11] = 1;
	block->map[10][11] = 1;
	block->map[10][12] = 1;
	block->map[9][9] = 1;
	block->map[9][19] = 1;
	block->map[2][12] = 1;
	block->map[3][4] = 1;
}

static void		set_map(t_block *block)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 21)
	{
		j = -1;
		while (++j < 21)
		{
			if (i == 0 || i == 20)
				block->map[i][j] = 1;
			else if (j == 0 || j == 20)
				block->map[i][j] = 1;
			else
				block->map[i][j] = 0;
		}
	}
	copy_map(block);
	copy_map2(block);
}

int				main(void)
{
	t_block		block;

	init_mlx(&block);
	init_sky_floor(&block);
	set_map(&block);
	test(&block);
	mlx_put_image_to_window(block.mlx, block.window, block.img, 0, 0);
	mlx_key_hook(block.window, key_hook, &block);
	mlx_hook(block.window, 17, 0, close_window, &block);
	mlx_hook(block.window, 2, (1L << 0), key_hook, &block);
	mlx_loop(block.mlx);
	return (EXIT_SUCCESS);
}
