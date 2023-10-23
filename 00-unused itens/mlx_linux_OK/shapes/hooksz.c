/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:11 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/20 16:11:39 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mlx.h"
// #include	"mlx_int.h"
#include "testz.h"

int	expose_win1(void *p)
{
	mlx_put_image_to_window(mlx, win1, im3, 0, 0);
}

int	expose_win2(void *p)
{
	mlx_put_image_to_window(mlx, win2, im4, 0, 0);
	mlx_put_image_to_window(mlx, win2, im2, 0, 0);
}

int	key_win1(int key, void *p)
{
	printf("Key in Win1 : %d\n", key);
	if (key == 0xFF1B)
		exit(0);
}

int	key_win2(int key, void *p)
{
	printf("Key in Win2 : %d\n", key);
	if (key == 0xFF1B)
		exit(0);
}

int	key_win3(int key, void *p)
{
	printf("Key in Win3 : %d\n", key);
	if (key ==0 xFF1B)
		mlx_destroy_window(mlx, win3);
}

int	mouse_win1(int button, int x, int y, void *p)
{
	printf("Mouse in Win1, button %d at %dx%d.\n", button, x, y);
}

int	mouse_win2(int button, int x, int y, void *p)
{
	printf("Mouse in Win2, button %d at %dx%d.\n", button, x, y);
}

int	mouse_win3(int x, int y, void *p)
{
	printf("Mouse moving in Win3, at %dx%d.\n", x, y);
}

