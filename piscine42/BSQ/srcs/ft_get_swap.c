/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 17:33:19 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:21:05 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

int		ft_get_swap(int index, char **av)
{
	int						fd;
	int						fd2;
	int						ret;
	unsigned long long		ret2;
	char					buf[BUFFER];

	ret = 0;
	ret2 = 0;
	fd = open("swap", O_RDWR | O_TRUNC | O_CREAT, 0777);
	fd2 = open(av[index], O_RDONLY);
	while ((ret = read(fd2, buf, BUFFER)))
	{
		ret2 += write(fd, buf, ret);
	}
	close(fd);
	close(fd2);
	return (ret2);
}
