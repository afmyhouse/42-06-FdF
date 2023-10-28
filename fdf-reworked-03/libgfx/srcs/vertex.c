/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:28 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/28 18:36:21 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"
//#include "../include/libgfx.h"

t_2dp	*get_2dp(float x, float y)
{
	t_2dp	*vertex;

	vertex = (t_2dp *)malloc(sizeof(t_2dp));
	vertex->x = x;
	vertex->y = y;
	return (vertex);
}

t_3dp	*get_3dp(float x, float y, float z)
{
	t_3dp	*vertex;

	vertex = (t_3dp *)malloc(sizeof(t_3dp));
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	return (vertex);
}

t_vertex	*get_vertex(float x, float y, float z)
{
	t_vertex	*vertex;

	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	vertex->local = get_3dp(x, y, z);
	vertex->world = get_3dp(0, 0, 0);
	vertex->aligned = get_3dp(0, 0, 0);
	vertex->projected = get_3dp(0, 0, 0);
	vertex->color = z;
	return (vertex);
}
