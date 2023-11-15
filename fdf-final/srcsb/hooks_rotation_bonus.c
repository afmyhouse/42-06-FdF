/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:11 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/07 09:47:56 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_hook(t_v *v)
{
	v->theta += (v->keys->w - v->keys->s) * v->ialfa;
	v->phi += (v->keys->d - v->keys->a) * v->ialfa;
	v->psi += (v->keys->e - v->keys->q) * v->ialfa;
	if (v->theta > PI2 || v->theta < -PI2)
		v->theta += -PI2 * (v->theta > PI2) + PI2 * (v->theta < -PI2);
	if (v->phi > PI2 || v->phi < -PI2)
		v->phi += -PI2 * (v->phi > PI2) + PI2 * (v->phi < -PI2);
	if (v->psi > PI2 || v->psi < -PI2)
		v->psi += -PI2 * (v->psi > PI2) + PI2 * (v->psi < -PI2);
	usleep(UMYTIME * 2);
	if (v->project)
		usleep(UMYTIME * 5);
}

static void	keys_rot_alfa(int kc, t_v *v, int kt)
{
	if (kc == KEY_W)
		v->keys->w = kt;
	if (kc == KEY_S)
		v->keys->s = kt;
	if (kc == KEY_A)
		v->keys->a = kt;
	if (kc == KEY_D)
		v->keys->d = kt;
	if (kc == KEY_Q)
		v->keys->q = kt;
	if (kc == KEY_E)
		v->keys->e = kt;
	v->keys->status = kt;
}

void	keys_rot_status(int kc, t_v *v, int kt)
{
	if (kc == KEY_W || kc == KEY_S || kc == KEY_A || kc == KEY_D
		|| kc == KEY_UP || kc == KEY_DOWN || kc == KEY_LEFT || kc == KEY_RIGHT
		|| kc == KEY_Q || kc == KEY_E)
		keys_rot_alfa(kc, v, kt);
	if (kc == KEY_UP || kc == KEY_DOWN || kc == KEY_LEFT || kc == KEY_RIGHT)
		keys_shift_arrow(kc, v, kt);
}
