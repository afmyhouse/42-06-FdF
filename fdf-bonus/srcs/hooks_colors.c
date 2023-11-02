/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:59 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 22:38:03 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	create_color_range(t_v *v, int nc)
{
	int				i;
	float			f;
	int				m;
	unsigned char	rgb[3];

	if (v->colors)
	{
		free(v->colors);
		v->colors = NULL;
	}
	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
	f = 0;
	i = -1;
	m = 127;
	while (++i < nc)
	{
		rgb[2] = (cos(f) + v->r) * m;
		rgb[0] = (sin(f) + v->g) * m;
		rgb[1] = (-cos(f) + v->b) * m;
		v->colors[i] = ((int)rgb[0]) << 16 | ((int)rgb[1]) << 8 | rgb[2];
		f += (PI / 2) / (float)nc;
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
	usleep(UMYTIME);
}

// MANDATORY COLOR FUNCTION
// {
// 	int	i;
// 	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
// 	i = -1;
// 	while (++i < nc)
// 		v->colors[i] = FDFCOLOR;
// }

// void	color_hook(t_v *v)
// {
// 	if (v->keys->c)
// 		create_color_range(v, NUMCOLORS);
// }

void	keys_color_status(int kc, t_v *v, int kt)
{
	if (kc == KEY_C)
	{
		v->keys->c = kt;
		v->keys->status = kt;
	}
}
