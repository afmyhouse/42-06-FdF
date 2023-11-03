/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_show_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:23:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 23:31:24 by antoda-s         ###   ########.fr       */
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
	v->color = 0xFF0000;
	put_str_to_win(v, v->scale, ox, oy + (20 * (i++)));
	v->caption = "Scale X : ";
	v->color = 0xFF0000;
	put_str_to_win(v, v->x_scale, ox, oy + (20 * (i++)));
	v->caption = "Scale Y : ";
	v->color = 0xFF0000;
	put_str_to_win(v, v->y_scale, ox, oy + (20 * (i++)));
	v->caption = "Scale Z : ";
	v->color = 0xFF0000;
	put_str_to_win(v, v->z_scale, ox, oy + (20 * (i++)));
	return (i);
}

static int	put_shift_data(t_v *v, int ox, int oy)
{
	int	i;

	i = 0;
	v->caption = "Shift X : ";
	v->color = 0x00FF00;
	put_str_to_win(v, v->x_sh, ox, oy + (20 * (i++)));
	v->caption = "Shift Y : ";
	v->color = 0x00FF00;
	put_str_to_win(v, v->y_sh, ox, oy + (20 * (i++)));
	return (i);
}

static int	put_angle_data(t_v *v, int ox, int oy)
{
	int	i;

	i = 0;
	v->caption = "Theta X : ";
	v->color = 0x0000FF;
	put_str_to_win(v, v->theta, ox, oy + (20 * (i)));
	v->caption = "";
	put_str_to_win(v, (float)360 * (v->theta / PI2), ox + 100, oy + (20 * i++));
	v->caption = "Phi Y   : ";
	v->color = 0x0000FF;
	put_str_to_win(v, v->phi, ox, oy + (20 * (i)));
	v->caption = "";
	put_str_to_win(v, (float)360 * (v->phi / PI2), ox + 100, oy + (20 * i++));
	v->caption = "Psi Z   : ";
	v->color = 0x0000FF;
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

	tmp = v->caption;
	ox = v->win_w - 150;
	oy = v->win_h - 280;
	mlx_string_put(v->mlx, v->win, ox, oy, WHITE, "             ");
	mlx_string_put(v->mlx, v->win, ox, oy, WHITE, v->caption);
	put_scale_data(v, ox, oy + 20);
	put_shift_data(v, ox, oy + 100);
	put_angle_data(v, ox, oy + 140);
	v->caption = tmp;
}
