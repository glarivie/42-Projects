/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 18:33:31 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 19:27:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		while (i < argc)
		{
			while (argv[i][j])
			{
				if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
					argv[i][j] += 32;
				j++;
			}
			j = 0;
			i++;	
		}

		i = 1;
		j = 0;
		while (i < argc)
		{
			while (argv[i][j])
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				{
					if ((j == 0)
							|| (argv[i][j - 1] == '\t')
							|| (argv[i][j - 1] == ' '))
						argv[i][j] -= 32;
				}
				j++;
			}
			j = 0;
			i++;
		}

		i = 1;
		j = 0;
		while (i < argc)
		{
			while (argv[i][j])
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			j = 0;
			i++;
			write(1, "\n", 1);
		}
	}
	return (0);
}
