/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:35:22 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 14:25:25 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <assert.h>

# define BUFFER_SIZE 1

int   ft_printf(const char *fmt, ...);
char  *append(char *buffer, const char c);
char  *to_upper(char *str);

#endif
