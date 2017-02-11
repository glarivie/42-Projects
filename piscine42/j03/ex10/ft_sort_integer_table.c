/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 18:16:17 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/10 18:17:26 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_sort_integer_table(int *tab, int size)
{
	int	index;
	int	temp;

	index = 0;
	while (index < size)
	{
		if (tab[index] > tab[index + 1])
		{
			temp = tab[index + 1];
			tab[index + 1] = tab[index];
			tab[index] = temp;
			index = 0;
		}
		else
			index++;
	}
}
