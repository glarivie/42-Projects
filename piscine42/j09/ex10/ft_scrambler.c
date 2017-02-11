/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 13:03:29 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/14 13:15:55 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int		a_copy;
	int		b_copy;
	int		c_copy;
	int		d_copy;

	a_copy = ***a;
	b_copy = *b;
	c_copy = *******c;
	d_copy = ****d;
	*******c = a_copy;
	****d = c_copy;
	*b = d_copy;
	***a = b_copy;
}
