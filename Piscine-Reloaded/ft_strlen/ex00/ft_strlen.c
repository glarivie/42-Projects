/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:10:23 by glarivie          #+#    #+#             */
/*   Updated: 2016/10/28 22:26:00 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	// if (str == NULL)
	// 	return 0;
	return str != NULL ? 1 + ft_strlen(*str ? str + 1 : NULL) : -1;
}
