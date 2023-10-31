/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:36 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/31 18:46:22 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_points(t_v *v)
{
	int	y;
	int	x;

	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			free(v->points[y][x]->origin);
			free(v->points[y][x]->world);
			free(v->points[y][x]->aligned);
			free(v->points[y][x]->projected);
			free(v->points[y][x]);
		}
		free(v->points[y]);
	}
	free(v->points);
}

int	exit_hook(t_v *v)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	mlx_do_key_autorepeaton(v->mlx);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	free_points(v);
	if (v->keys)
		free(v->keys);
	if (v->colors)
		free(v->colors);
	if (v->mlx)
		free(v->mlx);
	if (v)
		free(v);
	exit(0);
}

// int	expose_hook(t_v *v)
// {

// 	// if (MY_DEBUG)
// 	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
// 	plot_update(v);
// 	// if (MY_DEBUG)
// 	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
// 	return (0);
// }

int	my_loop_hook(t_v *v)
{

	usleep(5000);
	if (v->keys->c)
		color_hook(v);
	if (v->keys->i || v->keys->j || v->keys->k || v->keys->l
		|| v->keys->right || v->keys->left || v->keys->up || v->keys->down)
		shift_hook(v);
	if (v->keys->w || v->keys->s || v->keys->a || v->keys->d
		|| v->keys->q || v->keys->e)
		rotate_hook(v);
	if(v->keys->o || v->keys->p)
		focal_hook(v);
	if (v->keys->minus || v->keys->plus)
		scale_hook(v);
	else if (v->keys->status)
		plot_update(v);
	sleep(MYTIME);
	return (0);
}

int	key_press_hook(int keycode, t_v *v)
{
	//ft_printf("Pressed keycode in = %d ( %x )\n", keycode, keycode);
	if (keycode == 0xff1b)
		exit_hook(v);
	if (keycode == KEY_M)
		v->project = !v->project;
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
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);

	//mlx_expose_hook(view->win, expose_hook, view);

	mlx_do_key_autorepeatoff(view->mlx);

	mlx_hook(view->win, KeyPress, KeyPressMask, key_press_hook, view);

	mlx_hook(view->win, KeyRelease, KeyReleaseMask, key_release_hook, view);

	mlx_hook(view->win, DestroyNotify, 0, exit_hook, view);

	mlx_loop_hook(view->mlx, my_loop_hook, view);

	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}
