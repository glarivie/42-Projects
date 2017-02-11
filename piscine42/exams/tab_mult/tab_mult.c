/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 12:02:27 by exam              #+#    #+#             */
/*   Updated: 2015/08/29 14:09:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 1;
	ret = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	i = i - 1;
	while (i >= 0)
	{
		ret += (str[i] - '0') * j;
		i--;
		j = j * 10;
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	char	i;
	int		j;
	int		ret;
	char	ret1;
	int		multi;
	int		mod;
	int		k;
	int		test;

	test = 0;
	mod = 1000000000;
	i = '1';
	j = 1;
	k = 0;
	ret = 0;
	multi = 0;
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		multi = ft_atoi(argv[1]);
		while (argv[1][k])
			k++;
		while (i <= '9')
		{
			ret = (j * multi);
			write(1, &i, 1);
			write(1, " x ", 3);
			write(1, argv[1], k);
			write(1, " = ", 3);

			while (mod > 0)
			{
				if (ret >= 0)
				{
					ret1 = (ret / mod) + '0';
					if (ret1 != '0')
						test++;
					if (test > 0)
						write(1, &ret1, 1);
					ret = (ret - (ret / mod) * mod);
				}
				mod = mod / 10;
			}
			mod = 1000000000;
			test = 0;
			write(1, "\n", 1);
			i++;
			j++;
		}
	}
	return (0);
}
