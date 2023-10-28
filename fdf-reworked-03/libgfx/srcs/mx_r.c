/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:18:37 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/28 12:49:50 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

static void	mx_rx(float mx[4][4], float theta)
{
	mx_zero(mx);
	mx[0][0] = 1;
	mx[1][1] = cos(theta);
	mx[1][2] = sin(theta);
	mx[2][1] = -sin(theta);
	mx[2][2] = cos(theta);
	mx[3][3] = 1;
}

static void	mx_ry(float mx[4][4], float phi)
{
	mx_zero(mx);
	mx[0][0] = cos(phi);
	mx[0][2] = -sin(phi);
	mx[1][1] = 1;
	mx[2][0] = sin(phi);
	mx[2][2] = cos(phi);
	mx[3][3] = 1;
}

static void	mx_rz(float mx[4][4], float psi)
{
	mx_zero(mx);
	mx[0][0] = cos(psi);
	mx[0][1] = sin(psi);
	mx[1][0] = -sin(psi);
	mx[1][1] = cos(psi);
	mx[2][2] = 1;
	mx[3][3] = 1;
}

void	mx_r(float mx0[4][4], float theta, float phi, float psi)
{
	float	rotx[4][4];
	float	roty[4][4];
	float	rotz[4][4];
	float	mx1[4][4];
	float	mx2[4][4];

	mx_rx(rotx, theta);
	mx_ry(roty, phi);
	mx_rz(rotz, psi);
	mx_mul(mx0, roty, mx1);
	mx_mul(mx1, rotx, mx2);
	mx_mul(mx2, rotz, mx0);
}

void	v_mx_mul(t_3dp *src, float mx[4][4], t_3dp *dst)
{
	dst->x
		= src->x * mx[0][0]
		+ src->y * mx[1][0]
		+ src->z * mx[2][0]
		+ mx[3][0];
	dst->y
		= src->x * mx[0][1]
		+ src->y * mx[1][1]
		+ src->z * mx[2][1]
		+ mx[3][1];
	dst->z
		= src->x * mx[0][2]
		+ src->y * mx[1][2]
		+ src->z * mx[2][2]
		+ mx[3][2];
}
