/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/07 00:56:54 by antoda-s         ###   ########.fr       */
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
	mx_s(mx, v->xsc, v->ysc, v->zsc);
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
		mx_t(mx, v->xsh, v->ysh, v->zsh);
	else
		mx_t(mx, v->xsh + v->win_w / 2, v->ysh + v->win_h / 2, v->zsh);
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
