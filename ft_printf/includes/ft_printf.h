/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:35:22 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 17:47:47 by glarivie         ###   ########.fr       */
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

# define BUFFER_SIZE 2

int		ft_printf(const char *fmt, ...);
char	*append_char(char *buffer, const char c);
char	*append_str(char *buffer, const char *str);
char	*to_upper(char *str);

#endif
