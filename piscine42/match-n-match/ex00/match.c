/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 20:16:39 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/16 13:16:06 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_match_count(char *s1, char *s2)
{
	if (s2[0] == '*')
	{
		if (s1[0])
			return (ft_match_count((s1 + 1), s2) + ft_match_count(s1, (s2 + 1)));
		if (!(s1[0]))
			return (ft_match_count(s1, (s2 + 1)));
	}
	if (s1[0] == s2[0])
	{
		if (s1[0])
			return (ft_match_count((s1 + 1), (s2 + 1)));
		if (!(s1[0]))
			return (1);
	}
	return (0);
}

int		match(char *s1, char *s2)
{
	if (ft_match_count(s1, s2) >= 1)
		return (1);
	else
		return (0);
}
