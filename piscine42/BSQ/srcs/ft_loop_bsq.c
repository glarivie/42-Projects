/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 22:27:24 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 22:37:38 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

void	ft_loop_bsq(int ac, char **av)
{
	unsigned long long	ret2;
	char				*buf;
	t_bsq_data			data;
	char				**bsq;
	int					i;

	i = 1;
	while (i < ac)
	{
		ret2 = ft_get_swap(i, av);
		buf = ft_read(ret2);
		data = ft_get_infos(buf, ret2);
		bsq = ft_get_bsq(data, buf);
		if ((ft_check_map(bsq, data) == FALSE))
			write(2, "map error\n", 10);
		else
		{
			bsq = ft_fill_square(bsq, data, ft_check_tab(bsq, data));
			ft_print_bsq(bsq, data);
		}
		ft_free_bsq(bsq, data);
		i++;
	}
}
