/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 00:21:32 by antoda-s         ###   ########.fr       */
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

	// printf("worl 2 align -------------------------------------------------\n");
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

void	align2prsptiv(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	int		zmax;

	zmax = v->z_max;
	mx_id(mx);
		y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			v->points[y][x]->projected->x
				= (float)(v->z_max / (v->scale * v->width)) * v->focal_dist
				* v->points[y][x]->aligned->x
				/ (v->z_max - v->points[y][x]->aligned->z) + v->win_w / 2;
			v->points[y][x]->projected->y
				= (float)(v->z_max / (v->scale * v->width)) * v->focal_dist
				* v->points[y][x]->aligned->y
				/ (v->z_max - v->points[y][x]->aligned->z) + v->win_h / 2;
			v->points[y][x]->projected->z = v->points[y][x]->origin->z;
		}
	}
	v->z_max = zmax;
}

void	align2prsptiv_original(t_v *v)
{
	//float	mx[4][4];
	int		y;
	int		x;

	//mx_id(mx);
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
			v->points[y][x]->projected->z = v->points[y][x]->aligned->z;
		}
	}
}

//void	align2prsptiv(t_v *v)
void	align2sphere(t_v *v)
{
	//float	mx[4][4];
	float	r;
	int		y;
	int		x;

	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			r = v->points[y][x]->aligned->z - v->z_min;
			if (v->z_max - v->z_min)
				r /= (float)(v->z_max - v->z_min);
			//r += 1.0;
			v->theta = v->points[y][x]->aligned->x / (float)(v->z_max - v->z_min) * PI2;
			v->phi = v->points[y][x]->aligned->y / (float)(v->z_max - v->z_min) * PI * -1.0;
			v->points[y][x]->projected->x = v->points[y][x]->aligned->x * r * cos(v->theta) * sin(v->phi) + v->width;
			v->points[y][x]->projected->y = v->points[y][x]->aligned->y * r * sin(v->theta) * sin(v->phi) + v->height;
			v->points[y][x]->projected->z = v->points[y][x]->aligned->z * r * cos(v->phi);
			printf("aligned   => x: %f, y: %f, z: %f\n", v->points[y][x]->aligned->x,
				v->points[y][x]->aligned->y, v->points[y][x]->aligned->z);
			printf("projected => x: %f, y: %f, z: %f\n", v->points[y][x]->projected->x,
				v->points[y][x]->projected->y, v->points[y][x]->projected->z);
		}
	}
}
