/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_k.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 10:48:02 by antoda-s         ###   ########.fr       */
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

void	keys_init(t_v *v)
{
	scale_keys_init(v);
	v->keys->r = 0;
}
