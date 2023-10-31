/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 19:45:59 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_file2win(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
	mx_t(mx, -v->file_w / 2, -v->file_h / 2, 0);
	mx_s(mx, v->x_scale, v->y_scale, v->z_scale);
	y = -1;
	while (++y < v->file_h)
	{
		x = -1;
		while (++x < v->file_w)
		{
			v_mx_mul(v->points[y][x]->origin, mx,
				v->points[y][x]->world);
		}
	}
}

void	set_win2rts(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
	mx_r(mx, v->theta, v->phi, v->psi);
	mx_s(mx, (v->win_w * v->scale) / v->file_w,
		(v->win_h * v->scale) / v->file_h, v->scale);
	if (v->project)
		mx_t(mx, v->x_shift, v->y_shift, v->z_shift);
	else
		mx_t(mx, v->x_shift + v->win_w / 2, v->y_shift + v->win_h / 2, v->z_shift);
	y = -1;
	while (++y < v->file_h)
	{
		x = -1;
		while (++x < v->file_w)
		{
			v_mx_mul(v->points[y][x]->world, mx, v->points[y][x]->aligned);
			if (!v->project)
				v->points[y][x]->aligned->z = v->points[y][x]->origin->z;
		}
	}
}

void	set_rts2screen(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
	y = -1;
	while (++y < v->file_h)
	{
		x = -1;
		while (++x < v->file_w)
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
}
