/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:32:28 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/27 14:40:40 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Vérifie si un caractère est compris entre "0" et "9"
*/

t_bool	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? TRUE : FALSE);
}
