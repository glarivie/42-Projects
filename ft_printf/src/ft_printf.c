/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:45:25 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 17:49:36 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	int		count;
	char	*buffer;
	va_list	ap;

	count = 0;
	buffer = ft_strnew(sizeof(char) * BUFFER_SIZE);
	while (*fmt)
	{
		if (*fmt != '%')
			buffer = append_char(buffer, *fmt++);
	}
	buffer[ft_strlen(buffer)] = '\0';
	count = ft_strlen(buffer);
	ft_putstr(buffer);
	free(buffer);
	va_end(ap);
	return (count);
}
