/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_show_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:23:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/03 11:38:35 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_str_to_win(t_v *v, float val, int x, int y)
{
	char	*tmp;
	char	*str;

	tmp = ft_ftoa(val);
	str = ft_strjoin(v->caption, tmp);
	mlx_string_put(v->mlx, v->win, x, y, v->color, str);
	free(tmp);
	free(str);
}

static int	put_scale_data(t_v *v, int ox, int oy)
{
	int	i;

	i = 0;
	v->caption = "Scale   : ";
	v->color = LIGHTSALMON;
	put_str_to_win(v, v->scale, ox, oy + (20 * (i++)));
	v->caption = "Scale X : ";
	// v->color = 0xFF0000;
	put_str_to_win(v, v->x_scale, ox, oy + (20 * (i++)));
	v->caption = "Scale Y : ";
	// v->color = 0xFF0000;
	put_str_to_win(v, v->y_scale, ox, oy + (20 * (i++)));
	v->caption = "Scale Z : ";
	// v->color = 0xFF0000;
	put_str_to_win(v, v->z_scale, ox, oy + (20 * (i++)));
	return (i);
}

static int	put_shift_data(t_v *v, int ox, int oy)
{
	int	i;

	i = 0;
	v->caption = "Shift X : ";
	v->color = LIMEGREEN;
	put_str_to_win(v, v->x_sh, ox, oy + (20 * (i++)));
	v->caption = "Shift Y : ";
	// v->color = 0x00FF00;
	put_str_to_win(v, v->y_sh, ox, oy + (20 * (i++)));
	if (v->project)
	{
		v->color = LIGHTSTEELBLUE;
		v->caption = "Focus : ";
		put_str_to_win(v, v->focal_dist, ox, oy + (20 * (i++)));
	}
	return (i);
}

static int	put_angle_data(t_v *v, int ox, int oy)
{
	int	i;

	i = 0;
	v->caption = "Theta X : ";
	v->color = KHAKI;
	put_str_to_win(v, v->theta, ox, oy + (20 * (i)));
	v->caption = "";
	put_str_to_win(v, (float)360 * (v->theta / PI2), ox + 100, oy + (20 * i++));
	v->caption = "Phi Y   : ";
	put_str_to_win(v, v->phi, ox, oy + (20 * (i)));
	v->caption = "";
	put_str_to_win(v, (float)360 * (v->phi / PI2), ox + 100, oy + (20 * i++));
	v->caption = "Psi Z   : ";
	put_str_to_win(v, v->psi, ox, oy + (20 * (i)));
	v->caption = "";
	put_str_to_win(v, (float)360 * (v->psi / PI2), ox + 100, oy + (20 * i++));
	return (i);
}

void	put_dat_to_win(t_v *v)
{
	int		ox;
	int		oy;
	char	*tmp;
	int	col;

	tmp = v->caption;
	col = 150;
	ox = 50;
	oy = v->win_h - 80;
	mlx_string_put(v->mlx, v->win, ox, oy, WHITE, "             ");
	mlx_string_put(v->mlx, v->win, ox, oy, WHITE, v->caption);
	ox += col;
	put_scale_data(v, ox, oy);
	ox += col;
	put_shift_data(v, ox, oy);
	ox += col;
	put_angle_data(v, ox, oy);
	v->caption = tmp;
}
