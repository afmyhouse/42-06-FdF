/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:55 by antoda-s          #+#    #+#             */
/*   Updated: 2024/02/02 17:56:51 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_scale(t_v *v)
{
	if (v->wd >= v->ht && v->zmax > v->wd)
		v->sc = 0.8 * (float)v->wd / (2 * v->zmax);
	else if (v->wd < v->ht && v->zmax > (v->ht))
		v->sc = 0.8 * (float)v->ht / (2 * v->zmax);
	else if (v->wd >= v->ht && v->wd >= v->zmax)
		v->sc = 0.8 * (float)v->wd / (v->zmax + v->wd);
	else if (v->wd < v->ht && v->zmax <= v->ht)
		v->sc = 0.8 * (float)v->ht / (v->zmax + v->ht);
}

void	set_scale_iso(t_v *v)
{
	if (((v->zmax - v->zmin) + ft_max(v->wd, v->ht) / 2)
		> ft_max(v->wd, v->ht))
		v->sc = (float)v->ht / ((v->zmax - v->zmin) + v->ht);
	else if (((v->zmax - v->zmin) + ft_max(v->wd, v->ht) / 2)
		<= ft_max(v->wd, v->ht))
		v->sc = 1 / 1.73;
}

void	init_iso(t_v *v)
{
	v->theta = U45DEG;
	v->phi = -UISOXRAD;
	v->psi = U30DEG;
	v->ialfa = DEG2RAD_1 * 10;
	v->xsc = 1.0;
	v->ysc = 1.0;
	v->zsc = 1.0;
	set_scale_iso(v);
	v->isc = USCALE * v->wd / 100;
	v->maxsc = USCALE_UL_ALIGN;
	v->xsh = 0.0;
	v->ysh = (v->zmax - v->zmin) / 2;
	v->zsh = 0.0;
	v->ish = USHIFT * v->wd / 10;
	v->focal = 3;
	v->r = 1;
	v->g = 1;
	v->b = 1;
	v->caption = "Isometric";
}

void	init_flat(t_v *v)
{
	v->caption = "Parallel";
	v->theta = 0.0;
	v->phi = 0.0;
	v->psi = 0.0;
	v->ialfa = UALFA;
	v->xsc = 1.0;
	v->ysc = (float)v->xsc * v->win_w / v->win_h;
	v->zsc = 1.0;
	set_scale(v);
	v->isc = USCALE * v->wd / 100;
	v->maxsc = USCALE_UL_ALIGN;
	v->xsh = 0.0;
	v->ysh = 0.0;
	v->zsh = 0.0;
	v->ish = USHIFT * v->wd / 10;
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
		v->p = NULL;
		v->keys = NULL;
		v->mlx = NULL;
		v->project = 0;
		v->err = 0;
		return (v);
	}
	exit(1);
}
