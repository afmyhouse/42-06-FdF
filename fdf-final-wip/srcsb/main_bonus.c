/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/05 01:48:34 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_v	*v;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		return (0);
	}
	v = init_v();
	v->file = argv[1];
	parse_file(v, argv[1]);
	fdf(v);
}
