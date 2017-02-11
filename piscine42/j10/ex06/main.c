/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 17:55:15 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/19 11:04:48 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	
	
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		i = ft_atoi(argv[1]);
		j = ft_atoi(argv[3]);
		if (argv[2][0] == '-')
			ft_putnbr(ft_sub(i, j));
		if (argv[2][0] == '+')
			ft_putnbr(ft_add(i, j));
		if (argv[2][0] == '*')
			ft_putnbr(ft_mul(i, j));
		if (argv[2][0] == '/')
			ft_putnbr(ft_div(i, j));
		if (argv[2][0] == '%')
			ft_putnbr(ft_mod(i, j));
		else
			ft_putnbr(0);
	}
	return (0);
}
