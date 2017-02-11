/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_wtf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 07:44:19 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/19 08:30:05 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	t_bool		ft_isdiese(char c)
{
	return ((c == '#') ? TRUE : FALSE);
}

static t_bool		ft_chk_bbb(char *blk)
{
	int		index;
	int		count;

	index = -1;
	count = 0;
	while (blk[++index])
	{
		if (ft_isdiese(blk[index]) && ft_isdiese(blk[index - 1]))
			count++;
		if (ft_isdiese(blk[index]) && ft_isdiese(blk[index + 1]))
			count++;
		if (ft_isdiese(blk[index]) && ft_isdiese(blk[index - 5]))
			count++;
		if (ft_isdiese(blk[index]) && ft_isdiese(blk[index + 5]))
			count++;
	}
	return ((count >= 6) ? TRUE : FALSE);
}

t_bool				ft_chk_wtf(t_lst *begin_lst)
{
	while (begin_lst->next != NULL)
	{
		if (ft_chk_bbb(begin_lst->shape) == FALSE)
			return (FALSE);
		begin_lst = begin_lst->next;
	}
	return (TRUE);
}
