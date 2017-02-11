/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 11:42:41 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 12:56:17 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_length;
	int		copy_count;
	char	*copy;

	copy_count = 0;
	src_length = 0;
	while (src[src_length])
		src_length++;
	copy = (char *)malloc(sizeof(char) * (src_length));
	while (copy_count < src_length)
	{
		copy[copy_count] = src[copy_count];
		copy_count++;
	}
	copy[copy_count] = '\0';
	return (copy);
}
