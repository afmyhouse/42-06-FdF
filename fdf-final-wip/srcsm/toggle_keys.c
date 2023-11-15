/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 10:50:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	set_iso(t_v *v)
{
	init_iso(v);
	v->project = 0;
	plot_full(v);
}

void	toggle_key(int kc, t_v *v, int kt)
{
	if (!kt)
		v->keys->status = kt;
	if (kc == KEY_R)
		set_iso(v);
	keys_scale_status(kc, v, kt);
}
