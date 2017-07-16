/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:35:44 by glarivie          #+#    #+#             */
/*   Updated: 2017/07/16 18:46:49 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_strnew(size));
	if (!size)
		return (ptr);
	new_ptr = ft_strnew(size);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}
