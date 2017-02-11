/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 17:30:40 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:18:32 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

int		ft_atoi(char *str)
{
	int		count;
	int		isneg;
	int		result;

	count = ft_isspace(str);
	result = 0;
	if (str[count] == '-')
		isneg = 1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		result = ((result * 10) + (str[count] - '0'));
		count++;
	}
	if (isneg)
		return (-result);
	else
		return (result);
}
