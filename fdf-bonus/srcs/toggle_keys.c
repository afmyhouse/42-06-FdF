/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 23:20:16 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	set_iso(t_v *v)
{
	init_iso(v);
	v->project = 0;
	plot_update(v);
}

static void	set_flat(t_v *v)
{
	init_flat(v);
	v->project = 0;
	plot_update(v);
}

static void	set_prsptv(t_v *v)
{
	init_flat(v);
	init_proj(v);
	plot_update(v);
	v->caption = "Perspective";
}

void	toggle_key(int kc, t_v *v, int kt)
{
	if (!kt)
		v->keys->status = kt;
	if (kc == KEY_R)
		set_iso(v);
	if (kc == KEY_F)
		set_flat(v);
	if (kc == KEY_V && kt)
		set_prsptv(v);
	keys_color_status(kc, v, kt);
	keys_rot_status(kc, v, kt);
	keys_shift_status(kc, v, kt);
	keys_scale_status(kc, v, kt);
	keys_zoom_status(kc, v, kt);
}
