/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:17 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 23:15:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	show_controls(void)
{
	ft_putstr(
		"INTRUCTIONS: [key]\n"
		"AXIS: [ x ] [ y ] [ z ] (object axis)\n"
		"      x horizontal\n"
		"      y vertical\n"
		"      z depth\nROTATION:\n"
		"=> rotate around x axis : [ w ] | [ s ]\n"
		"=> rotate around y axis : [ a ] | [ d ]\n"
		"+> rotate around z axis : [ q ] | [ e ]\n"
		"\nSHIFT:\n"
		"=> shift up             : [ i ] | [ up    ]\n"
		"=> shift down           : [ k ] | [ down  ]\n"
		"=> shift left and right : [ j ] | [ left  ]\n"
		"=> shift left and right : [ l ] | [ right ]\n"
		"\nSCALE:\n"
		"=> full zoom in|out     : [ + ] | [ - ]\n"
		"=> scale x axis         : [ x ] and [ + ] | [ - ] \n"
		"=> scale y axis         : [ y ] and [ + ] | [ - ] \n"
		"=> scale z axis         : [ z ] and [ + ] | [ - ] \n"
		"\n=> change color range   : [ c ]\n"
		"\n=> Esc to quit.\n");
}

static void	window_init(t_v *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		exit_hook(v);
	v->win = mlx_new_window(v->mlx, v->win_w, v->win_h, "FDF 42 BONUS");
	if (!v->win)
		exit_hook(v);
	v->keys = (t_keys *)malloc(sizeof(t_keys));
	if (!v->keys)
		exit_hook(v);
	keys_init(v);
	init_iso(v);
}

///		create_mlx_image(v);
///		mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0, 0);
///		mlx_destroy_image(v->mlx, v->img->img);
void	fdf(t_v *v)
{
	show_controls();
	window_init(v);
	create_color_range(v, NUMCOLORS);
	plot_full(v);
	hooks_setting(v);
	mlx_loop(v->mlx);
}
