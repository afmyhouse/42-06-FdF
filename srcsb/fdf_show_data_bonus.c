/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_show_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:23:06 by antoda-s          #+#    #+#             */
/*   Updated: 2024/02/02 17:48:36 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_str_to_win(t_v *v, float val, int x, int y)
{
	char	*tmp;
	char	*str;

	tmp = ft_ftoa(val, 3);
	if (val >= 0)
	{
		str = ft_strjoin("+", tmp);
		free(tmp);
		tmp = str;
	}
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
	put_str_to_win(v, v->sc, ox, oy + (20 * (i++)));
	v->caption = "Scale X : ";
	put_str_to_win(v, v->xsc, ox, oy + (20 * (i++)));
	v->caption = "Scale Y : ";
	put_str_to_win(v, v->ysc, ox, oy + (20 * (i++)));
	v->caption = "Scale Z : ";
	put_str_to_win(v, v->zsc, ox, oy + (20 * (i++)));
	return (i);
}

static int	put_shift_data(t_v *v, int ox, int oy)
{
	int	i;

	i = 0;
	v->caption = "Shift X : ";
	v->color = LIMEGREEN;
	put_str_to_win(v, v->xsh, ox, oy + (20 * (i++)));
	v->caption = "Shift Y : ";
	put_str_to_win(v, v->ysh, ox, oy + (20 * (i++)));
	if (v->project)
	{
		v->color = LIGHTSTEELBLUE;
		v->caption = "Focus : ";
		put_str_to_win(v, v->focal, ox, oy + (20 * (i++)));
	}
	return (i);
}

static int	put_angle_data(t_v *v, int ox, int oy)
{
	int	i;

	i = 0;
	v->caption = "Theta (X) : ";
	v->color = KHAKI;
	put_str_to_win(v, v->theta, ox, oy + (20 * (i)));
	v->caption = "";
	put_str_to_win(v, (float)360 * (v->theta / PI2), ox + 120, oy + (20 * i++));
	v->caption = "Phi   (Y) : ";
	put_str_to_win(v, v->phi, ox, oy + (20 * (i)));
	v->caption = "";
	put_str_to_win(v, (float)360 * (v->phi / PI2), ox + 120, oy + (20 * i++));
	v->caption = "Psi   (Z) : ";
	put_str_to_win(v, v->psi, ox, oy + (20 * (i)));
	v->caption = "";
	put_str_to_win(v, (float)360 * (v->psi / PI2), ox + 120, oy + (20 * i++));
	return (i);
}

void	put_dat_to_win(t_v *v)
{
	int		ox;
	int		oy;
	char	*tmp;
	int		col;

	tmp = v->caption;
	col = 150;
	ox = 50;
	oy = v->win_h - 80;
	mlx_string_put(v->mlx, v->win, ox, oy, WHITE, "             ");
	mlx_string_put(v->mlx, v->win, ox, oy, WHITE, v->caption);
	mlx_string_put(v->mlx, v->win, ox, oy + 20, LIMEGREEN, v->file);
	ox += col;
	put_scale_data(v, ox, oy);
	ox += col;
	put_shift_data(v, ox, oy);
	ox += col;
	put_angle_data(v, ox, oy);
	v->caption = tmp;
}
