/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 17:23:02 by exam              #+#    #+#             */
/*   Updated: 2015/08/14 18:08:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		while (argv[1][i])
		{
			if (argv[1][i] > 64 && argv[1][i] < 91)
			{
				if ((argv[1][i] + 13) > 90)
					argv[1][i] = 13 - (91 - argv[1][i]) + 65;
				else
					argv[1][i] = argv[1][i] + 13;
			}
			if (argv[1][i] > 96 && argv[1][i] < 123)
			{
				if ((argv[1][i] + 13) > 122)
					argv[1][i] = 13 - (123 - argv[1][i]) + 97;
				else
					argv[1][i] = argv[1][i] + 13;
			}
			i++;
		}
		ft_putstr(argv[1]);
	}
	return (0);
}
