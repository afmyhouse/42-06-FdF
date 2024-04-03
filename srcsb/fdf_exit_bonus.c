/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:10:58 by antoda-s          #+#    #+#             */
/*   Updated: 2024/02/02 17:56:51 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_points(t_v *v)
{
	int	y;
	int	x;

	y = -1;
	while (++y < v->ht)
	{
		x = -1;
		while (++x < v->wd)
		{
			free(v->p[y][x]->org);
			free(v->p[y][x]->win);
			free(v->p[y][x]->aln);
			free(v->p[y][x]->pjt);
			free(v->p[y][x]);
		}
		free(v->p[y]);
	}
	free(v->p);
}

int	exit_hook(t_v *v)
{
	if (v->p)
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
