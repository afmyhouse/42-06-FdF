/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:20:54 by myoung            #+#    #+#             */
/*   Updated: 2023/10/24 22:00:30 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	color_hook(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	if (view->pressed->c)
	{
		view->r = rand() % 3;
		view->g = rand() % 3;
		view->b = rand() % 3;
		init_color_table(view, 100);
	}
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
