/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:42:48 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/19 12:31:39 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			index;
	void		*tmp;
//	int			num;

	index = -1;
//	num = 0;
	va_start(ap, format);
	while(format[++index])
	{
		if (format[index] != '%' && format[index - 1] != '%')
			ft_putchar(format[index]);
		if (format[index] == '%')
		{
			if (format[index + 1] == 's')
			{
				tmp = va_arg(ap, char *);
				ft_putstr((char *)tmp);
			}
			if (format[index + 1] == 'd')
			{
				tmp = va_arg(ap, char *);
				ft_putnbr(ft_atoi((char *)tmp));
			}
			if (format[index + 1] == 'S')
			{
				tmp = (wchar_t *)va_arg(ap, wchar_t *);
				printf("%S", (wchar_t *)tmp);
			//	ft_putstr((char *)tmp);
			}
		}
	}
	va_end(ap);
	return (0);
}
