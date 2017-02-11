/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 14:59:03 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/13 21:51:21 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		i;

	i = -1;
	while (argv[0][++i] && argc != 0)
		ft_putchar(argv[0][i]);
	ft_putchar('\n');
	return (0);
}
