/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:45:25 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 18:52:04 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	int		count;
	char	*buffer;
	va_list	ap;
	int		d;

	count = 0;
	va_start(ap, fmt);
	buffer = ft_strnew(sizeof(char) * BUFFER_SIZE);
	--fmt;
	while (*++fmt)
	{
		if (*fmt != '%')
			buffer = append_char(buffer, *fmt);
		else
		{
			printf("fmt: %c, fmt + 1: %c\n", *fmt, *(fmt + 1));
			if (*(++fmt) == 'd')
			{
				puts("lol");
				d = (int)va_arg(ap, int);
				buffer = append_str(buffer, ft_itoa(d));
			}
		}
	}
	buffer = append_char(buffer, '\0');
	count = ft_strlen(buffer);
	ft_putstr(buffer);
	free(buffer);
	va_end(ap);
	return (count);
}
