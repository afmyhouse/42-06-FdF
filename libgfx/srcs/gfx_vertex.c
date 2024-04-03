/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:28 by antoda-s          #+#    #+#             */
/*   Updated: 2024/02/02 17:54:24 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

t_2d	*set_vx_2d(float x, float y)
{
	t_2d	*v2d;

	v2d = (t_2d *)malloc(sizeof(t_2d));
	v2d->x = x;
	v2d->y = y;
	return (v2d);
}

t_3d	*set_vx_3d(float x, float y, float z)
{
	t_3d	*v3d;

	v3d = (t_3d *)malloc(sizeof(t_3d));
	v3d->x = x;
	v3d->y = y;
	v3d->z = z;
	return (v3d);
}

t_vx	*set_vx(float x, float y, float z)
{
	t_vx	*vertex;

	vertex = (t_vx *)malloc(sizeof(t_vx));
	vertex->org = set_vx_3d(x, y, z);
	vertex->win = set_vx_3d(0, 0, 0);
	vertex->aln = set_vx_3d(0, 0, 0);
	vertex->pjt = set_vx_3d(0, 0, 0);
	vertex->color = z;
	return (vertex);
}
