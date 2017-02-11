/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:40:07 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/18 11:32:23 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		**ft_get_map(int len)
{
	char	**ret;
	int		i;
	int		j;

	i = -1;
	if (!(ret = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (++i < len)
	{
		if (!(ret[i] = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		j = -1;
		while (++j < len)
			ret[i][j] = '.';
		ret[i][j] = '\0';
	}
	ret[len] = NULL;
	return (ret);
}
