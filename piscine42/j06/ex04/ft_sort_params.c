/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:02:25 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 09:10:14 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_array_compare(char *ar1, char *ar2)
{
	int		i;

	i = 0;
	while (ar1[i] || ar2[i])
	{
		if (ar1[i] != ar2[i])
			return (ar1[i] - ar2[i]);
		i++;
	}
	return (0);
}

void	ft_array_swap(char *ar1, char *ar2)
{
	char	*ar3;

	ar3 = ar1;
	ar1 = ar2;
	ar2 = ar3;
}

void	ft_array_print(char *ar)
{
	int		i;

	i = -1;
	while (ar[++i])
		ft_putchar(ar[i]);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (j < argc)
	{
		while (ft_array_compare(argv[i], argv[i + 1]) < 0)
		{
			ft_array_swap(argv[i], argv[i + 1]);
			i++;
		}
		j++;
	}
	i = 0;
	while (argv[++i])
		ft_array_print(argv[i]);
	return (0);
}
