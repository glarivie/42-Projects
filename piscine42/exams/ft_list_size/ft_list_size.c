/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 11:41:06 by exam              #+#    #+#             */
/*   Updated: 2015/09/10 20:28:51 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	t_list		*list;
	int			size;

	size = 0;
	list = begin_list;
	if (list)
	{
		while (list->next != NULL)
		{
			list = list->next;
			size++;
		}
	}
	return (size - 1);
}
