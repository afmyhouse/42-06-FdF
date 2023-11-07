/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:36 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 10:49:24 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	expose_hook(t_v *v)
{
	plot_update(v);
	return (0);
}

int	my_loop_hook(t_v *v)
{
	if (v->keys->minus || v->keys->plus)
	{
		scale_hook(v);
		plot_full(v);
		v->keys->status = 0;
	}
	if (v->keys->status)
		plot_update(v);
	return (0);
}

int	key_press_hook(int keycode, t_v *v)
{
	if (keycode == 0xff1b)
		exit_hook(v);
	toggle_key(keycode, v, 1);
	return (0);
}

int	key_release_hook(int keycode, t_v *v)
{
	toggle_key(keycode, v, 0);
	return (0);
}

void	hooks_setting(t_v *view)
{
	mlx_do_key_autorepeatoff(view->mlx);
	mlx_hook(view->win, KeyPress, KeyPressMask, key_press_hook, view);
	mlx_hook(view->win, KeyRelease, KeyReleaseMask, key_release_hook, view);
	mlx_hook(view->win, DestroyNotify, 0, exit_hook, view);
	mlx_loop_hook(view->mlx, my_loop_hook, view);
}
