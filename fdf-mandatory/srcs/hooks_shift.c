/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:24 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 01:31:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	shift_hook(t_v *v)
// {
// 	if ((v->keys->l || v->keys->right) && !(v->keys->j || v->keys->left))
// 		v->x_sh += v->i_shift;
// 	else if ((v->keys->j || v->keys->left) && !(v->keys->l || v->keys->right))
// 		v->x_sh -= v->i_shift;
// 	if ((v->keys->k || v->keys->down) && !(v->keys->i || v->keys->up))
// 		v->y_sh += v->i_shift;
// 	else if ((v->keys->i || v->keys->up) && !(v->keys->k || v->keys->down))
// 		v->y_sh -= v->i_shift;
// 	usleep(UMYTIME);
// }

// void	keys_shift_alfa(int kc, t_v *v, int kt)
// {
// 	if (kc == KEY_I)
// 	{
// 		v->keys->i = kt;
// 		v->keys->k = 0;
// 	}
// 	if (kc == KEY_J)
// 	{
// 		v->keys->j = kt;
// 		v->keys->l = 0;
// 	}
// 	if (kc == KEY_K)
// 	{
// 		v->keys->k = kt;
// 		v->keys->i = 0;
// 	}
// 	if (kc == KEY_L)
// 	{
// 		v->keys->l = kt;
// 		v->keys->j = 0;
// 	}
// 	v->keys->status = kt;
// }

// void	keys_shift_arrow(int kc, t_v *v, int kt)
// {
// 	if (kc == KEY_UP)
// 	{
// 		v->keys->up = kt;
// 		v->keys->down = 0;
// 	}
// 	if (kc == KEY_DOWN)
// 	{
// 		v->keys->down = kt;
// 		v->keys->up = 0;
// 	}
// 	if (kc == KEY_LEFT)
// 	{
// 		v->keys->left = kt;
// 		v->keys->right = 0;
// 	}
// 	if (kc == KEY_RIGHT)
// 	{
// 		v->keys->right = kt;
// 		v->keys->left = 0;
// 	}
// 	v->keys->status = kt;
// }

// void	keys_shift_status(int kc, t_v *v, int kt)
// {
// 	if (kc == KEY_I || kc == KEY_J || kc == KEY_K || kc == KEY_L)
// 		keys_shift_alfa(kc, v, kt);
// 	if (kc == KEY_UP || kc == KEY_DOWN || kc == KEY_LEFT || kc == KEY_RIGHT)
// 		keys_shift_arrow(kc, v, kt);
// }
