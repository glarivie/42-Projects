/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 10:42:50 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 12:47:15 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_match_count(char *s1, char *s2);

int match(char *s1, char *s2);

int		main(int argc, char **argv)
{
	printf("%d\n", match(argv[1], argv[2]));
	return 0;
}
