/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 16:15:15 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/19 11:06:52 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOP_H
# define FT_DOOP_H

# include <unistd.h>

int		ft_sub(int i, int j)
{
	return (i - j);
}

int		ft_add(int i, int j)
{
	return (i + j);
}

int		ft_mul(int i, int j)
{
	return (i * j);
}

int		ft_div(int	i, int j)
{
	if (j > 0)
		return (i / j);
	if (j == 0)
		write(1, "Stop : division by zero\n", 24);
	else
		return (0);
}

int		ft_mod(int i, int j)
{
	if (j > 0)
		return (i % j);
	if (j == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		return (0);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	unsigned int	digit;
	unsigned int	go_away;
	int				positive;
	int				value;

	value = 0;
	go_away = 0;
	digit = 0;
	while ( *str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	positive = (*str == '-' ? -1 : 1);
	if ( *str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	if ( ft_strlen(str) > 19 )
		return (positive == 1 ? -1 : 0);
	while (ft_isdigit (*str) && *str != '\0')
	{
		digit = (int) (*str - '0');
		value = (value * 10) + digit;
		str++;
	}
	return (value * positive);
}

#endif
