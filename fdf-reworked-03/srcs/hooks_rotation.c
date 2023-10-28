/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:20:54 by myoung            #+#    #+#             */
/*   Updated: 2023/10/28 17:29:03 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_hook(t_view *v)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	v->theta += (v->keys->w - v->keys->s) * 0.05;
	v->phi += (v->keys->d - v->keys->a) * 0.05;
	v->psi += (v->keys->q - v->keys->e) * 0.05;
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
