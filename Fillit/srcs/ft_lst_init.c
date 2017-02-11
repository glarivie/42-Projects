/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <guillaume.lariviere@stude>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:10:15 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/16 14:44:07 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_lst	*ft_lst_add(t_lst *begin_lst, int id)
{
	t_lst	*lst;
	int		col;

	col = -1;
	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	lst->id = id - 1;
	lst->used = FALSE;
	lst->next = begin_lst;
	lst->shape = (char *)malloc(sizeof(char) * 21);
	lst->shp = (char **)malloc(sizeof(char *) * 4);
	while (++col < 4)
		lst->shp[col] = (char *)malloc(sizeof(char) * 4 + 1);
	return (lst);
}

t_lst			*ft_lst_init(char *tab)
{
	t_lst	*begin_lst;
	int		cursor;
	int		col;

	col = -1;
	if (!(begin_lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (ft_strlen(tab) >= 440)
		cursor = ft_strlen(tab) / 20;
	else
		cursor = ft_strlen(tab) / 20 + 1;
	begin_lst->next = NULL;
	begin_lst->id = cursor - 1;
	begin_lst->used = FALSE;
	begin_lst->shape = (char *)malloc(sizeof(char) * 21);
	begin_lst->shp = (char **)malloc(sizeof(char *) * 4);
	while (++col < 4)
		begin_lst->shp[col] = (char *)malloc(sizeof(char) * 4 + 1);
	while (--cursor)
		begin_lst = ft_lst_add(begin_lst, cursor);
	return (begin_lst);
}
