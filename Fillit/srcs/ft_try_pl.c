/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 13:23:19 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/16 14:49:00 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool			ft_try(char **map, char **blk, int col, int line)
{
	int		y;
	int		x;
	int		chk;

	y = -1;
	chk = 0;
	while (++y < 4 && map[col + y] != NULL)
	{
		x = -1;
		while (++x < 4 && map[col + y][line + x] != '\0')
		{
			if (blk[y][x] == ' ')
				break ;
			if (ft_ismaj(blk[y][x]) && map[col + y][line + x] == '.')
				chk++;
		}
	}
	if (chk == 4)
		return (TRUE);
	return (FALSE);
}

char			**ft_try_pl(char **map, char **blk, int col, int line)
{
	int		y;
	int		x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (blk[y][x] == ' ')
				break ;
			if (ft_ismaj(blk[y][x]) && map[col + y][line + x] == '.')
				map[col + y][line + x] = blk[y][x];
		}
	}
	return (map);
}
