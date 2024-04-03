/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:23:06 by antoda-s          #+#    #+#             */
/*   Updated: 2024/02/02 17:56:51 by antoda-s         ###   ########.fr       */
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

	y = v->ht;
	while (y--)
	{
		x = v->wd;
		while (x--)
		{
			if (x < v->wd - 1)
				plot_line_to_img(v, *(v->p[y][x]->aln),
					*(v->p[y][x + 1]->aln));
			if (y < v->ht - 1)
				plot_line_to_img(v, *(v->p[y][x]->aln),
					*(v->p[y + 1][x]->aln));
		}
	}
}
