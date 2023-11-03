/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:49:28 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/03 01:36:53 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONSTANTS_H
# define FDF_CONSTANTS_H

/* ************************************************************************** */
///	ERROR CODES
/* ************************************************************************** */
# ifndef ERROR
#  define ERROR 1
# endif
# ifndef SUCCESS
#  define SUCCESS 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# ifndef MALLOC_ERROR
#  define MALLOC_ERROR 10
# endif
# ifndef MAP_ERROR
#  define MAP_ERROR 50
# endif
# ifndef MLX_ERROR
#  define MLX_ERROR 51
# endif
# ifndef ARGS_ERROR
#  define ARGS_ERROR 52
# endif
# ifndef PROCESS_ERROR
#  define PROCESS_ERROR 53
# endif
# ifndef MATRIX_ERROR
#  define MATRIX_ERROR 54
# endif
# ifndef COLOR_ERROR
#  define COLOR_ERROR 55
# endif
# ifndef BONUS_ERROR
#  define BONUS_ERROR 56
# endif

/* ************************************************************************** */
///	FILE ERROR CODES and STATUS
/* ************************************************************************** */
# ifndef FILE_EMPTY
#  define FILE_EMPTY 20
# endif
# ifndef FILE_ERROR
#  define FILE_ERROR 21
# endif
# ifndef FILE_NOT_FOUND
#  define FILE_NOT_FOUND 22
# endif
# ifndef FILE_NOT_READABLE
#  define FILE_NOT_READABLE 23
# endif
# ifndef FILE_NOT_VALID
#  define FILE_NOT_VALID 24
# endif
# ifndef FILE_NOT_OPEN
#  define FILE_NOT_OPEN 25
# endif
# ifndef FILE_NOT_CLOSED
#  define FILE_NOT_CLOSED 26
# endif
# ifndef FILE_NOT_WRITABLE
#  define FILE_NOT_WRITABLE 27
# endif
# ifndef FILE_NOT_CREATED
#  define FILE_NOT_CREATED 28
# endif
# ifndef FILE_NOT_DELETED
#  define FILE_NOT_DELETED 29
# endif
# ifndef FILE_NOT_RENAMED
#  define FILE_NOT_RENAMED 30
# endif
# ifndef FILE_NOT_COPIED
#  define FILE_NOT_COPIED 31
# endif
# ifndef FILE_NOT_MOVED
#  define FILE_NOT_MOVED 32
# endif
# ifndef FILE_NOT_EXECUTABLE
#  define FILE_NOT_EXECUTABLE 33
# endif
# ifndef FILE_NOT_EXECUTED
#  define FILE_NOT_EXECUTED 34
# endif

/* ************************************************************************** */
///	MATH TRIGNOMETRY CONSTANTS
/* ************************************************************************** */

# ifndef M_PI
#  define M_PI 1.57079632678
# endif

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# ifndef PI2
#  define PI2 6.28318530717958647692
# endif

# ifndef DEG2RAD_1
#  define DEG2RAD_1 0.001745329252
# endif

# ifndef DEG2RAD_90
#  define DEG2RAD_90 1.57079632678
# endif

# ifndef DEG2RAD_180
#  define DEG2RAD_180 3.14159265359
# endif

# ifndef DEG2RAD_135
#  define DEG2RAD_135 2.35619449019
# endif

# ifndef DEG2RAD_325
#  define DEG2RAD_325 5.67232006898
# endif

# ifndef DEG2RAD_120
#  define DEG2RAD_120 2.09439510239
# endif

# ifndef U30DEG
#  define U30DEG 0.52359877559
# endif
# ifndef U45DEG
#  define U45DEG 0.78539816339
# endif
# ifndef U35DEG
#  define U35DEG 0.6108652382
# endif
# ifndef U60DEG
#  define U60DEG 1.0471975512
# endif
# ifndef U90DEG
#  define U90DEG 1.57079632678
# endif

/* ************************************************************************** */
///	TIME DEFINITIONS TO MAKE THE VISUALIZATION MORE PLEASANT
/* ************************************************************************** */

# ifndef MYTIME
#  define MYTIME 0
# endif

# ifndef UMYTIME
#  define UMYTIME 10000
# endif

/* ************************************************************************** */
///	LIMITS FOR SCALING
/* ************************************************************************** */

# ifndef USCALE
#  define USCALE 0.01
# endif
# ifndef USCALE_ALIGN
#  define USCALE_ALIGN 0.5
# endif
# ifndef USCALE_PRSPTV
#  define USCALE_PRSPTV 0.1
# endif
# ifndef USCALE_LL
#  define USCALE_LL 0.0
# endif
# ifndef USCALE_UL_ALIGN
#  define USCALE_UL_ALIGN 5
# endif
# ifndef USCALE_UL_PRSPTV
#  define USCALE_UL_PRSPTV 0.7
# endif

/* ************************************************************************** */
///	LIMITS FOR SHIFTING
/* ************************************************************************** */

# ifndef USHIFT
#  define USHIFT 0.2
# endif
# ifndef USHIFT_MIN
#  define USHIFT_MIN 0.0
# endif

/* ************************************************************************** */
///	LIMITS AND CONSTANTS FOR ROTATION
/* ************************************************************************** */

# ifndef UALFA
#  define UALFA 0.05
# endif
# ifndef U_IALFA_MIN
#  define U_IALFA_MIN 0.05
# endif
# ifndef U_IALFA_MAX
#  define U_IALFA_MAX 0.5
# endif

# ifndef UFOCAL_I
#  define UFOCAL_I 1
# endif

# ifndef UFOCAL_UL
#  define UFOCAL_UL 5
# endif

/* ************************************************************************** */
///	WINDOW OBJECTS
/* ************************************************************************** */
# define WIN_W 1200
# define WIN_H 1200

# define F_SX	640
# define F_SY	360
# define D_SX	1280
# define D_SY	720
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
# define MENU_W	100
# define BUTTON_W	40
# define BUTTON_H	16

#endif
