/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 09:27:00 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/15 14:40:16 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_lstlen(t_lst *begin_lst)
{
	t_lst	*lst;
	int		cursor;

	lst = begin_lst;
	cursor = 0;
	if (begin_lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		cursor++;
	}
	return (cursor + 1);
}

int		ft_dctlen(t_dct *begin_dct)
{
	t_dct	*dct;
	int		cursor;

	dct = begin_dct;
	cursor = 0;
	if (begin_dct == NULL)
		return (1);
	while (dct->next != NULL)
	{
		cursor++;
		dct = dct->next;
	}
	return (cursor);
}
