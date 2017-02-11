/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 17:35:10 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 21:21:50 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

char	*ft_read(unsigned long long ret2)
{
	int		fd2;
	int		ret;
	char	*buf;

	ret = 0;
	buf = (char *)malloc(sizeof(char) * ret2);
	fd2 = open("swap", O_RDONLY);
	ret = read(fd2, buf, ret2);
	close(fd2);
	return (buf);
}
