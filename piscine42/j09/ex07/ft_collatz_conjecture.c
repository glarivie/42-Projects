/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 10:07:45 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/14 10:31:36 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if ((base % 2) == 0)
		return (ft_collatz_conjecture(base / 2));
	if ((base % 2) != 0)
		return (ft_collatz_conjecture((3 * base) + 1));
}
