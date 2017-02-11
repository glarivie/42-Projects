/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 12:18:57 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:18:50 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

t_bool		ft_check_map(char **bsq, t_bsq_data data)
{
	int		lines;
	int		columns;

	lines = 0;
	columns = 0;
	if (data.lines < 1)
		return (FALSE);
	while (lines < data.lines)
	{
		while (columns < data.columns)
		{
			if ((bsq[lines][columns] != data.block)
					&& (bsq[lines][columns] != data.empty))
				return (FALSE);
			columns++;
		}
		if (bsq[lines][columns] != '\0' && bsq[lines][columns] != '\n')
			return (FALSE);
		if (columns != data.columns)
			return (FALSE);
		columns = 0;
		lines++;
	}
	return (TRUE);
}
