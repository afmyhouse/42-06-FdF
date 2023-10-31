/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:14:17 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 14:14:20 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	show_controls(void)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	ft_putstr(
		"INTRUCTIONS: [key]\n"
		"ROTATION:\n"
		"=> rotate around x axis : [ w ] | [ s ]\n"
		"=> rotate around y axis : [ a ] | [ d ]\n"
		"+> rotate around z axis : [ q ] | [ e ]\n"
		"\n"
		"SHIFT:\n"
		"=> shift up             : [ i ] | [ up    ]\n"
		"=> shift down           : [ k ] | [ down  ]\n"
		"=> shift left and right : [ j ] | [ left  ]\n"
		"=> shift left and right : [ l ] | [ right ]\n"
		"\n"
		"SCALE:\n"
		"=> full zoom in|out     : [ + ] | [ - ]\n"
		"=> scale x axis         : [ x ] and [ + ] | [ - ] \n"
		"=> scale y axis         : [ y ] and [ + ] | [ - ] \n"
		"=> scale z axis         : [ z ] and [ + ] | [ - ] \n"
		"\n"
		"=> change color range   : [ c ]\n"
		"\n"
		"=> Esc to quit.\n");
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	fdf(t_v *view)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	show_controls();
	// init_color_table(view, NUMCOLORS);
	create_color_range(view, NUMCOLORS);
	full_plot(view);
	hooks_setting(view);
	mlx_loop(view->mlx);
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}
// 	// if (MY_DEBUG)
// 	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
// 	// if (MY_DEBUG)
// 	// 	ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);