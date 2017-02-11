/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkgrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 11:42:48 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/08 09:32:41 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_chrcnt(char *tab, char c)
{
	int	count;
	int	index;

	count = 0;
	index = -1;
	while (tab[++index])
	{
		if (tab[index] == c)
			count++;
	}
	return (count);
}

t_bool		ft_chkgrid(char *tab)
{
	int		line;
	int		blk;
	int		index;
	int		count;

	line = 0;
	blk = 0;
	index = -1;
	count = 0;
	while (tab[++index])
	{
		if (tab[index] == '.' || tab[index] == '#')
			count++;
		if (tab[index] == '\n' && tab[index - 1] != '\n' && (count % 4) == 0)
			line++;
		if (tab[index] == '\n' && tab[index - 1] == '\n' && (line % 4) == 0)
			blk++;
	}
	if (tab[index] == '\0' && (line % 4) == 0)
		blk++;
	if (ft_chrcnt(tab, '.') == (blk * 12)
			&& ft_chrcnt(tab, '#') == (blk * 4)
			&& ft_chrcnt(tab, '\n') == (line + blk - 1))
		return (TRUE);
	return (FALSE);
}
