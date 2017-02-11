/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:07:15 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/19 08:11:25 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool		ft_chk_err(int ac, char *buf)
{
	if (ac != 2 || ft_chkchr(buf) == FALSE
			|| ft_chkgrid(buf) == FALSE || buf[ft_strlen(buf)] == '\n')
	{
		ft_putstr("error\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool		ft_chk_err_2(t_lst *begin_lst, t_dct *begin_dct)
{
	if (ft_chktype(begin_dct, begin_lst) == FALSE
			|| ft_chk_wtf(begin_lst) == FALSE)
	{
		ft_putstr("error\n");
		return (FALSE);
	}
	return (TRUE);
}
