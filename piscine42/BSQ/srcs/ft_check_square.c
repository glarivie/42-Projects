/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:20:33 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/28 12:33:25 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

int		ft_check_square(char **tab, t_bsq_data data, t_coord coord)
{
	int		x_count;
	int		y_count;
	int		feedback;

	y_count = 0;
	feedback = 0;
	while (y_count < coord.ref && (coord.y + y_count) < data.lines)
	{
		x_count = 0;
		while (x_count < coord.ref
				&& tab[coord.y + y_count][coord.x + x_count] != '\0')
		{
			if (tab[coord.y + y_count][coord.x + x_count] == data.block)
				return (0);
			feedback = feedback + 1;
			x_count++;
		}
		y_count++;
	}
	return (ft_sqrt(feedback));
}
