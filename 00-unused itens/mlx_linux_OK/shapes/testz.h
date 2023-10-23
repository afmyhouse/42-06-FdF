/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testz.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:59:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/20 17:28:40 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTZ_H
# define TESTZ_H

# include	"mlx.h"
# include	"mlx_int.h"

# define WIN1_SX 242
# define WIN1_SY 242
# define IM1_SX 42
# define IM1_SY 42
# define IM3_SX 242
# define IM3_SY 242
# define TYPE 1
# define SL_TIME 1

/* ************************************************************************** */
///	DEBUG
/* ************************************************************************** */
# define DBG 1

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
# define SITLC "\033[3;3m"
# define SUNDL "\033[4;1m"
# define SBLNK "\033[5;1m"

void	*mlx;
void	*win1;
void		*win2;
void		*win3;
void		*im1;
void	*im2;
void	*im3;
void	*im4;
int	bpp1;
int	bpp2;
int	bpp3;
int	bpp4;
int	sl1;
int	sl2;
int	sl3;
int	sl4;
int	endian1;
int	endian2;
int	endian3;
int	endian4;
char	*data1;
char	*data2;
char	*data3;
char	*data4;
int	xpm1_x;
int	xpm1_y;

int	local_endian;


typedef struct s_image
{
	void	*image;
	int		bpp;
	int		sl;
	int		endian;
	char	*buffer;
	int		w;
	int		h;
	int		opp;
	int		color;
	//t_line	*line;
}	t_image;

typedef struct s_wdata
{
	void	*mlx;
	void	*win;
	t_image	*img;
}				t_wdata;

int	color_map_1(void *win, int w, int h);
//int	color_map_1(t_wdata *wd, int w, int h);
//int	color_map_2(unsigned char *data, int bpp, int sl, int w, int h, int endian,  int type, int local_endian);
//int	color_map_2(unsigned char *data, int bpp, int sl, int w, int h, int endian, int type)
//int	color_map_2(t_wdata *wd, int local_endian);
int	color_map_2(unsigned char *data, int bpp, int sl, int w, int h, int endian, int type);

int	expose_win1(void *p);
int	expose_win2(void *p);
int	key_win1(int key, void *p);
int	key_win2(int key, void *p);
int	key_win3(int key, void *p);
int	mouse_win1(int button, int x, int y, void *p);
int	mouse_win2(int button, int x, int y, void *p);
int	mouse_win3(int x, int y, void *p);


#endif
