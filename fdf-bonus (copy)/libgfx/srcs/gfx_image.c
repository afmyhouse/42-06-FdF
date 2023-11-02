/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:48:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/29 18:01:25 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

void	use_view_image(t_v *view)
{
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
}

void	create_view_image(t_v *view)
{
	view->img = mlx_new_image(view->mlx, WIN_W + 100, WIN_H + 100);
	view->pixels = mlx_get_data_addr(view->img, &(view->bits_per_pixel),
			&(view->size_line), &(view->endian));
}
