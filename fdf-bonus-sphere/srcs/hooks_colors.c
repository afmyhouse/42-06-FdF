/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:59 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/05 00:58:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void	create_color_range1(t_v *v, int nc)
{
	int				i;
	float			f;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	// if (MY_DEBUG)
	ft_printf("M-PI %f *******************\n", PI);
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
	printf("v-r = %.1f\n", v->r);
	printf("v-g = %.1f\n", v->g);
	printf("v-b = %.1f\n", v->b);
	f = 0;
	i = -1;
	while (++i < nc)
	{
		r = 255 * (v->r == 0)
			+ (cos(f) * 127 + 127) * (v->r == 1)
			+ (sin(f) * 127 + 127) * (v->r == 2);
		g = 255 * (v->g == 0)
			+ (cos(f) * 127 + 127) * (v->g == 1)
			+ (sin(f) * 127 + 127) * (v->g == 2);
		b = 255 * (v->b == 0)
			+ (cos(f) * 127 + 127) * (v->b == 1)
			+ (sin(f) * 127 + 127) * (v->b == 2);
		v->colors[i] = ((int)r) << 16 | ((int)g) << 8 | b;
		f += (PI / 2) / (float)nc;
	}
	printf("v->num_colors = %d\n", nc);
	v->num_colors = mlx_get_color_value(v->mlx, nc);
	//v->num_colors = colors;
	usleep(UMYTIME * 10);
}

void	create_color_range2(t_v *v, int nc)
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
		//v->colors[nc - i - 1]
		v->colors[i]
			= ((int)rgb[0]) << 16 | ((int)rgb[1]) << 8 | rgb[2];
		f += (PI) / (float)nc;
	}
	v->num_colors = nc;
	usleep(UMYTIME);
}

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
		create_color_range2(v, NUMCOLORS);
	}
	usleep(UMYTIME * 5);
}

// MANDATORY COLOR FUNCTION
// {
// 	int	i;
// 	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
// 	i = -1;
// 	while (++i < nc)
// 		v->colors[i] = WHITE;
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
