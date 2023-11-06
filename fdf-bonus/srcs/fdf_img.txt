/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:50:47 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/03 00:04:55 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	fill_img_grade(t_v *wd, int type)
{
	int				x;
	int				y;
	int				dec;
	int				color;
	int				color2;
	unsigned char	*ptr;

	wd->img_bypp = wd->img_bipp / 8;
	y = wd->win_h
	while (y--)
	{
		ptr = wd->pixels + y * wd->img_sl;
		x = wd->width;
		while (x--)
		{
			if (type == 2)
				color = (y * 255) / wd->simg->w
					+ ((((wd->simg->w - x) * 255) / wd->simg->w) << 16)
					+ (((y * 255) / wd->simg->h) << 8);
			else
				color = (x * 255) / wd->simg->w
					+ ((((wd->simg->w - x) * 255) / wd->simg->w) << 16)
					+ (((y * 255) / wd->simg->h) << 8);
			color2 = mlx_get_color_value(wd->smlx, color);
			dec = wd->simg->bypp;
			while (dec--)
			{
				if (wd->simg->img_edn == wd->l_endian)
				{
					if (wd->simg->img_edn)
						*(ptr + x * wd->simg->bypp + dec)
							= ((unsigned char *)(&color2))[4 - wd->simg->bypp + dec];
					else
						*(ptr + x * wd->simg->bypp + dec)
							= ((unsigned char *)(&color2))[dec];
				}
				else
				{
					if (wd->simg->img_edn)
						*(ptr + x * wd->simg->bypp + dec)
							= ((unsigned char *)(&color2))[wd->simg->bypp - 1 - dec];
					else
						*(ptr + x * wd->simg->bypp + dec)
							= ((unsigned char *)(&color2))[3 - dec];
				}
			}
		}
	}

}