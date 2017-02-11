/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 18:41:06 by exam              #+#    #+#             */
/*   Updated: 2015/08/14 19:22:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		param1;
	int		param2;
	int		i;

	if (argc != 3)
		printf("\n");
	else
	{
		param1 = atoi(argv[1]);
		param2 = atoi(argv[2]);
		if (param1 < 1 || param2 < 1)
			return (0);
		if (param1 > param2)
			i = param2;
		else
			i = param1;	
		while (i > 0)
		{
			if (param1 % i == 0 && param2 % i == 0)
			{
				printf("%d\n", i);
				return (0);
			}
			i--;
		}
	}	
	return (0);
}
