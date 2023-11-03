/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 23:39:05 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	file2window(t_v *v)
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

void	window2align(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
	mx_r(mx, v->theta, v->phi, v->psi);
	mx_s(mx, (v->win_h * v->scale) / v->width,
		(v->win_h * v->scale) / v->height, v->scale);
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

void	align2prsptiv(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
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
				+ v->win_w / 2;
			v->points[y][x]->projected->y = v->focal_dist
				* v->points[y][x]->aligned->y
				/ (v->z_max - v->points[y][x]->aligned->z)
				+ v->win_h / 2;
			v->points[y][x]->projected->z = v->points[y][x]->origin->z;
		}
	}
}
