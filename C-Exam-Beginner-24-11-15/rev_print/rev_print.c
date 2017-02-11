/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:08:09 by exam              #+#    #+#             */
/*   Updated: 2015/11/24 10:17:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	return (*s ? 1 + ft_strlen(++s) : 0);
}

int		main(int argc, char **argv)
{
	int		index;
	
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		index = ft_strlen(argv[1]);
		while (--index >= 0)
		{
			write(1, &argv[1][index], 1);
		}
		write(1, "\n", 1);
	}
	
	return (0);
}
