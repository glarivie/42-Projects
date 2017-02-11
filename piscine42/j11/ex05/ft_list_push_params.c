/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 11:45:45 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/20 12:34:46 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_first_elem(void *data)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

t_list	*ft_create_other_elem(t_list *after_list, void *data)
{
	t_list	*tmp_list;

	tmp_list = NULL;
	tmp_list = malloc(sizeof(t_list));
	if (list)
	{
		tmp_list->data = data;
		tmp_list->next = after_list;
	}
	return (tmp_list);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 1;
	if (ac < 2)
		return (NULL);
	if (list)
	{
		list = ft_create_first_elem(av[i]);
		while (++i < ac)
			list->data = ft_create_other_elem(av[i + 1]);
	}
	return (list);
}
