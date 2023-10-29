/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:48 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/29 22:29:05 by antoda-s         ###   ########.fr       */
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
	full_plot(v);
	//usleep(UMYTIME);
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
