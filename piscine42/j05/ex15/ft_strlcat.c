/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:54:27 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/12 14:36:11 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		if (i < size - 1)
			dest[i] = src[j];
		j++;
		i++;
	}
	dest[i - 1] = '\0';
	return (i);
}
