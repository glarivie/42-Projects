/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:07:28 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/06 19:12:36 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_putchar(char c);

int	ft_int_length(int nb)
{
	int	length;
	int	div;

	length = 0;
	div = 1;
	while ((nb / div) != 0)
	{
		length++;
		div = div * 10;
	}
	return (length);
}

void	ft_putnbr(int nb)
{
	int	length;
	int	div;

	length = ft_int_length(nb);
	div = 1;
	while (--length > 0)
		div = div * 10;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	while (div > 0)
	{
		ft_putchar(nb / div % 10 + '0');
		div = div / 10;
	}
}
