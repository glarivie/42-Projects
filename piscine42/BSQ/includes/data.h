/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 15:47:58 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 16:22:55 by pgorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define BUFFER 4096

typedef int		t_bool;

typedef struct	s_bsq_data
{
	char	empty;
	char	block;
	char	sqr_px;
	int		lines;
	int		columns;
}				t_bsq_data;

typedef struct	s_coord
{
	int		x;
	int		y;
	int		x_max;
	int		y_max;
	int		ref;
}				t_coord;

#endif
