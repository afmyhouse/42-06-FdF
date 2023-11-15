/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:10:58 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 22:12:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_points(t_v *v)
{
	int	y;
	int	x;

	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			free(v->points[y][x]->origin);
			free(v->points[y][x]->world);
			free(v->points[y][x]->aligned);
			free(v->points[y][x]->projected);
			free(v->points[y][x]);
		}
		free(v->points[y]);
	}
	free(v->points);
}

int	exit_hook(t_v *v)
{
	if (v->points)
		free_points(v);
	if (v->keys)
		free(v->keys);
	if (v->colors)
		free(v->colors);
	if (v->mlx)
	{
		mlx_do_key_autorepeaton(v->mlx);
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		free(v->mlx);
	}
	if (v)
		free(v);
	exit(0);
}
