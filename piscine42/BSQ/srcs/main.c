/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 11:45:49 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 23:01:03 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "func.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_wait_args();
	else
		ft_loop_bsq(argc, argv);
	return (EXIT_SUCCESS);
}
