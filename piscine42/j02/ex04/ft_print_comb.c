/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 15:31:04 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/07 22:44:44 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int count[3];

	count[0] = '0';
	while (count[0] <= '7')
	{
		count[1] = count[0] + 1;
		while (count[1] <= '8')
		{
			count[2] = count[1] + 1;
			while (count[2] <= '9')
			{
				ft_putchar(count[0]);
				ft_putchar(count[1]);
				ft_putchar(count[2]);
				if (count[0] != '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				count[2]++;
			}
			count[1]++;
		}
		count[0]++;
	}
}
