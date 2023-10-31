/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:24 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 18:29:19 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	shift_hook(t_v *v)
{
	// if (MY_DEBUG)
	//	ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	v->x_shift += (v->keys->l || v->keys->right) * v->i_shift;
	v->x_shift -= (v->keys->j || v->keys->left) * v->i_shift;
	v->y_shift += (v->keys->k || v->keys->down) * v->i_shift;
	v->y_shift -= (v->keys->i || v->keys->up) * v->i_shift;
	usleep(UMYTIME);
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	keys_shift(int kc, t_v *v, int kt)
{
	if (kc == KEY_I)
		v->keys->i = kt;
	if (kc == KEY_J)
		v->keys->j = kt;
	if (kc == KEY_K)
		v->keys->k = kt;
	if (kc == KEY_L)
		v->keys->l = kt;
	v->keys->status = kt;
}

void	keys_shift_arrow(int kc, t_v *v, int kt)
{
	if (kc == KEY_UP)
		v->keys->up = kt;
	if (kc == KEY_DOWN)
		v->keys->down = kt;
	if (kc == KEY_LEFT)
		v->keys->left = kt;
	if (kc == KEY_RIGHT)
		v->keys->right = kt;
	v->keys->status = kt;
}

void	keys_shift_status(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s => kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__, kc, kc, kt, SWHT);
	if (kc == KEY_I || kc == KEY_J || kc == KEY_K || kc == KEY_L)
		keys_shift(kc, v, kt);
	if (kc == KEY_UP || kc == KEY_DOWN || kc == KEY_LEFT || kc == KEY_RIGHT)
		keys_shift_arrow(kc, v, kt);
}

