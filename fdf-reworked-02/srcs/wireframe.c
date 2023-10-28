/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:27:57 by myoung            #+#    #+#             */
/*   Updated: 2023/10/28 20:23:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	local_to_world(t_view *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	mx_id(mx);
	mx_t(mx, -(v->width / 2), -(v->height / 2), 0);
	mx_s(mx, v->x_scale, v->y_scale, v->z_scale);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			v_mx_mul(v->points[y][x]->local, mx,
				v->points[y][x]->world);
		}
	}

	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}

void	world_to_aligned(t_view *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	mx_id(mx);
	mx_r(mx, v->theta, v->phi, v->psi);
	mx_s(mx, (WIN_W * v->scale) / v->width,
		(WIN_H * v->scale) / v->height, v->scale);
	if (v->project)
		mx_t(mx, v->x_shift, v->y_shift, v->z_shift);
	else
		mx_t(mx, v->x_shift + WIN_W / 2, v->y_shift + WIN_H / 2, v->z_shift);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			v_mx_mul(v->points[y][x]->world, mx, v->points[y][x]->aligned);
			//v->points[y][x]->aligned->z = v->project ? v->points[y][x]->aligned->z : v->points[y][x]->local->z;
			if (!v->project)
				v->points[y][x]->aligned->z = v->points[y][x]->local->z;
		}
	}
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}

void	aligned_to_projected(t_view *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	mx_id(mx);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			if (!v->points[y][x]->aligned->z)
				v->points[y][x]->aligned->z = 0.001;
			v->points[y][x]->projected->x = v->focal_dist
				* v->points[y][x]->aligned->x
				/ (v->z_max - v->points[y][x]->aligned->z)
				+ WIN_W / 2;
			v->points[y][x]->projected->y = v->focal_dist
				* v->points[y][x]->aligned->y
				/ (v->z_max - v->points[y][x]->aligned->z)
				+ WIN_H / 2;
			v->points[y][x]->projected->z = v->points[y][x]->local->z;
		}
	}
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}


t_view	*init_v(void)
{
	t_view	*v;

	v = (t_view *)malloc(sizeof(t_view));
	v->project = 0;

	v->theta = 0.0;
	v->phi = 0.0;
	v->psi = 0.0;
	v->alfa_i = 0.05;

	v->x_scale = 1;
	v->y_scale = 1;
	v->z_scale = 1;
	v->scale = 0.5;
	v->scale_i = 0.01;

	v->x_shift = 0.0;
	v->y_shift = 0.0;
	v->z_shift = 0.0;
	v->shift_i = 1;

	v->focal_dist = 7;
	v->r = 1;
	v->g = 1;
	v->b = 1;
	v->id = mlx_init();
	v->win = mlx_new_window(v->id, WIN_W, WIN_H, "FDF 42");
	v->keys = (t_keys *)malloc(sizeof(t_keys));
	keys_init(v);
	return (v);
}

void	keys_init(t_view *v)
{
	v->keys->status = 0;
	v->keys->c = 0;
	v->keys->semi = 0;
	v->keys->i = 0;
	v->keys->j = 0;
	v->keys->k = 0;
	v->keys->l = 0;
	v->keys->m = 0;
	v->keys->n = 0;
	v->keys->o = 0;
	v->keys->p = 0;

	v->keys->q = 0;
	v->keys->w = 0;
	v->keys->e = 0;
	v->keys->a = 0;
	v->keys->s = 0;
	v->keys->d = 0;

	v->keys->x = 0;
	v->keys->y = 0;
	v->keys->z = 0;

	v->keys->left = 0;
	v->keys->up = 0;
	v->keys->right = 0;
	v->keys->down = 0;
	v->keys->plus = 0;
	v->keys->minus = 0;
}

void	keys_show(t_view *v)
{
	ft_printf("******************************\n");
	ft_printf("v->keys->status = %i\n", v->keys->status);
	ft_printf("v->keys->a      = %i\n", v->keys->a);
	ft_printf("v->keys->b      = %i\n", v->keys->b);
	ft_printf("v->keys->c      = %i\n", v->keys->c);
	ft_printf("v->keys->d      = %i\n", v->keys->d);
	ft_printf("v->keys->e      = %i\n", v->keys->e);
	ft_printf("v->keys->f      = %i\n", v->keys->f);
	ft_printf("v->keys->g      = %i\n", v->keys->g);
	ft_printf("v->keys->h      = %i\n", v->keys->h);
	ft_printf("v->keys->i      = %i\n", v->keys->i);
	ft_printf("v->keys->j      = %i\n", v->keys->j);
	ft_printf("v->keys->k      = %i\n", v->keys->k);
	ft_printf("v->keys->l      = %i\n", v->keys->l);
	ft_printf("v->keys->m      = %i\n", v->keys->m);
	ft_printf("v->keys->n      = %i\n", v->keys->n);
	ft_printf("v->keys->o      = %i\n", v->keys->o);
	ft_printf("v->keys->p      = %i\n", v->keys->p);
	ft_printf("v->keys->q      = %i\n", v->keys->q);
	ft_printf("v->keys->r      = %i\n", v->keys->r);
	ft_printf("v->keys->s      = %i\n", v->keys->s);
	ft_printf("v->keys->t      = %i\n", v->keys->t);
	ft_printf("v->keys->u      = %i\n", v->keys->u);
	ft_printf("v->keys->v      = %i\n", v->keys->v);
	ft_printf("v->keys->w      = %i\n", v->keys->w);
	ft_printf("v->keys->x      = %i\n", v->keys->x);
	ft_printf("v->keys->y      = %i\n", v->keys->y);
	ft_printf("v->keys->z      = %i\n", v->keys->z);
	ft_printf("v->keys->tab    = %i\n", v->keys->tab);
	ft_printf("v->keys->semi   = %i\n", v->keys->semi);
	ft_printf("v->keys->brace_l= %i\n", v->keys->brace_l);
	ft_printf("v->keys->brace_r= %i\n", v->keys->brace_r);
	ft_printf("v->keys->plus   = %i\n", v->keys->plus);
	ft_printf("v->keys->minus  = %i\n", v->keys->minus);
	ft_printf("v->keys->up     = %i\n", v->keys->up);
	ft_printf("v->keys->down   = %i\n", v->keys->down);
	ft_printf("v->keys->left   = %i\n", v->keys->left);
	ft_printf("v->keys->right  = %i\n", v->keys->right);
	ft_printf("v->project      = %i\n", v->project);

}
