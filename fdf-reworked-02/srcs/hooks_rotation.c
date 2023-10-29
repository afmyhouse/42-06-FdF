/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:11 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/29 22:28:40 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_hook(t_v *v)
{
	v->theta += (v->keys->w - v->keys->s) * v->alfa_i;
	v->phi += (v->keys->d - v->keys->a) * v->alfa_i;
	v->psi += (v->keys->e - v->keys->q) * v->alfa_i;
}
