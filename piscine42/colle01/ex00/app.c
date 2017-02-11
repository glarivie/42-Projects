/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 11:25:09 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/15 20:26:00 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_sudoku(char **argv, int grid[9][9])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 9)
	{
		while (i < 9)
		{
			if (argv[j + 1][i] == '.')
				grid[j][i] = '0';
			else
				grid[j][i] = (int)argv[j + 1][i];
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_print_sudoku(int	grid[9][9])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 9)
	{
		while (i < 9)
		{
			write(1, &grid[j][i], 1);
			if (i != 8)
				write(1, " ", 1);
			i++;
		}
		i = 0;
		j++;
		write(1, "\n", 1);		
	}
}

int		ft_check_entries(int argc)
{
	if (argc != 10)
	{
		write(1, "Sudoku has 9 lines\n", 19);
		return (-1);
	}
	else
		return (0);
}
