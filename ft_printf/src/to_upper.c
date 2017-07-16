/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:36:57 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/15 20:26:01 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char  *to_upper(char *str)
{
  size_t index;
  char *tmp;

  index = -1;
  tmp = strdup(str);
  while (str[++index])
    tmp[index] = ft_toupper(str[index]);

  return tmp;
}
