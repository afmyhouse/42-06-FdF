/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:24 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/03 19:37:30 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	focal_hook(t_v *v)
{
	if (v->keys->p && v->focal_dist < UFOCAL_UL)
		v->focal_dist += UFOCAL_I;
	if (v->keys->o && v->focal_dist > UFOCAL_I)
		v->focal_dist -= UFOCAL_I;
	usleep(UMYTIME * 10);
}

void	keys_zoom(int kc, t_v *v, int kt)
{
	if (kc == KEY_O)
		v->keys->o = kt;
	if (kc == KEY_P)
		v->keys->p = kt;
	v->keys->status = kt;
}

void	keys_zoom_status(int kc, t_v *v, int kt)
{
	if (kc == KEY_O || kc == KEY_P)
		keys_zoom(kc, v, kt);
}

void	init_proj(t_v *v)
{
	v->project = 1;
	if (((float)v->z_max / v->width <= 0.8))
		v->scale = (float)v->z_max / v->width;
	else if (((float)v->z_max / v->width > 0.8))
		v->scale = 0.8;
	// else if (!v->project)
	// 	set_scale(v);
	printf("=> z = %d, w = %d, h = %d\n", v->z_max, v->width, v->height);
	printf("=> z/w: %f\n", (float)v->z_max / v->width);
	printf("=> scale: %f\n", v->scale);
	v->focal_dist = 20;
	v->max_scale = 1.9 * v->scale;
	if (v->max_scale > 0.8)
		v->max_scale = 0.8;
	v->i_scale = 0.05 * v->max_scale;
	//v->max_scale = 1.4 * v->scale;
}
