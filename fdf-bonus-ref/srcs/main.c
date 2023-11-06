/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 22:08:21 by antoda-s         ###   ########.fr       */
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
	parse_file(v, argv[1]);
	fdf(v);
}
