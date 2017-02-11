/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 13:43:24 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 12:56:40 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		copy[i] = (*f)(tab[i]);
		i++;
	}
	return (copy);
}
