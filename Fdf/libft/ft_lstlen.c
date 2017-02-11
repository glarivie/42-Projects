/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 13:14:46 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/07 13:17:25 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstlen(t_list *begin_list)
{
	t_list		*list;
	size_t		count;

	list = begin_list;
	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}
