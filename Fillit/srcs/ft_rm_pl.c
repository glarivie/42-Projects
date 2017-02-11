/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:01:01 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/18 12:57:22 by ascholle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		ft_rm_pl2(char **blk)
{
	int		line;

	line = -1;
	while (++line < 4)
	{
		if (ft_ismaj(blk[0][line]) == TRUE)
			return (blk[0][line]);
	}
	return ('0');
}

char		**ft_rm_pl(char **map, char **blk, int len)
{
	int			col;
	int			line;
	char		c;

	c = '0';
	if (map != NULL && blk != NULL)
	{
		c = ft_rm_pl2(blk);
		if (c != '0')
		{
			col = -1;
			while (++col < len)
			{
				line = -1;
				while (++line < len)
				{
					if (map[col][line] == c)
						map[col][line] = '.';
				}
			}
		}
	}
	return (map);
}
