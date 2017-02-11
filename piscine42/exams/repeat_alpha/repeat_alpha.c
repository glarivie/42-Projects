/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 10:08:18 by exam              #+#    #+#             */
/*   Updated: 2015/08/29 10:19:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				j = argv[1][i] - 65;
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				j = argv[1][i] - 97;
			else
				j = 0;
			while (j >= 0)
			{
				write(1, &argv[1][i], 1);
				j--;
			}
			i++;
		}
		write(1, "\n", 1);
	}
	
	
	return (0);
}
