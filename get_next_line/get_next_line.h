/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:38:06 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/29 10:56:45 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 32
# define ERR -1

typedef	struct		s_fd
{
	int				fd;
	char			*lne;
	struct s_fd		*nxt;
	struct s_fd		*srt;
}					t_fd;

int					get_next_line(int const fd, char **line);

#endif
