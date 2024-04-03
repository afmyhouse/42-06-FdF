/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_zoom_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:24 by antoda-s          #+#    #+#             */
/*   Updated: 2024/02/02 17:48:36 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	focal_hook(t_v *v)
{
	if (v->keys->p && v->focal < UFOCAL_UL)
		v->focal += UFOCAL_I;
	if (v->keys->o && v->focal > UFOCAL_I)
		v->focal -= UFOCAL_I;
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
	v->sc = (1 - v->sc / 0.82);
	v->focal = 3;
	v->maxsc = 2 * v->sc;
	if (v->maxsc > 0.98)
		v->maxsc = 0.98;
	v->isc = 0.005 * v->maxsc;
}
