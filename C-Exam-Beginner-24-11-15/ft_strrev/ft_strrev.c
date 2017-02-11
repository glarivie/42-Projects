/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:20:35 by exam              #+#    #+#             */
/*   Updated: 2015/11/24 10:38:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *s)
{
	return (*s ? 1 + ft_strlen(++s) : 0);
}

char	*ft_strrev(char *str)
{
	int		index;
	int		len;
	char	tmp;

	index = 0;
	len = ft_strlen(str) - 1;
	while (index <= len)
	{
		tmp = str[index];
		str[index] = str[len];
		str[len] = tmp;
		index++;
		len--;
	}
	return (str);
}
