/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:59 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/07 01:46:09 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	create_color_range(t_v *v, int nc)
{
	int				i;
	float			f;
	unsigned char	rgb[3];

	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
	f = 0;
	i = -1;
	while (++i < nc)
	{
		rgb[0] = (i * 255 / nc) * (v->r == 0)
			+ (((nc - i) * 127 / nc) + 127) * (v->r == 1)
			+ (sin(f) + 1) * 127 * (v->r == 2);
		rgb[1] = (i * 127 / nc) * (v->g == 0)
			+ (((nc - i) * 127 / nc) + 127) * (v->g == 1)
			+ (sin(f) + 1) * 127 * (v->g == 2);
		rgb[2] = (i * 255 / nc) * (v->b == 0)
			+ (((nc - i) * 127 / nc) + 127) * (v->b == 1)
			+ (cos(f) + 1) * 127 * (v->b == 2);
		v->colors[i]
			= ((int)rgb[0]) << 16 | ((int)rgb[1]) << 8 | rgb[2];
		f += (PI) / (float)nc;
	}
	v->num_colors = nc;
	usleep(UMYTIME);
}

void	color_hook(t_v *v)
{
	if (v->keys->c)
	{
		v->r = rand() % 3;
		v->g = rand() % 3;
		v->b = rand() % 3;
		create_color_range(v, NUMCOLORS);
	}
	usleep(UMYTIME * 5);
}


void	keys_color_status(int kc, t_v *v, int kt)
{
	if (kc == KEY_C)
	{
		v->keys->c = kt;
		v->keys->status = kt;
	}
}
