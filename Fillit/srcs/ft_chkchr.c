/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 11:35:55 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/08 09:24:24 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool		ft_chkchr(char *tab)
{
	int		index;

	index = -1;
	while (tab[++index])
	{
		if (tab[index] != '\n' && tab[index] != '#' && tab[index] != '.')
			return (FALSE);
	}
	return (TRUE);
}
