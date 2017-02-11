/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 16:20:55 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/11 15:33:54 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;
	int b;

	i = 1;
	b = 0;
	while (i <= nb)
	{
		if (nb % i == 0)
			b++;
		i++;
	}
	if (b == 2)
		return (1);
	return (0);
}