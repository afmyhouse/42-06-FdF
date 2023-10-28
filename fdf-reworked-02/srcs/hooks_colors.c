/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:20:54 by myoung            #+#    #+#             */
/*   Updated: 2023/10/28 20:13:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	color_hook(t_view *view)
{

	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);

	if (view->keys->c)
	{
		view->r = rand() % 3;
		ft_printf("%s(>)%s %s = %f%s\n", SYLW, SYLW, "view->r", view->r, SWHT);
		view->g = rand() % 3;
		ft_printf("%s(>)%s %s = %f%s\n", SYLW, SYLW, "view->g", view->g, SWHT);
		view->b = rand() % 3;
		ft_printf("%s(>)%s %s = %f%s\n", SYLW, SYLW, "view->b", view->b, SWHT);
		//remove this sleep() to see the color change in real time
		//sleep(1);
		init_color_table(view, 100);
	}

	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

