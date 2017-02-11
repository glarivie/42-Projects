/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 17:36:16 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:20:50 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

t_bsq_data		ft_get_infos(char *buf, unsigned long long ret2)
{
	t_bsq_data		data;
	char			infos[BUFFER];
	int				i;

	i = 0;
	while (buf[i] != '\n')
	{
		infos[i] = buf[i];
		i++;
	}
	infos[i] = '\0';
	data.lines = ft_atoi(buf);
	data.sqr_px = infos[i - 1];
	data.block = infos[i - 2];
	data.empty = infos[i - 3];
	data.columns = ((ret2 - i) / data.lines) - 1;
	return (data);
}
