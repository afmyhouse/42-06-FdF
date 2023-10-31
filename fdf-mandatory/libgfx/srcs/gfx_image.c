/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:48:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 18:47:56 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

void	use_view_image(t_v *v)
{
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_destroy_image(v->mlx, v->img);
}

void	create_view_image(t_v *v)
{
	v->img = mlx_new_image(v->mlx, v->win_w + 100, v->win_h + 100);
	v->pixels = mlx_get_data_addr(v->img, &(v->img_bipp),
			&(v->img_sl), &(v->img_endn));
}
