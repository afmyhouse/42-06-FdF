/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 01:24:59 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	file2xyz(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
	mx_t(mx, -v->width / 2, -v->height / 2, 0);
	mx_s(mx, v->x_scale, v->y_scale, v->z_scale);
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
}

void	xyz2align(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
	mx_r(mx, v->theta, v->phi, v->psi);
	mx_s(mx, (v->win_w * v->scale) / v->width,
		(v->win_h * v->scale) / v->width, v->scale);
	if (v->project)
		mx_t(mx, v->x_sh, v->y_sh, v->z_sh);
	else
		mx_t(mx, v->x_sh + v->win_w / 2, v->y_sh + v->win_h / 2, v->z_sh);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			v_mx_mul(v->points[y][x]->world, mx, v->points[y][x]->aligned);
			if (!v->project)
				v->points[y][x]->aligned->z = v->points[y][x]->origin->z;
		}
	}
}

// void	align2prsptiv(t_v *v)
// {
// 	int		y;
// 	int		x;
// 	int		zmax;

// 	zmax = v->z_max;
// 	y = -1;
// 	while (++y < v->height)
// 	{
// 		x = -1;
// 		while (++x < v->width)
// 		{
// 			v->points[y][x]->projected->x
// 				= (float)(v->z_max / (v->scale * v->width)) * v->focal_dist
// 				* v->points[y][x]->aligned->x
// 				/ (v->z_max - v->points[y][x]->aligned->z) + v->win_w / 2;
// 			v->points[y][x]->projected->y
// 				= (float)(v->z_max / (v->scale * v->width)) * v->focal_dist
// 				* v->points[y][x]->aligned->y
// 				/ (v->z_max - v->points[y][x]->aligned->z) + v->win_h / 2;
// 			v->points[y][x]->projected->z = v->points[y][x]->origin->z;
// 		}
// 	}
// 	v->z_max = zmax;
// }
