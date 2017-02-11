/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 21:31:14 by glarivie          #+#    #+#             */
/*   Updated: 2016/10/28 22:25:06 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);

int		main(void) {
	int		len;
	char	*test;


	test = "hello";
	len = ft_strlen(test);

	printf("%d\n", len);

	return (0);
}
