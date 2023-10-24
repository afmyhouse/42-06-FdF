/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:50:37 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/21 20:22:00 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx.h"
#include	"mlx_int.h"
#include	"mlx_test.h"


// int	expose_win1(void *p)
// {
// 	mlx_string_put(gmlx, gwptr_1, 5, WSY / 2 - 10, 0x99FF, "IMAGE 3");
// 	sleep(5);
// 	mlx_put_image_to_window(gmlx, gwptr_1, giptr_3, 0, 0);
// }
int	expose_win1(t_wd *wd)
{
	mlx_string_put(wd->smlx, wd->swin, 5, WSY / 2 - 10, 0x99FF, "IMAGE 3");
	sleep(5);
	mlx_put_image_to_window(wd->smlx, wd->swin, giptr_3, 0, 0);
}

int	expose_win2(void *p)
{
	mlx_string_put(gmlx, gwptr_2, 5, WSY / 2 - 10, 0x99FF, "IMAGE 4");
	sleep(5);
	mlx_put_image_to_window(gmlx, gwptr_2, giptr_4, 0, 0);
	mlx_string_put(gmlx, gwptr_2, 5, WSY / 2 - 10, 0x99FF, "IMAGE 2");
	sleep(5);
	mlx_put_image_to_window(gmlx, gwptr_2, giptr_2, 0, 0);
}

int	key_win1(int key, void *p)
{
	printf("Key in Window 1 : %d\n", key);
	if (key == 0xFF1B)
		exit (0);
}

int	key_win2(int key, void *p)
{
	printf("Key in Window 2 : %x\n", key);
	if (key == 0xFF1B)
		exit (0);
}

int	key_win3(int key, void *p)
{
	printf("Key in Window 3 : %x\n", key);
	if (key == 0xFF1B)
		mlx_destroy_window(gmlx, gwptr_3);
}

int	mouse_win1(int button, int x, int y, void *p)
{
	printf("Mouse in Window 1, button %d at %dx%d.\n", button, x, y);
}

int	mouse_win2(int button, int x, int y, void *p)
{
	printf("Mouse in Window 2, button %d at %dx%d.\n", button, x, y);
}

int	mouse_win3(int x, int y, void *p)
{
	printf("Mouse moving in Window 3, at %dx%d.\n", x, y);
}


int	main()
{
	int		a;
	t_wd	*wd;
	t_img	*img;
	void	*gmlx;

		printf("MinilibX Test Program\n");
	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		l_endian = 1;
	else
			l_endian = 0;
	printf(" => Local Endian : %d : a = %#x : a[0] = %x\n", l_endian, a, ((unsigned char *)&a)[0]);

	wd = (t_wd *)malloc(sizeof(t_wd));
	printf(" => Connection ...");
	gmlx = mlx_init();
	if (!gmlx)
	{
		printf(" !! KO !!\n");
		exit (1);
	}
	printf("OK (use_xshm %d pshm_format %d)\n\n", ((t_xvar *)gmlx)->use_xshm, ((t_xvar *)gmlx)->pshm_format);

	wd = (t_wd *)malloc(sizeof(t_wd));
	wd->smlx = gmlx;
// ************************************************************************
//	CREATE WINDOW 1
// ************************************************************************
	printf(" => Window1 %dx%d \"Title 1\" ...", WSX, WSY);
	gwptr_1 = mlx_new_window(gmlx, WSX, WSY, "Title1");
	if (!(gwptr_1))
	{
		printf(" !! KO !!\n");
		exit (1);
	}
	printf("gwptr_1) = %p\n", gwptr_1);
	printf("OK\n");
// ************************************************************************
//	WINDOW 1 TEST :
//	Fill DIRECT to WINDOW by using the mlx_pixel_put function
// ************************************************************************
	mlx_test_fill_win(gmlx, gwptr_1, WSX, WSY);

// ************************************************************************
//	WINDOW 1 TEST : size is part of the window destination size
//	Fill IMAGE MEMORY with pixel info and dump to WINDOW
//	First the image is create din memory pointed by img-ptr and then
//	it is dumped into the window at position (X, Y)
// ************************************************************************
	mlx_test_fill_img_part(gmlx, gwptr_1, IM1_SX, IM1_SY);

// ************************************************************************
//	WINDOW 1 TEST 002 : Fill IMAGE MEMORY with pixel info and dump to WINDOW
// ************************************************************************
	mlx_test_fill_img_full(gmlx, gwptr_1, IM3_SX, IM3_SY);

// ************************************************************************
//	WINDOW 1 TESTS : STRING OUTPUT
// ************************************************************************
	printf("003 *********************************************************\n");
	printf(" => String ...");
	mlx_string_put(gmlx, gwptr_1, 5, WSY / 2 - 10, 0x99FF, "String output");
	mlx_string_put(gmlx, gwptr_1, 5, WSY / 2 + 10, 0xFF, "MinilibX test");
	printf("OK\n\n");
	sleep(2);

// ************************************************************************
//	WINDOW 1 TESTS : Fill IMAGE MEMORY with pixel info and dump to WINDOW
// ************************************************************************
	printf("004 *********************************************************\n");
	printf(" => Xpm from file ...");
	sleep(2);
	giptr_2 = mlx_xpm_file_to_image(gmlx, "open.xpm", &gxpm1_x, &gxpm1_y);
	if (!(giptr_2))
	{
		printf(" !! KO !!\n");
		exit (1);
	}
	gdata2 = mlx_get_data_addr(giptr_2, &gbpp2, &gsl2, &gendian2);
	printf(" \t=> image xpm data address %p\n", gdata2);
	printf(" \t\t=>[xpm : %dx%d][ gbpp2: %d, sizeline3: %d gendian3: %d type: %d ]\n", gxpm1_x, gxpm1_y, gbpp2, gsl2,
		gendian2, ((t_img *)giptr_3)->type);
	sleep(2);
	printf(" => Put xpm ...");
	mlx_put_image_to_window(gmlx, gwptr_1, giptr_2, 0, 0);
	//mlx_put_image_to_window(gmlx, gwptr_1, giptr_2, (WSX / 2 - gxpm1_x / 2), (WSY / 2 - gxpm1_y / 2));
	printf("OK\n");
	sleep(5);


// ************************************************************************
//	WINDOW 1 TESTS : Fill IMAGE MEMORY with pixel info and dump to WINDOW
// ************************************************************************
	printf("005 *********************************************************\n");
	printf(" => 2nd window, ");
	mlx_string_put(gmlx, gwptr_1, 5, 10, 0xFFFFFF, " => 2nd window ...");
	gwptr_2 = mlx_new_window(gmlx, WSX, WSY, "Title2");
	if (!(giptr_4 = mlx_new_image(gmlx, IM3_SX, IM3_SY)))
	{
		printf(" !! KO !!\n");
		exit (1);
	}
	printf("OK\n \t=> Image4 address %p\n", giptr_4);
	sleep(2);
// GET info about the STRUCTURE of IMAGE MEMORY AREA
	gdata4 = mlx_get_data_addr(giptr_4, &gbpp4, &gsl4, &gendian4);
	printf(" \t=> image data address %p\n", gdata4);
	printf(" \t\t=>[ gbpp3: %d, sizeline3: %d gendian4: %d type: %d ]\n", gbpp4, gsl4,
		gendian4, ((t_img *)giptr_4)->type);
	fill_img_grade(gmlx, gdata4, gbpp4, gsl4, IM3_SX, IM3_SY, gendian4, 2);
	sleep(5);


// ************************************************************************
//	WINDOW 1 TESTS : Fill IMAGE MEMORY with pixel info and dump to WINDOW
// ************************************************************************
	printf("005 *********************************************************\n");
	printf(" 3rd window, Installing hooks ...");
	gwptr_3 = mlx_new_window(gmlx, WSX, WSY, "Title3");
	//mlx_expose_hook(gwptr_1, expose_win1, gmlx);
	mlx_expose_hook(gwptr_1, expose_win1, wd);
	mlx_mouse_hook(gwptr_1, mouse_win1, 0);
	mlx_key_hook(gwptr_1, key_win1, 0);
	mlx_expose_hook(gwptr_2, expose_win2, 0);
	mlx_mouse_hook(gwptr_2, mouse_win2, 0);
	mlx_key_hook(gwptr_2, key_win2, 0);
	mlx_key_hook(gwptr_3, key_win3, 0);

	mlx_hook(gwptr_3, MotionNotify, PointerMotionMask, mouse_win3, 0);

	printf("OK\nNow in Loop. Just play. Esc in 3 to destroy, 1&2 to quit.\n");

	mlx_loop(gmlx);
}


/// @brief 		mlx_test_fill_win walktrough
/// @details		mlx_test_fill_win walktrough
///				-# Fill window background with grade COLOR
///				-# Fill window background with BLUE
///				-# Fill window background with GREEN
///				-# Fill window background with RED
///				-# Clear window background = BLACK
/// @param
void	mlx_test_fill_win(void *fmlx, void *win, int w, int h)
{
	printf("000 ********************************************************\n");
	printf("0001 *******************************************************\n");
	printf(" \t=> Fill direct window background GRADE ...");
	sleep(TIMER1);
	fill_win_grade(fmlx, win, w, h);
	printf("OK\n");

	printf(" \t=> Fill direct window background WHITE...");
	sleep(TIMER1);
	fill_win_color(fmlx, win, w, h, 0x00FFFFFF);
	printf("OK\n");

	printf(" \t=> Fill direct window background BLUE...");
	sleep(TIMER1);
	fill_win_color(fmlx, win, w, w, 0x000000FF);
	printf("OK\n");

	printf(" \t=> Fill direct window background GREEN...");
	sleep(TIMER1);
	fill_win_color(fmlx, win, w, w, 0x0000FF00);
	printf("OK\n");

	printf(" \t=> Fill direct window background RED...");
	sleep(TIMER1);
	fill_win_color(fmlx, win, w, w, 0x00FF0000);
	printf("OK\n");

	printf(" \t=> Clear Window = BACKGROUND BLACK...");
	sleep(TIMER1);
	mlx_clear_window(fmlx, win);
	printf("OK\n\n");
	sleep(TIMER2);
}
/// @brief 		mlx_test_fill_img_part walktrough
/// @details		mlx_test_fill_img_part walktrough
///				-# Create a image memory pointer = mlx_new_image(...)
///				-# Get info about the structure of image memory area
///				-# Fill pixel into image memory area according to its structure
///				-# Fill window background with image memory area
///				-# Destroy image memory area
/// @param		void
void	mlx_test_fill_img_part(void *fmlx, void *win, int w, int h)
{
	printf("001 *********************************************************\n");
// GET a pointer to IMAGE MEMORY AREA
	printf(" => Image1 ZPixmap %dx%d ...", w, h);
	sleep(TIMER1);
	mlx_string_put(fmlx, win, 20, 10, 0xFFFFFF, "=> Image1 ZPixmap");
	sleep(TIMER1);

	giptr_1 = mlx_new_image(fmlx, w, h);
	if (!giptr_1)
	{
		printf(" !! KO !!\n");
		exit (1);
	}
	printf("OK\n \t=> Image1 address %p\n", giptr_1);
	sleep(TIMER1);

// GET info about the STRUCTURE of IMAGE MEMORY AREA
	gdata1 = mlx_get_data_addr(giptr_1, &gbpp1, &gsl1, &gendian1);
	printf(" \t=> image data address %p\n", gdata1);
	printf(" \t\t=>[ gbpp1: %d, sizeline1: %d gendian1: %d type: %d ]\n", gbpp1, gsl1,
		gendian1, ((t_img *)giptr_1)->type);
// FILL pixel into IMAGE MEMORY AREA according to its STRUCTURE
	printf(" \t=> Fill Image1 MEMORY... size (w,h) = (%i,%i)\n", IM1_SX, IM1_SY);
	sleep(TIMER1);
	fill_img_grade(fmlx, gdata1, gbpp1, gsl1, IM1_SX, IM1_SY, gendian1, 1);
	printf(" \t=> OK (pixmap : %d)\n", (int)((t_img *)giptr_1)->pix);
// FILL WINDOW BACKGROUND with IMAGE MEMORY AREA
	printf(" \t=> Put Image1 ...@ x,y = %i,%i...", 60, 60);
	sleep(TIMER1);
	mlx_put_image_to_window(gmlx, gwptr_1, giptr_1, 60, 60);
	printf("OK\n");
// FILL WINDOW BACKGROUND with IMAGE MEMORY AREA
	printf(" \t=> Put Image1 ...@ x,y = %i,%i...", 30, 30);
	sleep(TIMER1);
	mlx_put_image_to_window(gmlx, gwptr_1, giptr_1, 30, 30);
	printf("OK\n");
	printf(" \t=> Destroy Image1 ... ");
	sleep(TIMER1);
	mlx_destroy_image(gmlx, giptr_1);
	printf("OK\n\n");
	sleep(TIMER2);
}

/// @brief 		mlx_test_fill_img_full walktrough
/// @details		mlx_test_fill_img_full walktrough
///				-# Create a image memory pointer = mlx_new_image(...)
///				-# Get info about the structure of image memory area
///				-# Fill pixel into image memory area according to its structure
///				-# Fill window background with image memory area
///				-# Destroy image memory area
/// @param
void	mlx_test_fill_img_full(void *fmlx, void *win, int w, int h)
{
	printf("002 *********************************************************\n");
	printf(" => Image3 ZPixmap %dx%d ...", w, h);
	sleep(TIMER1);
	mlx_string_put(fmlx, win, 20, 10, 0xFFFFFF, "=> Image3 ZPixmap");
	sleep(TIMER1);
	giptr_3 = mlx_new_image(fmlx, w - 40, h - 40);
	if (!(giptr_3))
	{
		printf(" !! KO !!\n");
		exit (1);
	}
	printf("OK\n \t=> Image3 address %p\n", giptr_3);
	sleep(TIMER1);
// GET info about the STRUCTURE of IMAGE MEMORY AREA
	gdata3 = mlx_get_data_addr(giptr_3, &gbpp3, &gsl3, &gendian3);
	printf(" \t=> image data address %p\n", gdata3);
	printf(" \t\t=>[ gbpp3: %d, sizeline3: %d gendian3: %d type: %d ]\n", gbpp3, gsl3,
		gendian3, ((t_img *)giptr_3)->type);
	sleep(TIMER1);
// FILL pixel into IMAGE MEMORY AREA according to its STRUCTURE
	printf(" \t=> Fill Image3 MEMORY... size (w,h) = (%i,%i)\n", w, h);
	fill_img_grade(fmlx, gdata3, gbpp3, gsl3, w - 40, h - 40, gendian3, 1);
	printf(" \t=> OK (pixmap : %d)\n", (int)((t_img *)giptr_3)->pix);
	sleep(TIMER1);
// FILL WINDOW BACKGROUND with IMAGE MEMORY AREA
	printf(" \t=> Put Image3 ...@ x,y = %i,%i...", 20, 20);
	mlx_put_image_to_window(fmlx, win, giptr_3, 20, 20);
	printf("OK\n");
	sleep(TIMER1);
// FILL WINDOW BACKGROUND with IMAGE MEMORY AREA
	printf(" \t=> Put Image1 ...@ x,y = %i,%i...", 40, 40);
	mlx_put_image_to_window(fmlx, win, giptr_3, 40, 40);
	printf("OK\n\n");
	sleep(TIMER2);
}
