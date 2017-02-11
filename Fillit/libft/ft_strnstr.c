/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 11:03:29 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/23 12:28:15 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	int		s2_len;

	i = 0;
	j = 0;
	s2_len = ft_strlen(s2) - 1;
	if (s2_len == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j] && (i + j) < n)
		{
			if (j == (size_t)s2_len)
				return ((char *)s1 + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
