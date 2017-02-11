/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 15:32:57 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 17:37:15 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list,
							void (*f)(void *),
							void *data_ref,
							int (*cmp)())
{
	t_list	*list;

	list = begin_list;
	if (list)
	{
		while (list->next != NULL)
		{
			if ((*cmp)(list->data, data_ref) == 0)
				(*f)(list->data);
			list = list->next;
		}
	}
}
