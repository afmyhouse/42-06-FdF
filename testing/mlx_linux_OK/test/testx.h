/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:59:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/20 17:28:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTX_H
# define TESTX_H

# include "mlx.h"
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

//int	color_map_1(void *win, int w, int h);
int	color_map_1(void *win, int w, int h);
int	color_map_1x(t_wdata *wd, int w, int h);
//int	color_map_2(unsigned char *data, int bpp, int sl, int w, int h, int endian,  int type, int local_endian);
int	color_map_2(unsigned char *data, int bpp, int sl, int w, int h, int endian, int type);
int	color_map_2z(t_wdata *wd, int local_endian);

#endif
