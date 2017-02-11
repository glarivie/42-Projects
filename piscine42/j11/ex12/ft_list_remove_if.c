/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:11:57 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 18:17:50 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (*begin_list)
	{
		while (*begin_list->next != NULL)
		{
			if ((*cmp)(*begin_list->data, data_ref) == 0)
				*begin_list = *begin_list->next->next;
			else
				*begin_list = *begin_list->next;
		}
	}
}
