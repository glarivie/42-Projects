/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 16:07:40 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/27 22:38:20 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

void		ft_print_bsq(char **bsq, t_bsq_data data);
void		ft_free_bsq(char **bsq, t_bsq_data data);
int			ft_isspace(char *str);
int			ft_atoi(char *str);
int			ft_get_swap(int index, char **av);
char		*ft_read(unsigned long long ret2);
t_bsq_data	ft_get_infos(char *buf, unsigned long long ret2);
char		**ft_get_bsq(t_bsq_data data, char *buf);
t_bool		ft_check_map(char **bsq, t_bsq_data data);
t_coord		ft_check_tab(char **tab, t_bsq_data data);
int			ft_check_square(char **tab, t_bsq_data data, t_coord coord);
int			ft_sqrt(int nb);
char		**ft_fill_square(char **tab, t_bsq_data data, t_coord coord);
void		ft_loop_bsq(int ac, char **av);
void		ft_wait_args(void);

#endif
