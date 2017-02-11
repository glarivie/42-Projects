/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bsq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:09:21 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:20:31 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

char		**ft_get_bsq(t_bsq_data data, char *buf)
{
	char	**bsq;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (buf[i[0]] != '\n')
		i[0]++;
	i[0]++;
	bsq = (char **)malloc(sizeof(char *) * data.lines);
	while (i[1] < data.lines)
	{
		bsq[i[1]] = (char *)malloc(sizeof(char) * data.columns + 1);
		while (i[2] <= data.columns)
		{
			bsq[i[1]][i[2]] = buf[i[0]];
			i[0]++;
			i[2]++;
		}
		bsq[i[1]][i[2]] = '\0';
		i[2] = 0;
		i[1]++;
	}
	return (bsq);
}
