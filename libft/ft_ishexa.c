/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:32:08 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/27 14:42:53 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Vérifie si un caractère est compris entre "0" et "9" ou en "a|A" et "f|F"
*/

t_bool		ft_ishexa(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
	(c >= 'A' && c <= 'F'))
		return (TRUE);
	return (FALSE);
}
