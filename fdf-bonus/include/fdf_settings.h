/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:49:28 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/03 11:21:25 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_SETTINGS_H
# define FDF_SETTINGS_H

/* ************************************************************************** */
///	WINDOW OBJECTS
/* ************************************************************************** */
# define WIN_W 800
# define WIN_H 800

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
#  define USHIFT 1
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
#  define UFOCAL_UL 10
# endif

#endif
