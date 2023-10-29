/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/29 22:27:45 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void	keys_rot_arrow(int kc, t_v *v, int kt)
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
}

void	keys_zoom(int kc, t_v *v, int kt)
{
	if (kc == KEY_O)
		v->keys->o = kt;
	if (kc == KEY_P)
		v->keys->p = kt;
	if (kc == KEY_C)
		v->keys->c = kt;
	v->keys->status = kt;
}

