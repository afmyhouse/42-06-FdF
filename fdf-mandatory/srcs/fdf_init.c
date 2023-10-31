/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 19:37:50 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_iso(t_v *v)
{
	v->theta = U30DEG;
	v->phi = -U30DEG;
	v->psi = U45DEG;
	v->i_alfa = UALFA;
	v->x_scale = 1.0;
	v->y_scale = 1.0;
	v->z_scale = 0.2;
	v->scale = 0.5;
	v->i_scale = USCALE;
	v->x_shift = 0.0;
	v->y_shift = 0.0;
	v->z_shift = 0.0;
	v->i_shift = USHIFT;
	v->focal_dist = 3;
	v->r = 1;
	v->g = 1;
	v->b = 1;
	v->project = 0;
}

void	init_flat(t_v *v)
{
	v->theta = 0.0;
	v->phi = 0.0;
	v->psi = 0.0;
	v->i_alfa = UALFA;
	v->x_scale = 1.0;
	v->y_scale = 1.0;
	v->z_scale = 0.2;
	v->scale = 0.5;
	v->i_scale = USCALE;
	v->x_shift = 0.0;
	v->y_shift = 0.0;
	v->z_shift = 0.0;
	v->i_shift = USHIFT;
	v->focal_dist = 3;
	v->r = 1;
	v->g = 1;
	v->b = 1;
	v->project = 0;
}

t_v	*init_v(void)
{
	t_v	*v;

	v = (t_v *)malloc(sizeof(t_v));
	if (v)
	{
		v->mlx = mlx_init();
		if (v->mlx)
		{
			v->win_h = WIN_H;
			v->win_w = WIN_W;
			v->win = mlx_new_window(v->mlx, v->win_w, v->win_h, "FDF 42");
			if (v->win)
			{
				v->keys = (t_keys *)malloc(sizeof(t_keys));
				if (v->keys)
					keys_init(v);
			}
		}
		init_iso(v);
		return (v);
	}
	exit(1);
}