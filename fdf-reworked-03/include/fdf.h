/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 20:13:58 by myoung            #+#    #+#             */
/*   Updated: 2023/10/28 19:40:37 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"
# include "../libft/gnl.h"
// # include "../libft/ft_printf.h"

//# include "../libgfx/include/keys.h"
# include "../libgfx/libgfx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "fdf_constants.h"
# include "debug.h"
# include "colors.h"

// typedef struct s_view
// {
// 	int		project;
// 	float	theta;
// 	float	phi;
// 	float	psi;
// 	float	scale;
// 	int		x_scale;
// 	int		y_scale;
// 	int		z_scale;
// 	float	x_shift;
// 	float	y_shift;
// 	float	z_shift;
// 	float	focal_dist;
// 	int		r;
// 	int		g;
// 	int		b;
// 	void	*id;
// 	void	*win;
// 	t_keys	*pressed;

// }	t_view;

void	fdf(t_view *view);
void	parse_file(t_view *view, char *filename);

int		mouse_hook(int button, int x, int y, t_view *view);
int		exit_hook(t_view *view);
void	hooks_setting(t_view *view);

void	draw_projected(t_view *view);

t_view	*init_v(void);
void	color_hook(t_view *view);
//void	zoom_hook(t_view *view);
void	shift_hook(t_view *view);
void	scale_hook(t_view *view);
void	rotate_hook(t_view *v);

int		key_press_hook(int keycode, t_view *view);
int		key_release_hook(int keycode, t_view *view);
int		expose_hook(t_view *view);
int		my_loop_hook(t_view *view);

void	full_redraw(t_view *view);
void	redraw(t_view *view);
void	local_to_world(t_view *view);
void	world_to_aligned(t_view *view);
void	aligned_to_projected(t_view *view);
void	draw_wireframe(t_view *view);
void	draw_projected(t_view *view);

void	keys_init(t_view *view);
void	keys_show(t_view *v);

void	keys_rot_alfa(int kc, t_view *v, int kt);
void	keys_rot_arrow(int kc, t_view *v, int kt);
void	keys_shift(int kc, t_view *v, int kt);
void	keys_scale(int key, t_view *v, int kt);
void	keys_zoom(int kc, t_view *v, int kt);

void	keys_rot_status(int kc, t_view *v, int kt);
void	keys_shift_status(int kc, t_view *v, int kt);
void	keys_scale_status(int key, t_view *v, int kt);
void	keys_zoom_status(int kc, t_view *view, int kt);
void	toggle_key(int keycode, t_view *view, int toggle);

#endif
