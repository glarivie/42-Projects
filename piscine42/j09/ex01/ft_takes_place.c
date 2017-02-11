/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 18:24:49 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/13 18:54:44 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		h;
	char	*f;

	h = hour;
	f = "THE FOLLOWING TAKES PLACE BETWEEN";
	if (hour > 12)
		h = hour % 12;
	if (hour == 0)
		h = 12;
	if (hour < 11)
		printf("%s %d.00 A.M. AND %d.00 A.M.\n", f, h, (h + 1) % 12);
	else if (hour == 11)
		printf("%s %d.00 A.M. AND %d.00 P.M.\n", f, h, (h + 1));
	else if (hour == 23)
		printf("%s 11.00 P.M. AND 12.00 A.M.\n", f);
	else if (hour == 24)
		printf("%s 12.00 A.M. AND 1.00 A.M.\n", f);
	else
		printf("%s %d.00 P.M. AND %d.00 P.M.\n", f, h, (h + 1) % 12);
}
