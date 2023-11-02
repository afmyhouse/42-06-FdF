/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:48:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 21:34:28 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

void	use_view_image(t_v *v)
{
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_destroy_image(v->mlx, v->img);
}

void	create_mlx_image(t_v *v)
{
	v->img = mlx_new_image(v->mlx, v->win_w, v->win_h);
	v->pixels = mlx_get_data_addr(v->img, &(v->bits_per_pixel),
			&(v->size_line), &(v->endian));
}
