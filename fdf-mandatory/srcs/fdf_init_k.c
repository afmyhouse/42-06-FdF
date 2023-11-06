/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_k.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 01:28:51 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	scale_keys_init(t_v *v)
{
	v->keys->x = 0;
	v->keys->y = 0;
	v->keys->z = 0;
	v->keys->plus = 0;
	v->keys->minus = 0;
}

// static void	rot_keys_init(t_v *v)
// {
// 	v->keys->q = 0;
// 	v->keys->e = 0;
// 	v->keys->w = 0;
// 	v->keys->s = 0;
// 	v->keys->a = 0;
// 	v->keys->d = 0;
// }

// static void	shift_keys_init(t_v *v)
// {
// 	v->keys->i = 0;
// 	v->keys->j = 0;
// 	v->keys->k = 0;
// 	v->keys->l = 0;
// 	v->keys->left = 0;
// 	v->keys->up = 0;
// 	v->keys->right = 0;
// 	v->keys->down = 0;
// }

// static void	zoom_keys_init(t_v *v)
// {
// 	v->keys->o = 0;
// 	v->keys->p = 0;
// }

void	keys_init(t_v *v)
{
	//rot_keys_init(v);
	scale_keys_init(v);
	//shift_keys_init(v);
	//zoom_keys_init(v);
	v->keys->r = 0;
	// v->keys->f = 0;
	// v->keys->m = 0;
	// v->keys->status = 0;
	// v->keys->c = 0;
}
