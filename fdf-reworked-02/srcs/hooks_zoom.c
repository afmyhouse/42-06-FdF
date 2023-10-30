/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:24 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 14:42:28 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	focal_hook(t_v *v)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	if (v->keys->o && v->focal_dist < 9)
	{
		printf("Focal distance INCREMENTED: %d\n", v->focal_dist);
		v->focal_dist += UFOCAL;//++;
	}
	if (v->keys->p && v->focal_dist > UFOCAL)
	{
		printf("Focal distance DECREMENTED: %d\n", v->focal_dist);
		v->focal_dist -= UFOCAL;//--;
	}
	printf("Focal distance: %d\n", v->focal_dist);
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	usleep(1000000);
}

void	keys_zoom(int kc, t_v *v, int kt)
{
	if (kc == KEY_O)
		v->keys->o = kt;
	if (kc == KEY_P)
		v->keys->p = kt;
	if (kc == KEY_C)
		v->keys->c = kt;
	v->keys->status = kt;
}

void	keys_zoom_status(int kc, t_v *v, int kt)
{
	if (kc == KEY_O || kc == KEY_P || kc == KEY_C)
		keys_zoom(kc, v, kt);
}
