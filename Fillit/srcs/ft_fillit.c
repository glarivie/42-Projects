/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:05:03 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/19 08:19:15 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fillit(int ac, char **av, int len)
{
	char		*buf;
	t_dct		*begin_dct;
	t_lst		*begin_lst;
	char		**map;

	if ((buf = ft_read(av, 1)) == NULL)
	{
		ft_putstr("error\n");
		return ;
	}
	if (ft_chk_err(ac, buf) == FALSE)
		return ;
	begin_dct = ft_fill_dct_1(ft_dct_init());
	begin_lst = ft_lst_init(buf);
	ft_fill_lst(buf, &begin_lst);
	ft_get_type(&begin_lst);
	if (ft_chk_err_2(begin_lst, begin_dct) == FALSE)
		return ;
	ft_type_angle(&begin_dct, &begin_lst);
	ft_fix_shape(&begin_lst);
	ft_fill_shp(&begin_lst);
	ft_rm_last(&begin_lst);
	map = ft_get_map(len);
	ft_fillit2(map, &begin_lst, &begin_dct, len);
}

void	ft_fillit2(char **map, t_lst **begin_lst, t_dct **begin_dct, int len)
{
	t_point		p;

	p.x = 0;
	p.y = 0;
	while ((map = ft_bt(*begin_lst, map, len, p)) == NULL)
	{
		ft_lst_clr(*begin_lst);
		while (map)
		{
			free(*map);
			map++;
		}
		free(map);
		map = ft_get_map(++len);
	}
	if (map)
		ft_print_map(map);
	ft_free_all(begin_dct, begin_lst, map);
}
