/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/24 22:13:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

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
#endif
