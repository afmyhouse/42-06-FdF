/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/31 10:09:53 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	hooks_setting(t_v *v)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);

	//mlx_expose_hook(v->win, expose_hook, v);

	mlx_do_key_autorepeatoff(v->mlx);

	mlx_hook(v->win, KeyPress, KeyPressMask, key_press_hook, v);

	mlx_hook(v->win, KeyRelease, KeyReleaseMask, key_release_hook, v);

	mlx_hook(v->win, DestroyNotify, 0, exit_hook, v);

	mlx_loop_hook(v->mlx, my_loop_hook, v);

	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}

int	main(int argc, char **argv)
{
	if (MY_DEBUG)
		ft_printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	t_v	*v;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		return (0);
	}
	v = init_v();
	parse_file(v, argv[1]);
	fdf(v);
	if (MY_DEBUG)
		ft_printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
// 	// if (MY_DEBUG)
// 	// 	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
// 	// if (MY_DEBUG)
// 	// 	ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);