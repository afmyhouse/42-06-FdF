/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/31 15:17:50 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	original_to_window(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SCYN, __func__, SWHT);
	sleep(MYTIME);

	//mx_show(mx, "O2W - CREATED");
	mx_id(mx);
	//mx_show(mx, "O2W - IDENTITY");
	//mx_t(mx, -(v->width / 2), -(v->height / 2), 0);
	mx_t(mx, -v->width / 2, -v->height / 2, 0);
	//mx_show(mx, "O2W - TRANSLATED");
	mx_s(mx, v->x_scale, v->y_scale, v->z_scale);
	//mx_show(mx, "O2W - SCALED");
	//vertex_show(v);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			v_mx_mul(v->points[y][x]->origin, mx,
				v->points[y][x]->world);
		}
	}

	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}

void	window_to_aligned(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	//mx_show(mx, "CREATED");
	mx_id(mx);
	//mx_show(mx, "IDENTITY");
	mx_r(mx, v->theta, v->phi, v->psi);
	//mx_show(mx, "ROTATED");
	// mx_s(mx, (WIN_W * v->scale) / v->width,
	// 	(WIN_H * v->scale) / v->height, v->scale);
	mx_s(mx, (WIN_H * v->scale) / v->height,
		(WIN_H * v->scale) / v->height, v->scale);
//	mx_show(mx, "SCALED");
	if (v->project)
	{
		mx_t(mx, v->x_shift, v->y_shift, v->z_shift);
	//	mx_show(mx, "TRANSLATED (PROJECTED)");
	}
	else
	{
		mx_t(mx, v->x_shift + WIN_W / 2, v->y_shift + WIN_H / 2, v->z_shift);
//		mx_show(mx, "TRANSLATED (FLAT)");
	}
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			v_mx_mul(v->points[y][x]->world, mx, v->points[y][x]->aligned);
			//v->points[y][x]->aligned->z = v->project ? v->points[y][x]->aligned->z : v->points[y][x]->local->z;
			if (!v->project)
				v->points[y][x]->aligned->z = v->points[y][x]->origin->z;
		}
	}
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	usleep(UMYTIME);
}

void	aligned_to_projected(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	mx_show(mx, "CREATED");
	mx_id(mx);
	mx_show(mx, "IDENTITY");
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			if (!v->points[y][x]->aligned->z)
				v->points[y][x]->aligned->z = 0.001;
			v->points[y][x]->projected->x = v->focal_dist
				* v->points[y][x]->aligned->x
				/ (v->z_max - v->points[y][x]->aligned->z)
				+ WIN_W / 2;
			v->points[y][x]->projected->y = v->focal_dist
				* v->points[y][x]->aligned->y
				/ (v->z_max - v->points[y][x]->aligned->z)
				+ WIN_H / 2;
			v->points[y][x]->projected->z = v->points[y][x]->origin->z;
		}
	}
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	usleep(UMYTIME);
}
