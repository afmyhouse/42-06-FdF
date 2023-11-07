/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:23:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 10:50:08 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	plot_full(t_v *v)
{
	file2xyz(v);
	plot_update(v);
}

void	plot_update(t_v *v)
{
	xyz2align(v);
	create_image(v);
	mlx_clear_window(v->mlx, v->win);
	plot_align(v);
	plot_image(v);
}

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
				plot_line_to_img(v, *(v->points[y][x]->aligned),
					*(v->points[y][x + 1]->aligned));
			if (y < v->height - 1)
				plot_line_to_img(v, *(v->points[y][x]->aligned),
					*(v->points[y + 1][x]->aligned));
		}
	}
}
