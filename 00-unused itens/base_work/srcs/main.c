/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:38:28 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/13 00:06:27 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	hook_view_set(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;

	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_expose_hook", SWHT):0;
	mlx_expose_hook(view->win, expose_hook, view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_expose_hook", SWHT):0;

	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_do_key_autorepeatoff", SWHT):0;
	mlx_do_key_autorepeaton(view->id);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_do_key_autorepeatoff", SWHT):0;

	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_hook", SWHT):0;
	mlx_hook(view->win, KeyPress, KeyPressMask, hook_key_press, view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_hook", SWHT):0;

	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_hook", SWHT):0;
	mlx_hook(view->win, KeyRelease, KeyReleaseMask, hook_key_release, view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_hook", SWHT):0;

	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_hook", SWHT):0;
	mlx_hook(view->win, DestroyNotify, 0, hook_exit, view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_hook", SWHT):0;

	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_loop_hook", SWHT):0;
	mlx_loop_hook(view->id, my_loop_hook, view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_loop_hook", SWHT):0;
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

int	main(int argc, char **argv)
{
	t_view	*view;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		return (0);
	}
	view = new_map();
	_SHOW_VARS_ ? keys_show(view):0;
	parse(view, argv[1]);
	fdf(view);
}
