/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:39:05 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/19 21:49:50 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	color_map_1(void *win, int w, int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x * 255) / w
				+ ((((w - x) * 255) / w) << 16)
				+ (((y * 255) / h) << 8);
			mlx_pixel_put(mlx, win, x, y, color);
		}
	}
}


int	color_map_2(unsigned char *data, int bpp, int sl, int w, int h, int endian,  int type, int local_endian)
{
	int			x;
	int			y;
	int			opp;
	int			dec;
	int			color;
	int				color2;
	unsigned char	*ptr;

	opp = bpp / 8;
	printf("(opp : %d) ", opp);
	y = h;
	while (y--)
	{
		ptr = data + y * sl;
		x = w;
		while (x--)
		{
			if (type == 2)
				color = (y * 255) / w
					+ ((((w - x) * 255) / w) << 16)
					+ (((y * 255) / h) << 8);
			else
				color = (x * 255) / w
					+ ((((w - x) * 255) / w) << 16)
					+ (((y * 255) / h) << 8);
			color2 = mlx_get_color_value(mlx, color);
			dec = opp;
			while (dec--)
			{
				if (endian == local_endian)
				{
					if (endian)
						*(ptr + x * opp + dec)
							= ((unsigned char *)(&color2))[4 - opp + dec];
					else
						*(ptr + x * opp + dec)
							= ((unsigned char *)(&color2))[dec];
				}
				else
				{
					if (endian)
						*(ptr + x * opp + dec)
							= ((unsigned char *)(&color2))[opp - 1 - dec];
					else
						*(ptr + x * opp + dec)
							= ((unsigned char *)(&color2))[3 - dec];
				}
			}
		}
	}

}
