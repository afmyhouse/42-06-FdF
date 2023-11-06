/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:17 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 01:20:46 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	show_controls(void)
{
	ft_putstr(
		"\n######### INTRUCTIONS: [key] ###########\n"
		"VIEWS: \n\t[ r ] ISO\n"//\t"[ f ] - XY\n\t[ g ] - ZX\n\t[ h ] - YZ\n"
		// "\t[ v ] - Perspective\n\n"
		// "AXIS : [ x ] [ y ] [ z ] (object axis)\n"
		// "\tx horizontal\n\ty vertical\n\tz depth\nROTATION:\n"
		// "=> rotate around x axis : [ w ] | [ s ]\n"
		// "=> rotate around y axis : [ a ] | [ d ]\n"
		// "+> rotate around z axis : [ q ] | [ e ]\n"
		// "\nSHIFT:\n"
		// "=> shift up             : [ i ] | [ up    ]\n"
		// "=> shift down           : [ k ] | [ down  ]\n"
		// "=> shift left and right : [ j ] | [ left  ]\n"
		// "=> shift left and right : [ l ] | [ right ]\n"
		"\nSCALE:\n\t"
		"=> full zoom in|out     : [ + ] | [ - ]\n\t"
		"=> scale x axis         : [ x ] and [ + ] | [ - ] \n\t"
		"=> scale y axis         : [ y ] and [ + ] | [ - ] \n\t"
		"=> scale z axis         : [ z ] and [ + ] | [ - ] \n\t"
		// "\n=> change color range   : [ c ]\n"
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

void	fdf(t_v *v)
{
	show_controls();
	window_init(v);
	create_color_range(v, NUMCOLORS);
	plot_full(v);
	hooks_setting(v);
	mlx_loop(v->mlx);
}
