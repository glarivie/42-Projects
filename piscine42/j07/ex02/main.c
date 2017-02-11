/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 13:17:40 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/13 14:16:32 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int *ft_range(int min, int max);
int ft_ultimate_range(int **range, int min, int max);

int main()
{
	int		**test;	
	
	printf("%d\n", ft_ultimate_range(test, 4, 9));
		
	
	return 0;
}
