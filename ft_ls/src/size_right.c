/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:08:24 by glarivie          #+#    #+#             */
/*   Updated: 2016/03/27 16:29:26 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	size_right(int st_size)
{
	int		int_size;

	int_size = -1;
	while (++int_size < (5 - ft_intlen(st_size)))
		ft_putchar(' ');
	ft_putnbr(st_size);
}
