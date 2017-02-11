/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 10:35:57 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/14 11:40:32 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_srch_sensitive(char *src, char *to_find)
{
	int		i;
	int		j;
	int		if_match;
	
	i = 0;
	j = 0;
	if_match = 0;
	while (to_find[j])
	{
		if ((((src[i] > 64 && src[i] < 91)
				&& (src[i] == to_find[j]))
				|| ((src[i] > 96 && src[i] < 123)
				&& ((src[i] - 32) == to_find[j])))
					|| (((src[i] > 96 && src[i] < 123)
					&& (src[i] == to_find[j]))
					|| ((src[i] > 64 && src[i] < 91)
					&& ((src[i] + 32) == to_find[j]))))
			if_match++;
			j++;
			
	}
}

int		main(int argc, char **argv)
{
	int		i;
}
