/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 11:39:16 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/13 11:42:41 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_print_map(char **map)
{
	int		col;

	col = -1;
	while (map[++col] != NULL)
	{
		ft_putstr(map[col]);
		ft_putchar('\n');
	}
}
