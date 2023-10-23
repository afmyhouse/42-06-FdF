/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:49:28 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/06 18:08:50 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONSTANTS_H
# define FDF_CONSTANTS_H
/* ************************************************************************** */
///	DEBUG
/* ************************************************************************** */
# ifndef _PRINT
#  define _PRINT 1
#  define _NOPRINT 0
# endif
# ifndef _SHOW_STACKS_
#  define _SHOW_STACKS_ 1
# endif
# ifndef _SHORT_SIZE_
#  define _SHORT_SIZE_ 5
# endif
# ifndef _DEBUG_
#  define _DEBUG_ 0
# endif
# ifndef _DEBUG_MALLOC_
#  define _DEBUG_MALLOC_ 0
# endif
# ifndef _CHUNK_
#  define _CHUNK_ 100
# endif
/* ************************************************************************** */
///	RESULTS
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
# ifndef NULL
#  define NULL 0
# endif
/* ************************************************************************** */
///	MATH
/* ************************************************************************** */
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

# ifndef SECS_CLK_HAND
#  define SECS_CLK_HAND 0.10471975512
# endif

# ifndef DEG2RAD_90
# define DEG2RAD_90 1.57079632678
# endif

#endif
