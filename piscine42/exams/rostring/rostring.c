/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 16:19:30 by exam              #+#    #+#             */
/*   Updated: 2015/08/29 16:52:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str)
{
	int		count;
	int		max_len;
	int		words;
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = 0;
	max_len = 1;
	words = 1;
	while (str[count])
	{
		if (str[count] == ' ' || str[count] == '\t' || str[count] == '\n')
		{
			words++;
			if (max_len < (count - max_len))
				max_len = count - max_len;
		}
		count++;
	}

	ret = (char **)malloc(sizeof(char *) * words + 1);
	count = 0;
	while (count <= words)
	{
		ret[count] = (char *)malloc(sizeof(char) * max_len + 1);
		count++;
	}
	count = 0;
	while (str[count])
	{
		if (str[count] != ' ' && str[count] != '\t' && str[count] != '\n')
		{
			ret[j][i] = str[count];
			i++;
			count++;
		}
		else
		{
			while(str[count] == ' ' || str[count] == '\t' || str[count] == '\n')
				count++;
			ret[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	ret[words] = NULL;
	return (ret);
}

void	ft_putstr(char *str)
{
	int		i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (str[i + 1] != ' ' && str[i + 1] != '\t')
				write(1, &str[i], 1);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	**pouet;
	int		i;
	int		j;
	
	i = 1;
	j = 0;
	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		pouet = ft_split(argv[1]);
		
		while (pouet[i] != NULL)
		{
			while (pouet[i][j])
			{
				if (pouet[i][j] != ' ' && pouet [i][j] != '\t')
					write(1, &pouet[i][j], 1);
				j++;
			}
			write(1, " ", 1);
			j = 0;
			i++;
		}

		i = 0;
		while (pouet[0][i])
		{
			if (pouet[0][i] != ' ' && pouet [0][i] != '\t')
				write(1, &pouet[0][i], 1);
			i++;
		}

			
		write(1, "\n", 1);
		free(pouet);
	}
	return (0);
}





