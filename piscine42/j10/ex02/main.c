/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:44:07 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/18 14:59:24 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int     *ft_map(int *tab, int length, int (*f)(int));

int		plus_un(int nb)
{
	return (nb + 1);
}

int		main(void)
{
	int		test[5] = {0, 1, 2, 3, 4};
	int		*ptr_test;
	ptr_test = test;
	int		*test2;
	test2 = ft_map(test, 5, &plus_un);

	int i = 0;
	while (i < 5)
	{
		printf("%d \n", test2[i]);

		i++;
	}
	return 0;
}
