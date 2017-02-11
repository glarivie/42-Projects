/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 09:28:44 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/08 17:53:47 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	sastantua(int size)
{
	/* drawing ASCII code */
	int		star;
	int		right_slash;
	int		left_slash;

	star = 42;
	right_slash = 47;
	left_slash = 92;

	/* size --> floors number */
	
	int		floor_index[size];

	int i = 0;
	while (i < size)
	{
		floor_index[i] = i;
		i++;
	}

	/* total lignes */
	int j = 0;
	int total_lignes = 0;
	while (j < size)
	{
		total_lignes = total_lignes + floor_index[j] + 3;
		j++;
	}

	/* lignes par etages */
	int k;
	int		floors_lines[size];
	k = 0;	
	while (k < floor_index[size])
	{
		floors_lines[k] = floor_index[k] + 3;
		k++;
	}
	
	/* DRAW THIS FUCKING PYRAMID ! */
	int count_floor = 0;
	int count_stars;
	int nbr_stars = 1;

	while (count_floor < floors_lines[floor_index[count_floor]])
	{
		count_stars = 1;
		ft_putchar(right_slash);
		while (count_stars <= nbr_stars)
		{
			ft_putchar(star);
			count_stars++;
		}
		ft_putchar(left_slash);
		nbr_stars = nbr_stars + 2;
		count_floor++;
	}
	
}




int		main(void)
{
	sastantua(5);
	return	(0);
}
