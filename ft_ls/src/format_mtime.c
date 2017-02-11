/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_mtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:08:24 by glarivie          #+#    #+#             */
/*   Updated: 2016/03/27 17:14:45 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*format_mtime(char *mtime)
{
	static char	ret_time[12];
	int			index;

	index = -1;
	while (++index < 12)
		ret_time[index] = mtime[index + 4];
	ret_time[index] = '\0';
	return (ret_time);
}
