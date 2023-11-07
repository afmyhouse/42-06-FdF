/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:12:26 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 22:14:23 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned char	get_t_c(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r_c(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g_c(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b_c(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
