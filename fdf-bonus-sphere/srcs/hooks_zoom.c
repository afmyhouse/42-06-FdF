/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:24 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/05 23:07:04 by antoda-s         ###   ########.fr       */
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

	set_scale(v);
	// printf("=> z = %d, w = %d, h = %d\n", v->z_max, v->width, v->height);
	// printf("=> z/w: %f\n", (float)v->z_max / v->width);
	// printf("=> z/h: %f\n", (float)v->z_max / v->height);
	// printf("=> scale: %f\n", v->scale);
	v->scale = (1 - v->scale / 0.82);
	v->focal_dist = 3;
	v->max_scale = 2 * v->scale;
	if (v->max_scale > 0.98)
		v->max_scale = 0.98;
	v->i_scale = 0.005 * v->max_scale;
	// printf("=> scale: %f\n", v->scale);
	// printf("int proj max scale: %f\n", v->max_scale);

}
