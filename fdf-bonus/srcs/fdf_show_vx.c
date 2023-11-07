/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_show_vx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/07 01:07:09 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	vertexshow(t_v *v)
{
	int		y;
	int		x;

	y = -1;
	while (++y < v->height)
	{
		x = -1;
		ft_printf("[%d] - ", y);
		while (++x < v->width)
		{
			ft_printf("%d ", v->points[y][x]->origin->x);
			ft_printf("%d ", v->points[y][x]->origin->y);
			ft_printf("%d ", v->points[y][x]->origin->z);
			ft_printf(" | ");
		}
		ft_printf("\n");
	}
	ft_printf("....\n");
}

void	mxshow(float mx[4][4], char *str)
{
	int		y;
	int		x;

	ft_printf("%s%s%s\n", SCYN, str, SWHT);
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			ft_printf("%.3f ", mx[y][x]);
		ft_printf("\n");
	}
	ft_printf("....\n");
}
