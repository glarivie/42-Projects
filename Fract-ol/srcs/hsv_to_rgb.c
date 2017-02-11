/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:42:59 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 08:43:03 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					hsv_to_rgb(int h, int s, int v)
{
	unsigned char			region;
	unsigned char			remainder;
	unsigned char			p;
	unsigned char			q;
	unsigned char			t;

	if (s == 0)
		return (rgb_to_int(v, v, v));
	region = h / 43;
	remainder = (h - (region * 43)) * 6;
	p = (v * (255 - s)) >> 8;
	q = (v * (255 - ((s * remainder) >> 8))) >> 8;
	t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;
	if (region == 0)
		return (rgb_to_int(v, t, p));
	else if (region == 1)
		return (rgb_to_int(q, v, p));
	else if (region == 2)
		return (rgb_to_int(p, v, t));
	else if (region == 3)
		return (rgb_to_int(p, q, v));
	else if (region == 4)
		return (rgb_to_int(t, p, v));
	else
		return (rgb_to_int(v, p, q));
}
