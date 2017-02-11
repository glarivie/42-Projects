/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 17:33:06 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 18:01:23 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	void	*tmp_data;

	if (*begin_list)
	{
		while (*begin_list->next != NULL)
		{
			if ((*cmp)(*begin_list->data, *begin_list->next->data) > 0)
			{
				tmp_data = *begin_list->data;
				*begin_list->data = *begin_list->next->data;
				*begin_list->next->data = tmp_data;
			}
			*begin_list = *begin_list->next;
		}
	}
}
