/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:56:20 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/19 08:27:12 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point				ft_rst_p(t_point p)
{
	p.x = 0;
	p.y = 0;
	return (p);
}

t_point				ft_inc_p(t_point p, int len)
{
	p.x = (p.x + 1) % len;
	if (p.x == 0)
		p.y = (p.y + 1) % len;
	return (p);
}

char				**ft_bt(t_lst *lst, char **map, int len, t_point p)
{
	char	**tmp_map;

	if (lst == NULL)
		return (map);
	if ((p.x == len - 1 && p.y == len - 1))
		return (NULL);
	if (ft_try(map, lst->shp, p.y, p.x) == TRUE)
	{
		map = ft_try_pl(map, lst->shp, p.y, p.x);
		lst->used = TRUE;
		if ((tmp_map = ft_bt(lst->next, map, len, ft_rst_p(p))) == NULL)
		{
			map = ft_rm_pl(map, lst->shp, len);
			return (ft_bt(lst, map, len, ft_inc_p(p, len)));
		}
		return (tmp_map);
	}
	return (ft_bt(lst, map, len, ft_inc_p(p, len)));
}
