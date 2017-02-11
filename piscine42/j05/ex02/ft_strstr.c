/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 11:03:29 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/12 09:44:02 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	to_find_length;

	i = 0;
	j = 0;
	to_find_length = 0;
	while (to_find[to_find_length])
		to_find_length++;
	if (to_find_length == 0)
		return (str);
	while (str[i])
	{
		while (to_find[j] == str[i + j])
		{
			if (j == to_find_length - 1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
