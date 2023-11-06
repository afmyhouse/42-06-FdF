/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 00:20:09 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_scale(t_v *v)
{
	if (v->width >= v->height && v->z_max > v->width)
	{
		v->scale = 0.8 * (float)v->width / (2 * v->z_max);
	}
	else if (v->width < v->height && v->z_max > (v->height))
	{
		v->scale = 0.8 * (float)v->height / (2 * v->z_max);
	}
	else if (v->width >= v->height && v->width >= v->z_max)
	{
		v->scale = 0.8 * (float)v->width / (v->z_max + v->width);
	}
	else if (v->width < v->height && v->z_max <= v->height)
	{
		v->scale = 0.8 * (float)v->height / (v->z_max + v->height);
	}
}

void	init_iso(t_v *v)
{
	v->theta = U45DEG;
	v->phi = -UISOXRAD;
	v->psi = U30DEG;
	v->i_alfa = DEG2RAD_1 * 10;
	v->x_scale = 1.0;
	v->y_scale = 1.0;
	v->z_scale = 1.0;
	set_scale(v);
	v->scale /= (float)1.73;
	v->i_scale = USCALE * v->width / 100;
	v->max_scale = USCALE_UL_ALIGN;
	v->x_sh = 0.0;
	v->y_sh = 0.0;
	v->z_sh = 0.0;
	v->i_shift = USHIFT * v->width / 10;
	v->focal_dist = 3;
	v->r = 1;
	v->g = 1;
	v->b = 1;
	v->caption = "Isometric";
}

void	init_flat(t_v *v)
{
	v->caption = "Parallel";
	v->theta = 0.0;
	v->phi = 0.0;
	v->psi = 0.0;
	v->i_alfa = UALFA;
	v->x_scale = 1.0;
	v->y_scale = (float)v->x_scale * v->win_w / v->win_h;
	v->z_scale = 1.0;
	set_scale(v);
	v->i_scale = USCALE * v->width / 100;
	v->max_scale = USCALE_UL_ALIGN;
	v->x_sh = 0.0;
	v->y_sh = 0.0;
	v->z_sh = 0.0;
	v->i_shift = USHIFT * v->width / 10;
	v->focal_dist = 3;
	v->r = 1;
	v->g = 1;
	v->b = 1;
}

t_v	*init_v(void)
{
	t_v	*v;

	v = (t_v *)malloc(sizeof(t_v));
	if (v)
	{
		v->colors = NULL;
		v->win_h = WIN_H;
		v->win_w = WIN_W;
		v->points = NULL;
		v->keys = NULL;
		v->mlx = NULL;
		v->project = 0;
		v->err = 0;
		return (v);
	}
	exit(1);
}