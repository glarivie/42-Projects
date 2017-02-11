/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 18:17:48 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/06 21:34:05 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_add_comma(int count[2])
{
	if (count[0] == 98 && count[1] == 99)
	{
		ft_putchar(count[0] / 10 + 48);
		ft_putchar(count[0] % 10 + 48);
		ft_putchar(' ');
		ft_putchar(count[1] / 10 + 48);
		ft_putchar(count[1] % 10 + 48);
	}
	else
	{
		ft_putchar(count[0] / 10 + 48);
		ft_putchar(count[0] % 10 + 48);
		ft_putchar(' ');
		ft_putchar(count[1] / 10 + 48);
		ft_putchar(count[1] % 10 + 48);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int count[2];

	count[0] = 0;
	while (count[0] <= 98)
	{
		count[1] = count[0] + 1;
		while (count[1] <= 99)
		{
			ft_add_comma(count);
			count[1]++;
		}
		count[0]++;
	}
}
