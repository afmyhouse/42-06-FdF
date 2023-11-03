/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:23:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/03 02:01:52 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	plot_full(t_v *v)
{
	file2window(v);
	plot_update(v);
}

void	plot_update(t_v *v)
{
	window2align(v);
	create_mlx_image(v);

	if (v->project)
	{
		align2prsptiv(v);
		mlx_clear_window(v->mlx, v->win);
		// v->caption = "Perspective";
		// put_dat_to_win(v);
		plot_perspective(v);
		use_view_image(v);
		v->caption = "Perspective";
		put_dat_to_win(v);
	}
	else
	{
		mlx_clear_window(v->mlx, v->win);
		// put_dat_to_win(v);
		plot_align(v);
		use_view_image(v);
		put_dat_to_win(v);
	}
}

void	plot_perspective(t_v *v)
{
	int		y;
	int		x;

	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			if (x < v->width - 1)
				draw_line_img(v, *(v->points[y][x]->projected),
					*(v->points[y][x + 1]->projected));
			if (y < v->height - 1)
				draw_line_img(v, *(v->points[y][x]->projected),
					*(v->points[y + 1][x]->projected));
		}
	}
}

// void	plot_align(t_v *v)
// {
// 	int		y;
// 	int		x;

// 	y = -1;
// 	while (++y < v->height)
// 	{
// 		x = -1;
// 		while (++x < v->width)
// 		{
// 			if (x < v->width - 1)
// 				draw_line_img(v, *(v->points[y][x]->aligned),
// 					*(v->points[y][x + 1]->aligned));
// 			if (y < v->height - 1)
// 				draw_line_img(v, *(v->points[y][x]->aligned),
// 					*(v->points[y + 1][x]->aligned));
// 		}
// 	}
// }


void	plot_align(t_v *v)
{
	int		y;
	int		x;

	y = v->height;
	while (y--)
	{
		x = v->width;
		while (x--)
		{
			if (x < v->width - 1)
				draw_line_img(v, *(v->points[y][x]->aligned),
					*(v->points[y][x + 1]->aligned));
			if (y < v->height - 1)
				draw_line_img(v, *(v->points[y][x]->aligned),
					*(v->points[y + 1][x]->aligned));
		}
	}
}
