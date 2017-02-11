/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 15:44:07 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/11 08:34:06 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		index;

	argc--;
	index = 0;
	while (argc > 0)
	{
		while (argv[argc][index])
		{
			ft_putchar(argv[argc][index]);
			index++;
		}
		ft_putchar('\n');
		index = 0;
		argc--;
	}
	return (0);
}
