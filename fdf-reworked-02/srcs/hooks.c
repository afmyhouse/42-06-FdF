/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:26:48 by myoung            #+#    #+#             */
/*   Updated: 2023/10/28 20:13:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	exit_hook(t_view *v)
{
	mlx_destroy_window(v->id, v->win);
	mlx_do_key_autorepeaton(v->id);
	exit(0);
}

// int	expose_hook(t_view *v)
// {

// 	if (MY_DEBUG)
// 		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
// 	redraw(v);
// 	if (MY_DEBUG)
// 		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
// 	return (0);
// }

int	my_loop_hook(t_view *v)
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
		redraw(v);
	}

	sleep(MYTIME);

	return (0);
}

int	key_press_hook(int keycode, t_view *v)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);


	//ft_printf("Pressed keycode in = %c(%#x)\n", keycode, keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_M)
		v->project = v->project ? 0 : 1;
	toggle_key(keycode, v, 1);

	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}

int	key_release_hook(int keycode, t_view *v)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	//ft_printf("Release key code in = %c(%#x)\n", keycode, keycode);
	toggle_key(keycode, v, 0);
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}
