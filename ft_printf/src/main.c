/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 19:45:00 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 13:58:40 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
  int original;
  int my_count;
  char *test;

  test = ft_strnew(sizeof(char) * 6);
  test = "hello";

  original = printf("helloytertertoertjertejrterjteijrtej\n");
  my_count = ft_printf("helloytertertoertjertejrterjteijrtej\n");

  printf("original: %d\n", original);
  printf("my_count: %d\n", my_count);

  return 0;
}
