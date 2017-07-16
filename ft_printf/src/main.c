/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 19:45:00 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 18:11:55 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int		original;
	int		my_count;
	int		test;

	test = 42;
	original = printf("qwertyuiopasdfghjklzxcvbnm %d\n", test);
	my_count = ft_printf("qwertyuiopasdfghjklzxcvbnm %d\n", test);
	printf("original: %d\n", original);
	printf("my_count: %d\n", my_count);
	return (0);
}
