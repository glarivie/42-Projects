/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 14:42:43 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 17:36:38 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	if (list)
	{
		while (list->next != NULL)
		{
			list = list->next;
			i++;
		}
	}
	return (i);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int		i;
	t_list				*list;

	i = 0;
	list = begin_list;
	if (list)
	{
		while (list->next != NULL)
		{
			if (i == nbr)
				return (list);
			else
				list = list->next;
			i++;
		}
	}
	return (NULL);
}

void	ft_list_reverse(t_list **begin_list)
{
	int		size;
	t_list	*list;
	t_list	*list_return;

	size = ft_list_size(begin_list) - 1;
	list = *begin_list;
	list_return = NULL;
	if (list)
	{
		while (size > 0)
		{
			list_return->next = ft_list_at(list, size);
			size = size - 1;
		}
		list_return->next = NULL;
	}
	return (list);
}
