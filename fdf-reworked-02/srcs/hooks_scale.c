/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:01:22 by myoung            #+#    #+#             */
/*   Updated: 2023/10/28 20:13:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	shift_hook(t_view *v)
{
	ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	// ft_printf("**********************\n");
	// ft_printf(" v->x_shift = %f\n", v->x_shift);
	// ft_printf(" v->y_shift = %f\n", v->y_shift);
	// ft_printf("----------------------\n");
	// ft_printf(" v->shift_i = %f\n", v->shift_i);
	// ft_printf(" v->keys->l = %d\n", v->keys->l);
	// ft_printf(" v->keys->right = %d\n", v->keys->right);
	// ft_printf(" v->keys->j = %d\n", v->keys->j);
	// ft_printf(" v->keys->left = %d\n", v->keys->left);
	// ft_printf(" v->keys->k = %d\n", v->keys->k);
	// ft_printf(" v->keys->down = %d\n", v->keys->down);
	// ft_printf(" v->keys->i = %d\n", v->keys->i);
	// ft_printf(" v->keys->up = %d\n", v->keys->up);
	// ft_printf("----------------------\n");
	v->x_shift += (v->keys->l || v->keys->right) * v->shift_i;
	v->x_shift -= (v->keys->j || v->keys->left) * v->shift_i;
	v->y_shift += (v->keys->k || v->keys->down) * v->shift_i;
	v->y_shift -= (v->keys->i || v->keys->up) * v->shift_i;
	// ft_printf(" v->x_shift = %f\n", v->x_shift);
	// ft_printf(" v->y_shift = %f\n", v->y_shift);
	// ft_printf("**********************\n");
	usleep(10000);
	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

// static void	zoom_hook(t_view *v)
// {
// 	if (!v->keys->x && !v->keys->y && !v->keys->z)
// 	{
// 		v->scale += v->scale_i
// 			* (v->keys->plus - v->keys->minus
// 				* ((v->scale - v->scale_i) >= v->scale_i));
// 	}
// }

void	scale_hook(t_view *v)
{
	if (!v->keys->x && !v->keys->y && !v->keys->z)
	{
		v->scale += v->scale_i
			* (v->keys->plus - v->keys->minus
				* ((v->scale - v->scale_i) >= v->scale_i));
	}
	v->x_scale += v->keys->x * v->scale_i
		* (v->keys->plus - v->keys->minus
			* ((v->x_scale - v->scale_i) >= v->scale_i));
	v->y_scale += v->keys->y * v->scale_i
		* (v->keys->plus - v->keys->minus
			* ((v->y_scale - v->scale_i) >= v->scale_i));
	v->z_scale += v->keys->z * v->scale_i
		* (v->keys->plus - v->keys->minus
			* ((v->z_scale - v->scale_i) >= v->scale_i));
	//zoom_hook(v);
	full_redraw(v);
	usleep(20000);
	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
