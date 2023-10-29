/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:24 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/29 17:58:31 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	shift_hook(t_v *v)
{
	// if (MY_DEBUG)
	//	ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	v->x_shift += (v->keys->l || v->keys->right) * v->shift_i;
	v->x_shift -= (v->keys->j || v->keys->left) * v->shift_i;
	v->y_shift += (v->keys->k || v->keys->down) * v->shift_i;
	v->y_shift -= (v->keys->i || v->keys->up) * v->shift_i;
	usleep(UMYTIME);
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

