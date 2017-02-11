/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:12:38 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:21:19 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

int		ft_isspace(char *str)
{
	int		count;

	count = 0;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	return (count);
}
