/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:03:21 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/15 14:47:34 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_type_angle(t_dct **begin_dct, t_lst **begin_lst)
{
	t_dct	*dct;
	t_lst	*lst;

	lst = *begin_lst;
	while (lst->next != NULL)
	{
		dct = *begin_dct;
		while (dct->next != NULL)
		{
			if (lst->type == dct->type)
			{
				lst->type_id = dct->letter;
				lst->angle = dct->rotation;
				break ;
			}
			else
				dct = dct->next;
		}
		lst = lst->next;
	}
}
