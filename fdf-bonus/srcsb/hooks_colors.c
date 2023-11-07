/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:59 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/07 09:51:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	colors_groups(t_v *v)
{
	int		colors[9][2];
	int		i;

	colors[0][0] = 0x20002C;
	colors[0][1] = 0xCBB4D4;
	colors[1][0] = 0x34E89E;
	colors[1][1] = 0x0F3443;
	colors[2][0] = 0x0575E6;
	colors[2][1] = 0x021B79;
	colors[3][0] = 0x43C6AC;
	colors[3][1] = 0x191654;
	colors[4][0] = 0x43c6ac;
	colors[4][1] = 0xf8ffae;
	colors[5][0] = 0xC0C0AA;
	colors[5][1] = 0x1CEFFF;
	colors[6][0] = 0xDBE6F6 ;
	colors[6][1] = 0xC5796D;
	colors[7][0] = 0x868F96;
	colors[7][1] = 0x596164;
	colors[8][0] = 0x30E8BF;
	colors[8][1] = 0xFF8235;
	i = rand() % 9;
	v->icolor = colors[i][0];
	v->fcolor = colors[i][1];
}

unsigned char	get_color(t_v *v, float a, unsigned char (*f)(int))
{
	unsigned char	color;

	color = ft_min(f(v->icolor), f(v->fcolor))
		+ ((unsigned char)ft_abs(f(v->icolor) - f(v->fcolor)))
		* ((f(v->icolor) < f(v->fcolor)) * (sin(a))
			+ ((f(v->icolor) >= f(v->fcolor)) * cos(a)));
	return (color);
}

void	create_color_range(t_v *v, int nc)
{
	int				i;
	float			f;
	unsigned char	rgb[3];

	colors_groups(v);
	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
	f = 0;
	i = -1;
	while (++i < nc)
	{
		rgb[0] = get_color(v, f, get_r_c);
		rgb[1] = get_color(v, f, get_g_c);
		rgb[2] = get_color(v, f, get_b_c);
		f += (PI / 2) / (float)nc;
		v->colors[i] = ((int)rgb[0]) << 16 | ((int)rgb[1]) << 8 | rgb[2];
	}
	v->num_colors = nc;
}

void	color_hook(t_v *v)
{
	if (v->keys->c)
		create_color_range(v, NUMCOLORS);
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
