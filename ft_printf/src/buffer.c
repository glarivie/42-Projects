/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 12:18:13 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 14:01:03 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char  *append(char *buffer, const char c)
{
  static size_t   reallocated = 1;
  static size_t   index = 0;

  if (ft_strlen(buffer) == reallocated * BUFFER_SIZE)
    buffer = (char *)ft_realloc(buffer, reallocated++ * (sizeof(char) * BUFFER_SIZE));

  buffer[index++] = c;

  return buffer;
}
