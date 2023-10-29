/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:36 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/29 22:26:11 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	exit_hook(t_v *v)
{
	mlx_destroy_window(v->mlx, v->win);
	mlx_do_key_autorepeaton(v->mlx);
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

	if (v->keys->o && v->focal_dist < 9)
		v->focal_dist++;
	if (v->keys->p && v->focal_dist > 0)
		v->focal_dist--;

	if (v->keys->minus || v->keys->plus)
		scale_hook(v);
	else if (v->keys->status)
	{
		//ft_printf("Status = %d\n", v->keys->status);
		plot_update(v);
	}

	sleep(MYTIME);

	return (0);
}

int	key_press_hook(int keycode, t_v *v)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);


	//ft_printf("Pressed keycode in = %c(%#x)\n", keycode, keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_M)
		v->project = !v->project;
	toggle_key(keycode, v, 1);

	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}

int	key_release_hook(int keycode, t_v *v)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	//ft_printf("Release key code in = %c(%#x)\n", keycode, keycode);
	toggle_key(keycode, v, 0);
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}
