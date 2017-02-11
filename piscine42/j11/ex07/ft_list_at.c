/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 12:55:00 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 17:36:16 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

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
