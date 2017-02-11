/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bsq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:14:08 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:21:34 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

void	ft_print_bsq(char **bsq, t_bsq_data data)
{
	int		lines;
	int		columns;

	lines = 0;
	columns = 0;
	while (lines < data.lines)
	{
		while (bsq[lines][columns])
		{
			write(1, &(bsq[lines][columns]), 1);
			columns++;
		}
		columns = 0;
		lines++;
	}
}
