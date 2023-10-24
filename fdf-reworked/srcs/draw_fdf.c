/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:18:26 by myoung            #+#    #+#             */
/*   Updated: 2023/10/24 22:10:27 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	full_redraw(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	local_to_world(view);
	redraw(view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	redraw(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	world_to_aligned(view);
	aligned_to_projected(view);
	mlx_clear_window(view->id, view->win);
	view->project ? draw_projected(view) : draw_wireframe(view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(1);
}

void	draw_projected(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	int		y;
	int		x;

	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (x < view->width - 1)
				drawline(view, *(view->points[y][x]->projected),
					*(view->points[y][x + 1]->projected));
			if (y < view->height - 1)
				drawline(view, *(view->points[y][x]->projected),
					*(view->points[y + 1][x]->projected));
		}
	}
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	draw_wireframe(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	int		y;
	int		x;

	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (x < view->width - 1)
				drawline(view, *(view->points[y][x]->aligned),
					*(view->points[y][x + 1]->aligned));
			if (y < view->height - 1)
				drawline(view, *(view->points[y][x]->aligned),
					*(view->points[y + 1][x]->aligned));
		}
	}
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
