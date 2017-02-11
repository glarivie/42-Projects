/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 15:53:29 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/26 10:04:29 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		index;

	index = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (index < n)
		{
			if (*((char *)s1 + index) != *((char *)s2 + index))
				return ((int)(*((char *)s1 + index) - *((char *)s2 + index)));
			index++;
		}
		return (0);
	}
	return (ERROR);
}
