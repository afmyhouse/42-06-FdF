/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:48 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/01 10:11:40 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	scale_hook(t_v *v)
{
	// if (MY_DEBUG)
	//	ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	v->scale += v->i_scale
		* (v->keys->plus - v->keys->minus
			* ((v->scale - v->i_scale) >= v->i_scale))
		* (!v->keys->x && !v->keys->y && !v->keys->z);
	v->x_scale += v->keys->x * v->i_scale
		* (v->keys->plus - v->keys->minus
			* ((v->x_scale - v->i_scale) >= v->i_scale));
	v->y_scale += v->keys->y * v->i_scale
		* (v->keys->plus - v->keys->minus
			* ((v->y_scale - v->i_scale) >= v->i_scale));
	v->z_scale += v->keys->z * v->i_scale
		* (v->keys->plus - v->keys->minus
			* ((v->z_scale - v->i_scale) >= v->i_scale));
	plot_full(v);
	//usleep(UMYTIME);
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
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

void	keys_scale_status(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s =>  kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__,  kc,  kc, kt, SWHT);
	if (kc == KEY_X || kc == KEY_Y || kc == KEY_Z
		|| kc == KEY_PLUS || kc == KEY_MINUS)
		keys_scale(kc, v, kt);
}
