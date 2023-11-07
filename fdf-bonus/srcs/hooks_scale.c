/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:48 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/07 01:07:58 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	scale_axys(t_v *v)
{
	if (!v->project)
	{
		v->xsc += v->keys->x * v->isc
			* (v->keys->plus - v->keys->minus
				* ((v->xsc - v->isc) >= 0));
		v->ysc += v->keys->y * v->isc
			* (v->keys->plus - v->keys->minus
				* ((v->ysc - v->isc) >= 0));
		v->zsc += v->keys->z * v->isc
			* (v->keys->plus - v->keys->minus
				* ((v->zsc - v->isc) >= 0));
	}
}

static void	scale_full(t_v *v)
{
	if (v->keys->plus && (v->scale + v->isc) <= v->maxsc)
		v->scale += v->isc;
	if (v->keys->minus && ((v->scale - v->isc) >= v->isc))
		v->scale -= v->isc;
	if (v->project)
		usleep(UMYTIME * 2);
}

void	scale_hook(t_v *v)
{
	if (!v->keys->x && !v->keys->y && !v->keys->z)
		scale_full(v);
	else if (v->keys->x || v->keys->y || v->keys->z)
		scale_axys(v);
}

void	keys_scale(int key, t_v *v, int kt)
{
	if (key == KEY_X)
		v->keys->x = kt;
	if (key == KEY_Y)
		v->keys->y = kt;
	if (key == KEY_Z)
		v->keys->z = kt;
	if (key == KEY_PLUS)
		v->keys->plus = kt;
	if (key == KEY_MINUS)
		v->keys->minus = kt;
	if (key == KEY_PLUS || key == KEY_MINUS)
			v->keys->status = kt;
	if (v->keys->plus && (v->scale + v->isc) >= v->maxsc)
		v->keys->status = 0;
}

void	keys_scale_status(int kc, t_v *v, int kt)
{
	if (kc == KEY_X || kc == KEY_Y || kc == KEY_Z
		|| kc == KEY_PLUS || kc == KEY_MINUS)
		keys_scale(kc, v, kt);
}
