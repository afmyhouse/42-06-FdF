/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:21:59 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 01:24:18 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	create_color_range(t_v *v, int nc)
{
	int	i;

	v->colors = (t_color *)malloc(sizeof(t_color) * nc);
	i = -1;
	while (++i < nc)
		v->colors[i] = WHITE;
}

// void	color_hook(t_v *v)
// {
// 	if (v->keys->c)
// 	{
// 		v->r = rand() % 3;
// 		v->g = rand() % 3;
// 		v->b = rand() % 3;
// 		create_color_range(v, NUMCOLORS);
// 	}
// 	usleep(UMYTIME * 5);
// }

// void	keys_color_status(int kc, t_v *v, int kt)
// {
// 	if (kc == KEY_C)
// 	{
// 		v->keys->c = kt;
// 		v->keys->status = kt;
// 	}
// }
