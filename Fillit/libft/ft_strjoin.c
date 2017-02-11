/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 12:19:03 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/23 12:24:33 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		ret_index;
	int		s1_index;
	int		s2_index;

	ret_index = 0;
	s1_index = -1;
	s2_index = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2) - 1);
	while (s1[++s1_index])
	{
		ret[ret_index] = s1[s1_index];
		ret_index++;
	}
	while (s2[++s2_index])
	{
		ret[ret_index] = s2[s2_index];
		ret_index++;
	}
	ret[ret_index] = '\0';
	return (ret);
}
