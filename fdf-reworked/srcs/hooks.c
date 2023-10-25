/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:26:48 by myoung            #+#    #+#             */
/*   Updated: 2023/10/25 10:24:32 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	exit_hook(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	mlx_destroy_window(view->id, view->win);
	exit(0);
}

int	expose_hook(t_view *view)
{

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	redraw(view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}

int	my_loop_hook(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	if (_SHOW_KEY_)
		keys_show(view);
	color_hook(view);
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
		scale_hook_work(view);
	else
		redraw(view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}

int		key_press_hook(int keycode, t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);

		
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_M)
		view->project = view->project ? 0 : 1;
	toggle_pressed(keycode, view, 1);

	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}

int		key_release_hook(int keycode, t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	printf("keycode = %d\n", keycode);
	toggle_pressed(keycode, view, 0);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}
