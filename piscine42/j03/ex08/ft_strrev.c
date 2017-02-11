/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 11:17:41 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/07 13:50:26 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*fr_strrev(char *str)
{
	int	index;
	char	temp;
	int	length;
	
	index = 0;
	length = ft_strlen(str) - 1;
	while (index < length)
	{
		temp = str[length];
		str[length] = str[index];
		str[index] = temp;
		index++;
		length--;
	}
	return (str);
}
