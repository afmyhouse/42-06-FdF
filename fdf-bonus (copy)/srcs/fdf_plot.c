/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:23:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/01 18:53:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	full_plot(t_v *v)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	original_to_window(v);
	plot_update(v);
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	plot_update(t_v *v)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	window_to_aligned(v);
	aligned_to_projected(v);
	mlx_clear_window(v->mlx, v->win);
	if (v->project)
		plot_perspective(v);
	else
		plot_align(v);
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	plot_perspective(t_v *v)
{
	int		y;
	int		x;

	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			if (x < v->width - 1)
				draw_line(v, *(v->points[y][x]->projected),
					*(v->points[y][x + 1]->projected));
			if (y < v->height - 1)
				draw_line(v, *(v->points[y][x]->projected),
					*(v->points[y + 1][x]->projected));
		}
	}
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}

void	plot_align(t_v *v)
{
	int		y;
	int		x;
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);
	ft_printf("v->theta = %f\n", v->theta * 180 / PI);
	ft_printf("v->phi = %f\n", v->phi * 180 / PI);
	ft_printf("v->psi = %f\n", v->psi * 180 / PI);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			if (x < v->width - 1)
				draw_line(v, *(v->points[y][x]->aligned),
					*(v->points[y][x + 1]->aligned));
			if (y < v->height - 1)
				draw_line(v, *(v->points[y][x]->aligned),
					*(v->points[y + 1][x]->aligned));
		}
	}
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}
