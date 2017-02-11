/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 18:52:45 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/26 09:46:48 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	if (s1 == '\0' || s2 == '\0')
		return (ERROR);
	while (s1[index] == s2[index] && s1[index]
					&& s2[index] && (index < (n - 1)))
		index++;
	return (s1[index] - s2[index]);
}
