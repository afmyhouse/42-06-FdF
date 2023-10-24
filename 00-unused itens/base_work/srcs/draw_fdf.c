/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:27:25 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/12 19:23:39 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	full_redraw(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	local_to_world(view);
	redraw(view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

void	redraw(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	world_to_aligned(view);
	aligned_to_projected(view);
	mlx_clear_window(view->id, view->win);
	if (view->project)
		draw_projected(view);
	else
		draw_wireframe(view);
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

void	draw_projected(t_view *view)
{
	int		y;
	int		x;

	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
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
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}

void	draw_wireframe(t_view *view)
{
	int		y;
	int		x;

	//_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
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
	//_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}
