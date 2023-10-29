/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:59 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/29 22:53:47 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	create_color_range(t_v *v, int nc)
{
	int				i;
	float			f;
	int				m;
	unsigned char	rgb[3];

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

// void	create_color_range3(t_v *v, int nc)
// {
// 	int				i;
// 	float			f;
// 	int				m;
// 	int				n;
// 	unsigned char	rgb[3];

// 	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
// 	f = 0;
// 	i = -1;
// 	m = 127;
// 	n = 255;
// 	while (++i < nc)
// 	{
// 		rgb[0] = (i * n / nc) * (v->r == 0)
// 			+ (((nc - i) * m / nc) + m) * (v->r == 1)
// 			+ (sin(f) + 1) * m * (v->r == 2);
// 		rgb[1] = (i * n / nc) * (v->g == 0)
// 			+ (((nc - i) * m / nc) + m) * (v->g == 1)
// 			+ (sin(f) + 1) * m * (v->g == 2);
// 		rgb[2] = (i * n / nc) * (v->b == 0)
// 			+ (((nc - i) * m / nc) + m) * (v->b == 1)
// 			+ (cos(f) + 1) * m * (v->b == 2);
// 		v->colors[nc - i - 1] = ((int)rgb[0]) << 16 | ((int)rgb[1]) << 8 | rgb[2];
// 		f += (PI / 2) / (float)nc;
// 	}
// 	v->num_colors = nc;
// 	usleep(UMYTIME);
// }

// void	create_color_range1(t_v *v, int nc)
// {
// 	int				i;
// 	float			f;
// 	int				m;
// 	int				n;
// 	unsigned char	rgb[3];

// 	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
// 	f = 0;
// 	i = -1;
// 	m = 127;
// 	n = 255;
// 	while (++i < nc)
// 	{
// 		rgb[0] = n * (v->r == 1)
// 			+ ((sin(f) * m) + m) * (v->r == 0) + (cos(f) * m + m) * (v->r == 2);
// 		rgb[1] = sin(f) * n * (v->g == 1)
// 			+ ((sin(f) * m) + m) * (v->g == 0) + (cos(f) * m + m) * (v->g == 2);
// 		rgb[2] = cos(f / 2) * n * (v->b == 1)
// 			+ ((sin(f) * m) + m) * (v->b == 0) + (cos(f) * m + m) * (v->b == 2);
// 		v->colors[nc - i- 1] = ((int)rgb[0]) << 16 | ((int)rgb[1]) << 8 | rgb[2];
// 		f += (PI / 2) / (float)nc;
// 	}
// 	v->num_colors = nc;
// 	usleep(UMYTIME);
// }

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

