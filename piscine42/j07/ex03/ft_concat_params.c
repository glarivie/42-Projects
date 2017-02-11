/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 15:31:13 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 10:30:43 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		length;
	char	*result;

	i = 1;
	j = 0;
	length = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			j++;
		}
		length = length + j;
		j = 0;
		i++;
	}
	i = 1;
	k = 0;
	result = (char *)malloc(sizeof(*result) * length + 1);
	while (i < argc)
	{
		while (argv[i][j])
		{
			result[k] += argv[i][j];
			j++;
			k++;
		}
		j = 0;
		i++;
		result[i] = '\n';
	}
	return (result);
}
