/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:15:37 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:20:12 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

void	ft_free_bsq(char **bsq, t_bsq_data data)
{
	int		lines;

	lines = 0;
	while (lines < data.lines)
	{
		free(bsq[lines]);
		lines++;
	}
	free(bsq);
}
