/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:57:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/12 19:20:24 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

void	translate_hook(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
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
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

void	hook_zoom(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	if (!view->pressed->x && !view->pressed->y && !view->pressed->z)
	{
		if (view->pressed->plus)
			view->scale += 0.1;
		if (view->pressed->minus)
			view->scale -= 0.1;
	}
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

void	hook_scale(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
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
	hook_zoom(view);
	full_redraw(view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}
