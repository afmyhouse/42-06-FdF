/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:01:22 by myoung            #+#    #+#             */
/*   Updated: 2023/10/24 22:21:34 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			translate_hook(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	if (view->pressed->semi)
		view->x_shift++;
	else if (view->pressed->p)
		view->x_shift--;
	if (view->pressed->l)
		view->x_shift++;
	else if (view->pressed->j)
		view->x_shift--;
	if (view->pressed->i)
		view->y_shift++;
	else if (view->pressed->k)
		view->y_shift--;
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

static void		zoom_hook(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	if (!view->pressed->x && !view->pressed->y && !view->pressed->z)
	{
		if (view->pressed->plus)
			view->scale += 0.1;
		if (view->pressed->minus)
			view->scale -= 0.1;
	}
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void			scale_hook_work(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	if (view->pressed->x)
	{
		if (view->pressed->plus)
			view->x_scale += 0.1;
		if (view->pressed->minus)
			view->x_scale -= 0.1;
	}
	if (view->pressed->y)
	{
		if (view->pressed->plus)
			view->y_scale += 0.1;
		if (view->pressed->minus)
			view->y_scale -= 0.1;
	}
	if (view->pressed->z)
	{
		if (view->pressed->plus)
			view->z_scale += 0.1;
		if (view->pressed->minus)
			view->z_scale -= 0.1;
	}
	zoom_hook(view);
	full_redraw(view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
