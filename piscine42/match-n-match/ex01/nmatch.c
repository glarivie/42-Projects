/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 20:16:39 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 12:49:57 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
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
