/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:04:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/12 19:13:32 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	hook_color(t_view *view)
{
	_DEBUG_ ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	if (view->pressed->c)
	{
		view->r = rand() % 3;
		view->g = rand() % 3;
		view->b = rand() % 3;
		init_color_table(view, 100);
	}
	_DEBUG_ ? printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
}
