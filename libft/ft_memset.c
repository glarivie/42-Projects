/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 19:39:30 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/23 14:09:00 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Crée une copie de "b" et inscrit "len" caractère "c" de type INT
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *copy;

	copy = (unsigned char *)b;
	while (len--)
		copy[len] = c;
	return (copy);
}
