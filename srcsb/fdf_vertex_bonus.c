/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:09 by antoda-s          #+#    #+#             */
/*   Updated: 2024/02/02 19:27:55 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	file2xyz(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
	mx_t(mx, -v->wd / 2, -v->ht / 2, 0);
	mx_s(mx, v->xsc, v->ysc, v->zsc);
	y = -1;
	while (++y < v->ht)
	{
		x = -1;
		while (++x < v->wd)
		{
			v_mx_mul(v->p[y][x]->org, mx,
				v->p[y][x]->win);
		}
	}
}

void	xyz2align(t_v *v)
{
	float	mx[4][4];
	int		y;
	int		x;

	mx_id(mx);
	mx_r(mx, v->theta, v->phi, v->psi);
	mx_s(mx, (v->win_w * v->sc) / v->wd,
		(v->win_h * v->sc) / v->wd, v->sc);
	if (v->project)
		mx_t(mx, v->xsh, v->ysh, v->zsh);
	else
		mx_t(mx, v->xsh + v->win_w / 2, v->ysh + v->win_h / 2, v->zsh);
	y = -1;
	while (++y < v->ht)
	{
		x = -1;
		while (++x < v->wd)
		{
			v_mx_mul(v->p[y][x]->win, mx, v->p[y][x]->aln);
			if (!v->project)
				v->p[y][x]->aln->z = v->p[y][x]->org->z;
		}
	}
}

void	align2prsptiv(t_v *v)
{
	int		y;
	int		x;
	//int		zmax;
	float	fc;

	//zmax = v->zmax;
	fc = (float)(4 * v->zmax / (v->sc * v->wd));
	y = -1;
	while (++y < v->ht)
	{
		x = -1;
		while (++x < v->wd)
		{
			if (!v->p[y][x]->aln->z)
				v->p[y][x]->aln->z = 0.001;
			v->p[y][x]->pjt->x = fc * v->focal * v->p[y][x]->aln->x
				/ (v->zmax - v->p[y][x]->aln->z) + v->win_w / 2;
			v->p[y][x]->pjt->y = fc * v->focal * v->p[y][x]->aln->y
				/ (v->zmax - v->p[y][x]->aln->z) + v->win_h / 2;
			v->p[y][x]->pjt->z = v->p[y][x]->org->z;
		}
	}
	//v->zmax = zmax;
}


void	align2prsptiv_original(t_v *v)
{
	int		y;
	int		x;

	y = -1;
	while (++y < v->ht)
	{
		x = -1;
		while (++x < v->wd)
		{
			if (!v->p[y][x]->aln->z)
				v->p[y][x]->aln->z = 0.001;
			v->p[y][x]->pjt->x = v->focal * v->p[y][x]->aln->x / (v->zmax - v->p[y][x]->aln->z) + v->win_w / 2;
			v->p[y][x]->pjt->y = v->focal * v->p[y][x]->aln->y / (v->zmax - v->p[y][x]->aln->z) + v->win_h / 2;
			v->p[y][x]->pjt->z = v->p[y][x]->aln->z;
		}
	}
}
