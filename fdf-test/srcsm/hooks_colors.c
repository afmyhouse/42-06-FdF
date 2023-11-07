/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:59 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 22:27:01 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	create_color_range1(t_v *v, int nc, int ic, int fc)
{
	int				i;
	float			f;
	unsigned char	rgb[3];

	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
	f = 0;
	i = -1;
	while (++i < nc)
	{
		rgb[0] = ft_min(get_r_c(ic), get_r_c(fc))
			+ ((unsigned char)ft_abs(get_r_c(ic) - get_r_c(fc)))
			* ((get_r_c(ic) < get_r_c(fc)) * (sin(f))
				+ ((get_r_c(ic) >= get_r_c(fc)) * cos(f)));
		rgb[1] = ft_min(get_g_c(ic), get_g_c(fc))
			+ ((unsigned char)ft_abs(get_g_c(ic) - get_g_c(fc)))
			* ((get_g_c(ic) < get_g_c(fc)) * (sin(f))
				+ ((get_g_c(ic) >= get_g_c(fc)) * cos(f)));
		rgb[2] = ft_min(get_b_c(ic), get_b_c(fc))
			+ ((unsigned char)ft_abs(get_b_c(ic) - get_b_c(fc)))
			* ((get_b_c(ic) < get_b_c(fc)) * (sin(f))
				+ ((get_b_c(ic) >= get_b_c(fc)) * cos(f)));
		f += (PI / 2) / (float)nc;
		v->colors[i] = ((int)rgb[0]) << 16 | ((int)rgb[1]) << 8 | rgb[2];
	}
	v->num_colors = nc;
}

void	create_color_range(t_v *v, int nc)
{
	create_color_range1(v, nc, LIGHTGRAY, LIGHTSKYBLUE);
	usleep(UMYTIME);
}
