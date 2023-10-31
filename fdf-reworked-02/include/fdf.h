/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 20:13:58 by myoung            #+#    #+#             */
/*   Updated: 2023/10/31 15:18:40 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"
# include "../libft/gnl.h"
# include "../libgfx/libgfx.h"
# include "fdf_constants.h"
# include "debug.h"
# include "colors.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

void	fdf(t_v *view);
void	parse_file(t_v *view, char *filename);

int		mouse_hook(int button, int x, int y, t_v *view);
int		exit_hook(t_v *view);
void	hooks_setting(t_v *view);

void	plot_perspective(t_v *view);

t_v		*init_v(void);
void	create_color_range(t_v *view, int colors);
void	color_hook(t_v *view);
//void	zoom_hook(t_view *view);
void	shift_hook(t_v *view);
void	scale_hook(t_v *view);
void	rotate_hook(t_v *v);

int		key_press_hook(int keycode, t_v *view);
int		key_release_hook(int keycode, t_v *view);
int		expose_hook(t_v *view);
int		my_loop_hook(t_v *view);

void	full_plot(t_v *view);
void	plot_update(t_v *view);
void	original_to_window(t_v *view);
void	window_to_aligned(t_v *view);
void	aligned_to_projected(t_v *view);
void	plot_flat(t_v *view);
void	plot_perspective(t_v *view);

void	keys_init(t_v *view);
void	keys_show(t_v *v);

void	keys_rot_alfa(int kc, t_v *v, int kt);
void	keys_shift_arrow(int kc, t_v *v, int kt);
void	keys_shift(int kc, t_v *v, int kt);
void	keys_scale(int key, t_v *v, int kt);
void	keys_zoom(int kc, t_v *v, int kt);

void	keys_rot_status(int kc, t_v *v, int kt);
void	keys_shift_status(int kc, t_v *v, int kt);
void	keys_scale_status(int key, t_v *v, int kt);
void	keys_zoom_status(int kc, t_v *view, int kt);
void	toggle_key(int keycode, t_v *view, int toggle);
void	init_iso(t_v *v);
void	init_flat(t_v *v);
void	focal_hook(t_v *v);
void	mx_show(float mx[4][4], char *str);
void	vertex_show(t_v *v);

#endif
