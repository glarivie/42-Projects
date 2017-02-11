/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 16:20:55 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/11 21:52:55 by glarivie         ###   ########.fr       */
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

int		ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
