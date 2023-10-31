/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:23:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 19:45:40 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	full_plot(t_v *v)
{
	set_file2win(v);
	plot_update(v);
}

void	plot_update(t_v *v)
{
	set_win2rts(v);
	set_rts2screen(v);
	mlx_clear_window(v->mlx, v->win);
	if (v->project)
		plot_perspective(v);
	else
		plot_flat(v);
}

void	plot_perspective(t_v *v)
{
	int		y;
	int		x;

	y = -1;
	while (++y < v->file_h)
	{
		x = -1;
		while (++x < v->file_w)
		{
			if (x < v->file_w - 1)
				draw_line(v, *(v->points[y][x]->projected),
					*(v->points[y][x + 1]->projected));
			if (y < v->file_h - 1)
				draw_line(v, *(v->points[y][x]->projected),
					*(v->points[y + 1][x]->projected));
		}
	}
}

void	plot_flat(t_v *v)
{
	int		y;
	int		x;

	y = -1;
	while (++y < v->file_h)
	{
		x = -1;
		while (++x < v->file_w)
		{
			if (x < v->file_w - 1)
				draw_line(v, *(v->points[y][x]->aligned),
					*(v->points[y][x + 1]->aligned));
			if (y < v->file_h - 1)
				draw_line(v, *(v->points[y][x]->aligned),
					*(v->points[y + 1][x]->aligned));
		}
	}
}
