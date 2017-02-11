/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:40:16 by exam              #+#    #+#             */
/*   Updated: 2015/11/24 10:57:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *s)
{
	return (*s ? 1 + ft_strlen(++s) : 0);
}

int		main(int argc, char **argv)
{
	int		index_av1;
	int		index_av2;
	int		ret;

	index_av1 = 0;
	index_av2 = 0;
	ret = 0;
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		while (argv[2][index_av2])
		{
			if (argv[1] != '\0' && (argv[2][index_av2] == argv[1][index_av1]))
			{
				ret++;
				index_av1++;	
			}
			index_av2++;
		}
		if (ret == ft_strlen(argv[1]))
			write(1, "1\n", 2);
		else
			write(1, "0\n", 2);
	}
	return (0);
}
