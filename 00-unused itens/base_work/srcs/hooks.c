/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:29:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/12 21:54:23 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	hook_exit(t_view *view)
{
	mlx_destroy_window(view->id, view->win);
	exit(0);
}

int	expose_hook(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	redraw(view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (0);
}

int	my_loop_hook(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	_SHOW_VARS_ ? keys_show(view):0;
	hook_color(view);
	translate_hook(view);
	if (view->pressed->w)
		view->theta += 0.05;
	if (view->pressed->s)
		view->theta -= 0.05;
	if (view->pressed->a)
		view->phi -= 0.05;
	if (view->pressed->d)
		view->phi += 0.05;
	if (view->pressed->q)
		view->psi += 0.05;
	if (view->pressed->e)
		view->psi -= 0.05;
	if (view->pressed->o && view->focal_dist < 9)
		view->focal_dist++;
	if (view->pressed->p && view->focal_dist > 0)
		view->focal_dist--;
	if (view->pressed->minus || view->pressed->plus)
		hook_scale(view);
	else
		redraw(view);
	return (0);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

int	hook_key_press(int keycode, t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	_SHOW_KEY_ ? printf("%s(>)%s %s keycode = %i%s\n",SYLW, SYLW, __func__, keycode, SWHT):0;
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_M)
		view->project = !view->project;
	toggle_pressed(keycode, view, 1);
	return (0);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

int	hook_key_release(int keycode, t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	toggle_pressed(keycode, view, 0);
	return (0);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}
