/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_dct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:52:07 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/12 14:19:46 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_dct	*ft_fill_dct_2(t_dct *begin_dct)
{
	t_dct		*dct;

	dct = begin_dct;
	dct = ft_dct_blk(dct, 191129, 'J', 0);
	dct = ft_dct_blk(dct, 191239, 'J', 1);
	dct = ft_dct_blk(dct, 121919, 'J', 2);
	dct = ft_dct_blk(dct, 123919, 'J', 3);
	dct = ft_dct_blk(dct, 912129, 'S', 0);
	dct = ft_dct_blk(dct, 191291, 'S', 1);
	dct = ft_dct_blk(dct, 129912, 'Z', 0);
	dct = ft_dct_blk(dct, 911219, 'Z', 1);
	return (dct);
}

t_dct			*ft_fill_dct_1(t_dct *begin_dct)
{
	t_dct		*dct;

	dct = begin_dct;
	dct = ft_dct_blk(dct, 111199, 'I', 0);
	dct = ft_dct_blk(dct, 123499, 'I', 1);
	dct = ft_dct_blk(dct, 121299, 'O', 0);
	dct = ft_dct_blk(dct, 123010, 'T', 0);
	dct = ft_dct_blk(dct, 911291, 'T', 1);
	dct = ft_dct_blk(dct, 919123, 'T', 2);
	dct = ft_dct_blk(dct, 191219, 'T', 3);
	dct = ft_dct_blk(dct, 119129, 'L', 0);
	dct = ft_dct_blk(dct, 123199, 'L', 1);
	dct = ft_dct_blk(dct, 129119, 'L', 2);
	dct = ft_dct_blk(dct, 911239, 'L', 3);
	return (ft_fill_dct_2(dct));
}
