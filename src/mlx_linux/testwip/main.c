/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/18 00:31:21 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include	"mlx.h"
//#include	"mlx_int.h"
#include	"myfdf.h"

int		abs_i(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_abs(double *n)
{
	if (*n < 0)
		*n = *n * (-1);
	return ;
}

double	abs_d(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		max_i(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int 	min_i(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char 	sign_d(double n)
{
	if (n < 0)
		return (-1);
	return (1);
}

int		my_round(double n)
{
	if ((sign_d(n) * (n - (int)n)) >= 0.5)
		return ((int)n + sign_d(n));
	return ((int)n);
}

int		ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

void	mlx_pixel_s(t_win_data *img, t_mlx_pixel *pixel)
{
	char	*dst;

	dst = img->addr + (pixel->y * img->ll
			+ pixel->x * (img->bpp / 8));
	*(unsigned int *)dst = pixel->color;
}

void	mlx_pixel_tester(t_win_data *img)
{
	t_mlx_pixel	pixel;

	printf(" => All Pixel ...");
	pixel.x = 0;
	while (pixel.x < FHD_SX)
	{
		pixel.y = 0;
		while (pixel.y < FHD_SY)
		{
			pixel.color = (((pixel.x * 255) / FHD_SX) << 8)
				+ (((FHD_SY - pixel.y) * 255) / FHD_SY)
				+ (((pixel.y * 255) / FHD_SY) << 16);
			mlx_pixel_s(img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	printf(" OK!!\n");
	return ;
}

void	mlx_square(t_win_data *img, t_mlx_square *sq)
{
	t_mlx_pixel	pixel;

	pixel.color = sq->color;
	pixel.x = sq->x;
	while ((pixel.x - sq->x) < sq->size)
	{
		pixel.y = sq->y;
		while ((pixel.y - sq->y) < sq->size)
		{
			mlx_pixel_s(img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	mlx_rectangle_corners(t_win_data *img, t_mlx_rect *rt)
{
	t_mlx_pixel	pixel;

	pixel.color = rt->color;
	pixel.x = rt->x;
	pixel.y = rt->y;
	mlx_pixel_s(img, &pixel);
	pixel.x = rt->x + rt->w;
	pixel.y = rt->y;
	mlx_pixel_s(img, &pixel);
	pixel.x = rt->x;
	pixel.y = rt->y + rt->h;
	mlx_pixel_s(img, &pixel);
	pixel.x = rt->x + rt->w;
	pixel.y = rt->y + rt->h;
	mlx_pixel_s(img, &pixel);
	return ;
}

void	mlx_rectangle_sides(t_win_data *img, t_mlx_rect *rt)
{
	mlx_line_r(img, &((t_mlx_line)
		{rt->x, rt->y, rt->x + rt->w, rt->y, rt->color}));
	mlx_line_r(img, &((t_mlx_line)
		{rt->x, rt->y, rt->x, rt->y + rt->h, rt->color}));
	mlx_line_r(img, &((t_mlx_line)
		{rt->x + rt->w, rt->y + rt->h, rt->x + rt->w, rt->y, rt->color}));
	mlx_line_r(img, &((t_mlx_line)
		{rt->x + rt->w, rt->y + rt->h, rt->x, rt->y + rt->h, rt->color}));
	return ;
}

void	mlx_rectangle_face(t_win_data *img, t_mlx_rect *rt)
{
	int			x;
	int			y;
	t_mlx_pixel	pixel;

	pixel.color = rt->color;
	pixel.x = rt->x;
	while ((pixel.x - rt->x) < rt->w)
	{
		pixel.y = rt->y;
		while ((pixel.y - rt->y) < rt->h)
		{
			mlx_pixel_s(img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	mlx_line_s_init(t_mlx_line *line)
{
	line->swap_xy = 0;
	line->xk = line->x0;
	line->yk = line->y0;
	line->k = 1;
	line->dx = abs_i(line->xn - line->x0);
	line->dy = abs_i(line->yn - line->y0);
	line->sdx = sign_d(line->xn - line->x0);
	line->sdy = sign_d(line->yn - line->y0);
	if (line->dy > line->dx)
		line->swap_xy = ft_swap(&line->dx, &line->dy);
	line->ek = 2 * line->dy - line->dx;
}

void	mlx_line_r(t_win_data *img, t_mlx_line *line)
{
	printf("mlx_line_r\n");
	mlx_line_s_init(line);
	mlx_pixel_s(img, &((t_mlx_pixel){line->x0, line->y0, line->color}));
	while (line->k <= line->dx)
	{
		line->k++;
		mlx_pixel_s(img, &((t_mlx_pixel){line->xk, line->yk, line->color}));
		line->yk += line->sdy * (line->swap_xy && line->ek < 0)
			+ line->sdy * !(line->ek < 0);
		line->xk += line->sdx * (!line->swap_xy && line->ek < 0)
			+ line->sdx * !(line->ek < 0);
		line->ek = (line->ek + 2 * line->dy) * (line->ek < 0)
			+ (line->ek + 2 * line->dy - 2 * line->dx) * !(line->ek < 0);
	}
}
void	mlx_line_c(t_win_data *img, t_mlx_line *l)
{
	mlx_line_r(img, &(t_mlx_line){l->x0, l->y0, l->xn, l->yn, 0});
	return ;
}

void	mlx_clock_secs_hand(t_win_data *img, t_mlx_circle *c)
{
	t_mlx_line	l;
	double		alfa;

	alfa = PI2;
	l.x0 = c->x;
	l.y0 = c->y;
	while (alfa > 0)
	{
		l.xn = (l.x0 + my_round(cos(alfa + DEG2RAD_90)
					* (c->radius - 20)));
		l.yn = (l.y0 - my_round(sin(alfa + DEG2RAD_90)
					* (c->radius - 20)));
		l.color = c->color;
		mlx_line_r(img, &l);
		mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
		usleep(1000 * 100);
		mlx_line_c(img, &l);
		alfa -= SECS_CLK_HAND;
	}
	mlx_line_r(img, &((t_mlx_line)
		{l.x0, l.y0, l.x0, l.y0 - c->radius + 20, c->color}));
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	return ;
}

void	clock_frame(t_win_data *img, int thick, t_mlx_circle *circle)
{
	int	tmp_radius;

	tmp_radius = circle->radius;
	while (thick-- > 0)
	{
		mlx_circle_(img, circle);
		circle->radius++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	return ;
}

void	mlx_clock(t_win_data *img)
{
	clock_frame(img, 16, &((t_mlx_circle)
		{(FHD_SX / 4) * 3, FHD_SY / 2, 120, CYAN}));
	mlx_clock_secs_hand(img, &((t_mlx_circle)
		{(FHD_SX / 4) * 3, FHD_SY / 2, 120, CYAN}));
	return ;
}

void	mlx_circle_(t_win_data *img, t_mlx_circle *circle)
{
	int		i;
	int		j;
	double	alfa;

	alfa = 0;
	while (alfa < PI2)
	{
		i = my_round(cos(alfa) * circle->radius);
		j = my_round(sin(alfa) * circle->radius);
		mlx_pixel_s(img, &((t_mlx_pixel){circle->x + i, circle->y - j, circle->color}));
		alfa += DEG2RAD_1 / 10;
	}
	return ;
}

void	mlx_circle_tester(t_win_data *win)
{
	int				xp;
	int				yp;
	t_mlx_circle	circle;

	xp = IM1_SX;
	yp = IM1_SY;
	circle.color = BLACK;
	circle.radius = 10;
	printf(" => Circunferences ...");
	circle.x = IM1_SX;
	circle.y = IM1_SY;
	mlx_circle_(win, &circle);
	circle.y = FHD_SY - IM1_SY;
	mlx_circle_(win, &circle);
	circle.x = FHD_SX - IM1_SX;
	mlx_circle_(win, &circle);
	circle.y = IM1_SY;
	mlx_circle_(win, &circle);
	mlx_put_image_to_window(win->mlx, win->win, win->img_ptr, 0, 0);
	printf(" OK!!\n");
	return ;
}

void	mlx_square_tester(t_win_data *win_data)
{
	t_mlx_square	sq;

	printf(" => Centered Fill Square ...");
	sq.size = IM1_SX;
	sq.x = (FHD_SX / 2) - sq.size / 2;
	sq.y = FHD_SY / 6 + sq.size / 2;
	sq.color = YELLOWGREEN;
	mlx_square(win_data, &sq);

	mlx_put_image_to_window(win_data->mlx, win_data->win,
		win_data->img_ptr, 0, 0);

	printf(" OK!!\n");
	return ;
}
void	mlx_rectangle_tester(t_win_data *win_data)
{
	t_mlx_rect	rt;

	printf(" => Rectangle ...");
	printf(" => sides ...");

	rt.w = IM1_SX;
	rt.h = IM1_SY;
	rt.x = IM1_SX;
	rt.y = IM1_SY;
	rt.color = RED;
	mlx_rectangle_sides(win_data, &rt);
	mlx_put_image_to_window(win_data->mlx, win_data->win,
		win_data->img_ptr, 0, 0);

	printf(" => face ...");
	rt.x = IM1_SX * 3;
	rt.y = IM1_SY;
	rt.color = BLUEVIOLET;
	mlx_rectangle_face(win_data, &rt);
	mlx_put_image_to_window(win_data->mlx, win_data->win,
		win_data->img_ptr, 0, 0);

	printf(" => corners ...");
	rt.x = IM1_SX * 5;
	rt.y = IM1_SY;
	rt.color = YELLOW;
	mlx_rectangle_corners(win_data, &rt);
	mlx_put_image_to_window(win_data->mlx, win_data->win,
		win_data->img_ptr, 0, 0);

	printf(" OK!!\n");
	return ;
}

void	mlx_line_tester(t_win_data *img)
{
	mlx_line_r(img, &((t_mlx_line){L_X, L_Y, L_X, L_Y + 100, WHEAT}));
	mlx_line_r(img, &((t_mlx_line){L_X, L_Y, L_X + 100, L_Y, WHEAT}));
	mlx_line_r(img, &((t_mlx_line){L_X, L_Y, L_X + 100, L_Y + 100, WHEAT}));

	mlx_line_r(img, &((t_mlx_line){L_X + 100, L_Y + 200, L_X + 100, L_Y + 100, BLUE}));
	mlx_line_r(img, &((t_mlx_line){L_X + 100, L_Y + 200, L_X, L_Y + 200, BLUE}));
	mlx_line_r(img, &((t_mlx_line){L_X + 100, L_Y + 200, L_X, L_Y + 100, BLUE}));

	// diagonals
	mlx_line_r(img, &((t_mlx_line){0, FHD_SY, FHD_SX, 0, BLUE}));
	mlx_line_r(img, &((t_mlx_line){0, 0, FHD_SX, FHD_SY, BLUE}));

	mlx_line_r(img, &((t_mlx_line){FHD_SX / 2, 0, FHD_SX, FHD_SY, RED}));
	mlx_line_r(img, &((t_mlx_line){FHD_SX / 2, 0, 0, FHD_SY, RED}));

	mlx_line_r(img, &((t_mlx_line){FHD_SX / 2, FHD_SY, FHD_SX, 0, GREEN}));
	mlx_line_r(img, &((t_mlx_line){FHD_SX / 2, FHD_SY, 0, 0, GREEN}));

	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);

	return ;
}
int	main(void)
{
	//void		*mlx_win_shd;
	t_win_data	img;
	int			sleep_time;



	printf("new version 3\n");

	printf(" => Connection ...");
	img.mlx = mlx_init();
	if (!img.mlx)
	{
		printf(" !! KO !! mlx connection failed\n");
		exit(1);
	}
	printf(" OK!! Connection active\n");

	printf(" => Window1 %dx%d \"Hello World! FHD\" ...", FHD_SX, FHD_SY);
	img.win = mlx_new_window(img.mlx, FHD_SX, FHD_SY, "Hello World! FHD");
	if (!(img.win))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf(" OK!! Window ready\n");

	printf(" => Image prepare ...");
	img.img_ptr = mlx_new_image(img.mlx, FHD_SX, FHD_SY);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp,
			&img.ll, &img.endian);
	printf(" => Image info: bpp = %d, line length =%d, endian = %d\n",
		img.bpp, img.ll, img.endian);

	mlx_pixel_tester(&img);
	sleep(SLEEP);
	mlx_line_tester(&img);
	sleep(SLEEP);
	mlx_square_tester(&img);
	sleep(SLEEP);
	mlx_rectangle_tester(&img);
	sleep(SLEEP);
	mlx_circle_tester(&img);
	sleep(SLEEP);

	printf(" => Clock with circunference frame ...\n");

	//img.color = TEAL;
	mlx_clock(&img);
	printf(" OK!!\n");

	mlx_loop(img.mlx);
}
/* more examples
	printf(" => Window1 %dx%d \"Hello World! SHD\" ...", SHD_SX, SHD_SY);
	mlx_win_shd = mlx_new_window(mlx, SHD_SX, SHD_SY, "Hello World! SHD");
	if (!(mlx_win_shd))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf(" OK!! Window ready\n");
*/