/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:18:07 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/01 22:58:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

void	init_color_table(t_v *v, int colors)
{
	int				i;
	float			f;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	v->colors = (t_color *)malloc(sizeof(t_color) * colors);
	f = 0;
	i = -1;
	while (++i < colors)
	{
		r = (cos(f) + v->r) * 127;
		g = (sin(f) + v->g) * 127;
		b = (-cos(f) + v->b) * 127;
		v->colors[i] = ((int)b) << 16 | ((int)g) << 8 | r;
		f += PI / colors;
	}
	v->num_colors = colors;
}
