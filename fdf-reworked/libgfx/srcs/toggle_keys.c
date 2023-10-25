/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/25 10:41:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libgfx.h"
// #include "libgfx.h"

static void	toggle_set_1(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_W)
		view->pressed->w = toggle;
	if (keycode == KEY_S)
		view->pressed->s = toggle;
	if (keycode == KEY_A)
		view->pressed->a = toggle;
	if (keycode == KEY_D)
		view->pressed->d = toggle;
}

static void	toggle_set_2(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_I)
		view->pressed->i = toggle;
	if (keycode == KEY_J)
		view->pressed->j = toggle;
	if (keycode == KEY_K)
		view->pressed->k = toggle;
	if (keycode == KEY_L)
		view->pressed->l = toggle;
	if (keycode == KEY_C)
		view->pressed->c = toggle;
}

static void	toggle_set_3(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_X)
		view->pressed->x = toggle;
	if (keycode == KEY_Y)
		view->pressed->y = toggle;
	if (keycode == KEY_Z)
		view->pressed->z = toggle;
	if (keycode == KEY_Q)
		view->pressed->q = toggle;
	if (keycode == KEY_E)
		view->pressed->e = toggle;
	if (keycode == KEY_O)
		view->pressed->o = toggle;
	if (keycode == KEY_P)
		view->pressed->p = toggle;
	if (keycode == KEY_PLUS)
		view->pressed->plus = toggle;
	if (keycode == KEY_MINUS)
		view->pressed->minus = toggle;
}
void	toggle_pressed(int keycode, t_view *view, int toggle)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	printf("keycode = %d\n", keycode);

	toggle_set_1(keycode, view, toggle);
	toggle_set_2(keycode, view, toggle);
	toggle_set_3(keycode, view, toggle);

}
