/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 21:54:18 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/11 22:02:04 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_find_next_prime(int nb);

int		main(void)
{
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(1));
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(4));
	printf("%d\n", ft_find_next_prime(14));
	printf("%d\n", ft_find_next_prime(43783));
	printf("%d\n", ft_find_next_prime(43784));
	printf("%d\n", ft_find_next_prime(11214));
	return (0);
}
