/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:29:05 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/12 19:23:39 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	show_controls(void)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	ft_putstr(
		"w/s : rotate by x axis\n"
		"a/d : rotate by y axis\n"
		"q/e : rotate by z axis\n"
		"\n"
		"c   : trippy colors\n"
		"ijkl: translate (move around)\n"
		"+/- : zoom / scale\n"
		"with z x or y, scale that axis\n"
		"Esc to quit.\n"
		);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

void	fdf(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	show_controls();
	init_color_table(view, 100);
	full_redraw(view);
	hook_view_set(view);
	mlx_loop(view->id);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}
