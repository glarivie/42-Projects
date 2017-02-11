/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:47:29 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/18 11:31:29 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_free_dct(t_dct **start)
{
	t_dct	*tmp;

	while (*start != NULL)
	{
		tmp = *start;
		*start = (*start)->next;
		free(tmp);
	}
}

static void		ft_free_lst(t_lst **start)
{
	t_lst	*tmp;

	while (*start != NULL)
	{
		tmp = *start;
		*start = (*start)->next;
		free(tmp);
	}
}

static void		ft_free_map(char **map)
{
	int		col;

	col = -1;
	while (map[++col] != NULL)
		free(map[col]);
	free(map);
}

void			ft_free_all(t_dct **begin_dct, t_lst **begin_lst, char **map)
{
	ft_free_dct(begin_dct);
	ft_free_lst(begin_lst);
	ft_free_map(map);
}
