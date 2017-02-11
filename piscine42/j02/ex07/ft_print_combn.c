/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 14:48:40 by glarivie          #+#    #+#             */
/*   Updated: 2015/09/10 14:49:49 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_putchar(char c);

void    ft_do_print_combn(int nb, int n)
{
        int     decimal;
        int     i;

        decimal = ten_powern(n - 1);
        i = n;
        while (i)
        {
                ft_putchar(((nb % (decimal * 10)) / decimal) + 48);
                i = i - 1;
                decimal = decimal / 10;
        }
        if ((nb != 9 && n == 1) || (nb != 89 && n == 2) || (nb != 789 && n == 3)
            || (nb != 6789 && n == 4) || (nb != 56789 && n == 5)
            || (nb != 456789 && n == 6) || (nb != 3456789 && n == 7)
            || (nb != 23456789 && n == 8) || (nb != 123456789 && n == 9))
        {
        	ft_putchar(',');
        	ft_putchar(' ');
        }
}

int     ten_powern(int n)
{
        int     result;

        result = 1;
        while (n)
        {
                result = result * 10;
                n = n - 1;
        }
        return (result);
}

int     ft_is_comb(int nb, int n)
{
        int     decimal;
        int     i;

        decimal = 10;
        i = n - 1;
        while (i)
        {
                if ((nb % decimal) / (decimal / 10)
                    <= nb % (decimal * 10) / decimal)
                {
                        return (0);
                }
                i = i - 1;
                decimal = decimal * 10;
        }
        ft_do_print_combn(nb, n);
        return (0);
}

void    ft_print_combn(int n)
{
        int     i;
        int     decimal;

        i = 0;
        decimal = ten_powern(n);
        while (i < decimal)
        {
                ft_is_comb(i, n);
                i = i + 1;
        }
        ft_putchar('\n');
}
