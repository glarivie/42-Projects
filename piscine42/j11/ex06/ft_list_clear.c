/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 12:25:35 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 12:48:55 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*list;
	t_lsit	*tmp_list;

	list = *begin_list;
	tmp_list = NULL;
	if (list)
	{
		while (tmp_list->next != NULL)
		{
			tmp_list = list->next;
			free(list);
		}
	}
	free(tmp_list);
	tmp_list = NULL;
}
