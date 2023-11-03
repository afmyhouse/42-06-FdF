/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 19:21:24 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	zoom_keys_show(t_v *v)
{
	ft_printf("v->keys->o      = %i\n", v->keys->o);
	ft_printf("v->keys->p      = %i\n", v->keys->p);
}

static void	scale_keys_show(t_v *v)
{
	ft_printf("v->keys->x      = %i\n", v->keys->x);
	ft_printf("v->keys->y      = %i\n", v->keys->y);
	ft_printf("v->keys->z      = %i\n", v->keys->z);
	ft_printf("v->keys->plus   = %i\n", v->keys->plus);
	ft_printf("v->keys->minus  = %i\n", v->keys->minus);
}

static void	shift_keys_show(t_v *v)
{
	ft_printf("v->keys->i      = %i\n", v->keys->i);
	ft_printf("v->keys->j      = %i\n", v->keys->j);
	ft_printf("v->keys->k      = %i\n", v->keys->k);
	ft_printf("v->keys->l      = %i\n", v->keys->l);
	ft_printf("v->keys->up     = %i\n", v->keys->up);
	ft_printf("v->keys->down   = %i\n", v->keys->down);
	ft_printf("v->keys->left   = %i\n", v->keys->left);
	ft_printf("v->keys->right  = %i\n", v->keys->right);
}

static void	rot_keys_show(t_v *v)
{
	ft_printf("v->keys->q      = %i\n", v->keys->q);
	ft_printf("v->keys->e      = %i\n", v->keys->e);
	ft_printf("v->keys->w      = %i\n", v->keys->w);
	ft_printf("v->keys->s      = %i\n", v->keys->s);
	ft_printf("v->keys->a      = %i\n", v->keys->a);
	ft_printf("v->keys->d      = %i\n", v->keys->d);
}

void	keys_show(t_v *v)
{
	rot_keys_show(v);
	shift_keys_show(v);
	scale_keys_show(v);
	zoom_keys_show(v);
	ft_printf("v->keys->r      = %i\n", v->keys->r);
	ft_printf("v->keys->f      = %i\n", v->keys->f);
	ft_printf("v->keys->status = %i\n", v->keys->status);
	ft_printf("v->keys->m      = %i\n", v->keys->m);
	ft_printf("v->keys->c      = %i\n", v->keys->c);
}
