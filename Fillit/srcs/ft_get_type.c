/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 07:59:13 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/15 14:47:13 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char		*ft_zton(char *shape)
{
	int		index;

	index = -1;
	while (++index < 6)
	{
		if (!(shape[index] >= '1' && shape[index] <= '5'))
			shape[index] = '9';
	}
	return (shape);
}

static int		ft_fill_type(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	j = -1;
	ret = (char *)malloc(sizeof(char) * 7);
	while (s[++i])
	{
		if ((s[i] == '.') && ((s[i + 1] == '#' && s[i - 5] == '#')
					|| (s[i + 1] == '#' && s[i + 5] == '#')
					|| (s[i - 1] == '#' && s[i + 5] == '#')
					|| (s[i - 1] == '#' && s[i - 5] == '#')))
			ret[++j] = '0';
		if (s[i] == '#')
		{
			j++;
			ret[j] = (s[i - 1] == '#') ? ret[j - 1] + 1 : '1';
		}
	}
	ret[6] = '\0';
	return (ft_atoi(ft_zton(ret)));
}

void			ft_get_type(t_lst **begin_lst)
{
	t_lst	*lst;
	int		cursor;

	lst = *begin_lst;
	cursor = ft_lstlen(*begin_lst);
	while (--cursor)
	{
		lst->type = ft_fill_type(lst->shape);
		lst = lst->next;
	}
}
