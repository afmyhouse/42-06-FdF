/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/07 11:54:18 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_scale_iso(t_v *v)
{
	if (((v->zmax - v->zmin) + ft_max(v->width, v->height) / 2)
		> ft_max(v->width, v->height))
		v->scale = (float)v->height / ((v->zmax - v->zmin) + v->height);
	else if (((v->zmax - v->zmin) + ft_max(v->width, v->height) / 2)
		<= ft_max(v->width, v->height))
		v->scale = 1 / 1.73;
}

void	init_iso(t_v *v)
{
	v->caption = "Isometric";
	v->theta = U45DEG;
	v->phi = -UISOXRAD;
	v->psi = U30DEG;
	v->ialfa = DEG2RAD_1 * 10;
	v->xsc = 1.0;
	v->ysc = 1.0;
	v->zsc = 1.0;
	set_scale_iso(v);
	v->isc = USCALE * v->width / 100;
	v->maxsc = USCALE_UL_ALIGN;
	v->xsh = 0.0;
	v->ysh = (v->zmax - v->zmin) / 2;
	v->zsh = 0.0;
	v->ish = USHIFT * v->width / 10;
	v->focal = 3;
	v->r = 1;
	v->g = 1;
	v->b = 1;
}

t_v	*init_v(void)
{
	t_v	*v;

	v = (t_v *)malloc(sizeof(t_v));
	if (v)
	{
		v->colors = NULL;
		v->win_h = WIN_H;
		v->win_w = WIN_W;
		v->points = NULL;
		v->keys = NULL;
		v->mlx = NULL;
		v->project = 0;
		v->err = 0;
		return (v);
	}
	exit(1);
}
