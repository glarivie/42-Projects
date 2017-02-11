/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 07:58:34 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/10 14:52:39 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_fill_lst(char *tab, t_lst **begin_lst)
{
	t_lst	*lst;
	int		index_tab;
	int		index_shape;

	lst = *begin_lst;
	index_tab = -1;
	index_shape = 0;
	while (tab[++index_tab])
	{
		if (tab[index_tab] == '\n' && tab[index_tab - 1] == '\n')
		{
			lst->shape[index_shape] = '\0';
			lst = lst->next;
			index_shape = 0;
		}
		else
		{
			lst->shape[index_shape] = tab[index_tab];
			index_shape++;
		}
	}
}
