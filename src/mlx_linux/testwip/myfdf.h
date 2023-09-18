/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:33:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/18 00:34:20 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFDF_H
# define MYFDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <time.h>

# include "../mlx.h"
# include "../mlx_int.h"
# include "colors.h"
# include "keys.h"
# include "fdf_constants.h"

# define FHD_SX	1080
# define FHD_SY	720
# define SHD_SX	640
# define SHD_SY	480
# define IM1_SX	50
# define IM1_SY	50
# define IM3_SX	242
# define IM3_SY	242
# define L_X	50
# define L_Y	150
# define L_S	100
# define SLEEP	1

/* ************************************************************************** */
///	STRUCTS
/* ************************************************************************** */
typedef struct s_win_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		width;
	int		height;
	int		color;
}				t_win_data;

typedef struct s_mlx_pixel
{
	int		x;
	int		y;
	int		color;
}				t_mlx_pixel;

typedef struct s_mlx_line
{
	int		x0;
	int		y0;
	int		xn;
	int		yn;
	int		color;
	int		dx;
	int		dy;
	int		sdx;
	int		sdy;
	int		ek;
	int		swap_xy;
	int		xk;
	int		yk;
	int		k;
}				t_mlx_line;

typedef struct s_mlx_circle
{
	int		x;
	int		y;
	int		radius;
	int		color;
}				t_mlx_circle;

typedef struct s_mlx_square
{
	int		x;
	int		y;
	int		size;
	int		color;
}				t_mlx_square;

typedef struct s_mlx_rect
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		color;
}				t_mlx_rect;

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

/* ************************************************************************** */
///	FUNCTIONS PROTOTYPES
/* ************************************************************************** */
void			mlx_pixel(t_win_data *img, int x, int y, int color);
void			mlx_pixel_s(t_win_data *img, t_mlx_pixel *pixel);

void			mlx_square(t_win_data *img, t_mlx_square *square);

// void			mlx_line(t_win_data *img, int x0, int y0,
// 					int xn, int yn, int color);
void			mlx_line_(t_win_data *img, t_mlx_line *line);
void			mlx_line_s(t_win_data *img, t_mlx_line *line);
void			mlx_line_r(t_win_data *img, t_mlx_line *line);
void			mlx_circle(t_win_data *img);
void			mlx_circle_g(t_win_data *img);
void			mlx_circle_(t_win_data *img, t_mlx_circle *circle);

void			mlx_secs_hand(t_win_data *img);
void			mlx_clock_secs_hand_s(t_win_data *img, t_mlx_circle *circle);
void			mlx_clock(t_win_data *img);

void			mlx_line_tester(t_win_data *img);
int				abs_i(int n);
void			ft_abs(double *n);
double			abs_d(double n);
int				max_i(int a, int b);
int				min_i(int a, int b);
char			sign_d(double n);
int				my_round(double n);


/* ************************************************************************** */
/// colors
int				create_trgb_c(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
unsigned char	get_t_c(int trgb);
unsigned char	get_r_c(int trgb);
unsigned char	get_g_c(int trgb);
unsigned char	get_b_c(int trgb);
int				create_trgb_i(int t, int r, int g, int b);
int				get_t_i(int trgb);
int				get_r_i(int trgb);
int				get_g_i(int trgb);
int				get_b_i(int trgb);

#endif
