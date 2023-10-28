/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:20:54 by myoung            #+#    #+#             */
/*   Updated: 2023/10/28 20:27:08 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_hook(t_view *v)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	ft_printf("**********************\n");
	ft_printf(" v->theta = %f\n", v->theta);
	ft_printf(" v->phi = %f\n", v->phi);
	ft_printf(" v->psi = %f\n", v->psi);
	ft_printf("----------------------\n");
	ft_printf(" v->alfa_i = %f\n", v->alfa_i);
	ft_printf(" (v->keys->w - v->keys->s) = %d\n", (v->keys->w - v->keys->s));
	ft_printf(" (v->keys->d - v->keys->a) = %d\n", (v->keys->d - v->keys->a));
	ft_printf(" (v->keys->q - v->keys->e) = %d\n", (v->keys->q - v->keys->e));
	ft_printf("----------------------\n");
	v->theta += (v->keys->w - v->keys->s) * 0.05;
	v->phi += (v->keys->d - v->keys->a) * 0.05;
	v->psi += (v->keys->q - v->keys->e) * 0.05;
	ft_printf(" v->theta = %f\n", v->theta);
	ft_printf(" v->phi = %f\n", v->phi);
	ft_printf(" v->psi = %f\n", v->psi);
	ft_printf("**********************\n");
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
