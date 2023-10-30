/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:11 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 14:31:06 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_hook(t_v *v)
{
	v->theta += (v->keys->w - v->keys->s) * v->alfa_i;
	v->phi += (v->keys->d - v->keys->a) * v->alfa_i;
	v->psi += (v->keys->e - v->keys->q) * v->alfa_i;
}

void	keys_rot_status(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s => kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__, kc, kc, kt, SWHT);
	if (kc == KEY_W || kc == KEY_S || kc == KEY_A || kc == KEY_D
		|| kc == KEY_UP || kc == KEY_DOWN || kc == KEY_LEFT || kc == KEY_RIGHT
		|| kc == KEY_Q || kc == KEY_E)
		keys_rot_alfa(kc, v, kt);
	// if (kc == KEY_UP || kc == KEY_DOWN || kc == KEY_LEFT || kc == KEY_RIGHT)
	// 	keys_shift_arrow(kc, v, kt);
}

void	keys_rot_alfa(int kc, t_v *v, int kt)
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
