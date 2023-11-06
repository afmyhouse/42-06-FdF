/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:59:13 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 00:30:21 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

# include "math.h"
# include "../minilibx/mlx.h"
# include "keys.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

// # define WIN_W 1600
// # define WIN_H 1200

# ifndef PI
#  define PI 3.14159265358979323846
# endif

// # ifndef M_PI
// #  define M_PI 1.57079632678
// # endif

# ifndef MY_DEBUG
#  define MY_DEBUG 1
# endif
/* ************************************************************************** */
///	STRINGS COLORS
/* ************************************************************************** */
# define SRED "\033[0;31m"
# define SGRN "\033[0;32m"
# define SYLW "\033[0;33m"
# define SBLU "\033[0;34m"
# define SPPL "\033[0;35m"
# define SCYN "\033[1;36m"
# define SWHT "\033[0m"
# define SBOLD "\033[1;1m"

typedef int		t_color;

typedef struct s_2d
{
	float		x;
	float		y;
}				t_2d;

typedef struct s_3d
{
	float		x;
	float		y;
	float		z;
}				t_3d;

typedef struct s_vx
{
	t_3d		*origin;
	t_3d		*world;
	t_3d		*aligned;
	t_3d		*projected;
	t_color		color;
}				t_vx;

typedef struct s_v
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	char		*caption;
	char		*file;
	void		*img;
	int			img_bipp;
	int			img_bypp;
	int			img_sl;
	int			img_edn;
	char		*pixels;
	t_vx		***points;
	t_color		*colors;
	int			num_colors;
	int			width;
	int			height;
	int			z_min;
	int			z_max;
	float		theta;
	float		phi;
	float		psi;
	float		i_alfa;
	float		x_scale;
	float		y_scale;
	float		z_scale;
	float		scale;
	float		i_scale;
	float		max_scale;
	float		x_sh;
	float		y_sh;
	float		z_sh;
	float		i_shift;
	float		r;
	float		g;
	float		b;
	int			focal_dist;
	t_keys		*keys;
	int			project;
	char		err;
	int			color;
}				t_v;

//void			toggle_key(int keycode, t_v *v, int toggle);
void			plot_image(t_v *v);
void			create_image(t_v *v);

//void			init_color_table(t_v *v, int colors);

void			mx_zero(float mat[4][4]);
void			mx_id(float mat[4][4]);

void			v_mx_mul(t_3d *src, float mat[4][4], t_3d *dst);

void			mx_mul(float m1[4][4], float m2[4][4], float p[4][4]);
void			mx_t(float p[4][4], float x, float y, float z);
void			mx_s(float p[4][4], float x, float y, float z);
void			mx_r(float p[4][4], float theta, float phi, float psi);

void			plot_point_to_pixel(t_v *v, int x, int y, float z);
void			plot_line_to_pixel(t_v *v, t_3d p0, t_3d p1);
void			plot_line_to_img(t_v *v, t_3d p0, t_3d p1);

t_2d			*set_vx_2d(float x, float y);
t_3d			*set_vx_3d(float x, float y, float z);
t_vx			*set_vx(float x, float y, float z);

#endif
