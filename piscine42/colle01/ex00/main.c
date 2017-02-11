/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 11:25:16 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/15 20:25:12 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_entries(int argc);
void	ft_init_sudoku(char **argv, int grid[9][9]);
void    ft_print_sudoku(int grid[9][9]);

int		main(int argc, char **argv)
{
	ft_check_entries(argc);

	int		sudoku[9][9];
	ft_init_sudoku(argv, sudoku);	
	ft_print_sudoku(sudoku);

	return (0);
}
