/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dct_blk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:30:10 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/12 14:20:53 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dct		*ft_dct_blk(t_dct *begin_dct, int code, char ltr, int rot)
{
	t_dct		*dct;

	if (!(dct = (t_dct *)malloc(sizeof(t_dct))))
		return (NULL);
	dct->type = code;
	dct->letter = ltr;
	dct->rotation = rot;
	dct->next = begin_dct;
	return (dct);
}

t_dct		*ft_dct_init(void)
{
	t_dct		*begin_dct;

	if (!(begin_dct = (t_dct *)malloc(sizeof(t_dct))))
		return (NULL);
	begin_dct->next = NULL;
	return (begin_dct);
}
