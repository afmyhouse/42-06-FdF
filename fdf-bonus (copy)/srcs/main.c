/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/31 14:40:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	// if (MY_DEBUG)
	// 	ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	t_v	*view;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		return (0);
	}
	view = init_v();
	parse_file(view, argv[1]);
	fdf(view);
	// if (MY_DEBUG)
	// 	ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
// 	// if (MY_DEBUG)
// 	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
// 	// if (MY_DEBUG)
// 	// 	ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);