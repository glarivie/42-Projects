/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 17:55:28 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/13 18:04:00 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c);
void ft_putstr(char *str);
char *ft_concat_params(int argc, char **argv);

int main(int argc, char **argv)
{
	ft_putstr(ft_concat_params(argc, argv));
	return (0);
}
