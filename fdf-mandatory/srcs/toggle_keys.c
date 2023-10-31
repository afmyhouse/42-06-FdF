/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 18:55:35 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	toggle_key(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s => kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__, kc, kc, kt, SWHT);
	if (kc == KEY_R)
	{
		ft_printf("Resetting to ISOMETRIC...\n");
		init_iso(v);
		v->keys->status = kt;
		full_plot(v);
	}
	if (kc == KEY_F)
	{
		ft_printf("Resetting to FLAT...\n");
		v->keys->status = kt;
		init_flat(v);
		full_plot(v);
	}
	keys_rot_status(kc, v, kt);
	keys_shift_status(kc, v, kt);
	keys_scale_status(kc, v, kt);
	keys_zoom_status(kc, v, kt);
}

