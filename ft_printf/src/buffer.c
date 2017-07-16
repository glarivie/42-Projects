/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 12:18:13 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 17:47:50 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*append_char(char *buffer, const char c)
{
	static size_t	r = 1;
	static size_t	index = 0;

	if (ft_strlen(buffer) == r * BUFFER_SIZE)
		buffer = (char *)ft_realloc(buffer, ++r * (sizeof(char) * BUFFER_SIZE));
	buffer[index++] = c;
	return (buffer);
}

char	*append_str(char *buffer, const char *str)
{
	while (*str)
		buffer = append_char(buffer, *str++);
	return (buffer);
}
