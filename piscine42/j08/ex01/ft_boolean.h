/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 10:42:25 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/17 11:44:47 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN(x) (((x) % 2) == 0)
# define EVEN_MSG "I have a pair number of arguments.\n"
# define ODD_MSG "I have an impair of arguments.\n"

typedef int		t_bool;

#endif
