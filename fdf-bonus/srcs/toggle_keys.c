/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/07 01:11:32 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	set_iso(t_v *v)
{
	init_iso(v);
	v->project = 0;
	plot_full(v);
}

static void	set_flat(t_v *v, char axis)
{
	init_flat(v);
	if (axis == 'x')
		v->theta = PI / 2;
	if (axis == 'y')
		v->phi = PI / 2;
	if (axis == 'z')
		v->psi = 0;
	v->project = 0;
	plot_full(v);
}

static void	set_prsptv(t_v *v)
{
	set_flat(v, 'x');
	init_proj(v);
	plot_update(v);
}

// static void	set_sphere(t_v *v)
// {
// 	set_flat(v, 'x');
// 	align2sphere(v);
// 	v->sphere = 1;
// 	plot_update(v);
// }

void	toggle_key(int kc, t_v *v, int kt)
{
	if (!kt)
		v->keys->status = kt;
	if (kc == KEY_R)
		set_iso(v);
	if (kc == KEY_F)
		set_flat(v, 'z');
	if (kc == KEY_G)
		set_flat(v, 'x');
	if (kc == KEY_H)
		set_flat(v, 'y');
	// if (kc == KEY_B)
	// 	set_sphere(v);
	if (kc == KEY_V && kt)
		set_prsptv(v);
	keys_color_status(kc, v, kt);
	keys_rot_status(kc, v, kt);
	keys_shift_status(kc, v, kt);
	keys_scale_status(kc, v, kt);
	keys_zoom_status(kc, v, kt);
}
