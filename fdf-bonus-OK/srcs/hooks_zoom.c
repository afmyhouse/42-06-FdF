/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:24 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 22:33:02 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	focal_hook(t_v *v)
{
	if (v->keys->p && v->focal_dist < UFOCAL_UL)
		v->focal_dist += UFOCAL_I;
	if (v->keys->o && v->focal_dist > UFOCAL_I)
		v->focal_dist -= UFOCAL_I;
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
	v->project = !v->project;
	if (v->project && ((float)v->z_max / v->width < 0.45))
		v->scale = (float)v->z_max / v->width;
	else if (v->project && ((float)v->z_max / v->width >= 0.45))
		v->scale = 0.7;
	else if (!v->project)
		set_scale(v);
	v->focal_dist = 5 * v->project;
	v->max_scale = v->scale;
}
