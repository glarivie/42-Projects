/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:08:15 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 18:11:22 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (*begin_list1)
	{
		while (*begin_list1->next != NULL)
			*begin_list1 = *begin_list1->next;
	}
	if (begin_list2)
		*begin_list1 = begin_list2->next;
}
