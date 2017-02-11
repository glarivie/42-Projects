/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:13:49 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/18 11:32:44 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_read(char **av, int index)
{
	int					fd;
	unsigned long long	rd;
	char				*tab;

	if (!(tab = (char *)malloc(sizeof(char) * BUFFER)))
		return (NULL);
	if (!(fd = open(av[index], O_RDONLY)))
		return (NULL);
	if (!(rd = read(fd, tab, BUFFER)))
		return (NULL);
	close(fd);
	return (tab);
}
