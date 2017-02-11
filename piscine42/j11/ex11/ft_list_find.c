/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 16:23:46 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 17:37:38 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;

	list = begin_list;
	if (list)
	{
		while (list->next != NULL)
		{
			if ((*cmp)(list->data, data_ref) == 0)
				return (list);
			else
				list = list->next;
		}
	}
}
