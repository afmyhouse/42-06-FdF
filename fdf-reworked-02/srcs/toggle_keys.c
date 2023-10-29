/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/29 17:58:31 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	keys_rot_status(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s => kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__, kc, kc, kt, SWHT);
	if (kc == KEY_W || kc == KEY_S || kc == KEY_A || kc == KEY_D
		|| kc == KEY_UP || kc == KEY_DOWN || kc == KEY_LEFT || kc == KEY_RIGHT
		|| kc == KEY_Q || kc == KEY_E)
		keys_rot_alfa(kc, v, kt);
	if (kc == KEY_UP || kc == KEY_DOWN || kc == KEY_LEFT || kc == KEY_RIGHT)
		keys_rot_arrow(kc, v, kt);
}

void	keys_shift_status(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s => kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__, kc, kc, kt, SWHT);
	if (kc == KEY_I || kc == KEY_J || kc == KEY_K || kc == KEY_L)
		keys_shift(kc, v, kt);
}


void	keys_scale_status(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s =>  kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__,  kc,  kc, kt, SWHT);
	if (kc == KEY_X || kc == KEY_Y || kc == KEY_Z
		|| kc == KEY_PLUS || kc == KEY_MINUS)
		keys_scale(kc, v, kt);
}

void	keys_zoom_status(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s => kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__, kc, kc, kt, SWHT);

	if (kc == KEY_O || kc == KEY_P || kc == KEY_C)
		keys_zoom(kc, v, kt);
}

void	toggle_key(int kc, t_v *v, int kt)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s => kc = %c(%#x), Toggle = %d%s\n", SYLW, SYLW, __func__, kc, kc, kt, SWHT);
	keys_rot_status(kc, v, kt);
	keys_shift_status(kc, v, kt);
	keys_scale_status(kc, v, kt);
	keys_zoom_status(kc, v, kt);
	//keys_show(v);
}

