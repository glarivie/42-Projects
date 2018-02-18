/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:39:29 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/27 14:43:43 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Vérifie qu'un caractère est espace, un retour à la ligne ou une tabulation
*/

t_bool	ft_isspace(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t' || c == '\r'
				|| c == '\f' || c == '\v') ? TRUE : FALSE);
}
