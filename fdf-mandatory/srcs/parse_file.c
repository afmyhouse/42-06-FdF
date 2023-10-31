/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/30 19:26:30 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	parse_vertex(t_v *v, int fd)
{
	char	*line;
	char	**vertex;
	int		p[3];

	line = get_next_line(fd);
	v->points = (t_vx ***)malloc(sizeof(t_vx **) * v->file_h);
	v->z_min = __INT_MAX__;
	v->z_max = -__INT_MAX__ - 1;
	p[1] = 0;
	while (line)
	{
		vertex = ft_split(line, ' ');
		v->points[p[1]] = (t_vx **)malloc(sizeof(t_vx *) * v->file_w);
		p[0] = -1;
		while (++p[0] < v->file_w)
		{
			p[2] = ft_atoi(vertex[p[0]]);
			v->points[p[1]][p[0]] = set_vx(p[0], p[1], p[2]);
			v->z_min = (v->z_min > p[2]) * p[2] + !(v->z_min > p[2]) * v->z_min;
			v->z_max = (v->z_max < p[2]) * p[2] + !(v->z_max < p[2]) * v->z_max;
		}
		line = get_next_line(fd);
		p[1]++;
	}
	free(line);
}

// static void	parse_vertex_build(t_v *v, int y, char *line)
// {
// 	char	**vertex;
// 	int		x;
// 	int		z;

// 	vertex = ft_split(line, ' ');
// 	v->points[y] = (t_vx **)malloc(sizeof(t_vx *) * v->width);
// 	x = -1;
// 	while (++x < v->width)
// 	{
// 		z = ft_atoi(vertex[x]);
// 		v->points[y][x] = set_vx(x, y, z);
// 			v->z_min = (v->z_min > z) * z + !(v->z_min > z) * v->z_min;
// 			v->z_max = (v->z_max < z) * z + !(v->z_max < z) * v->z_max;
// 	}
// 	free(vertex);
// }


// static void	parse_vertex(t_v *v, int fd)
// {
// 	char	*line;
// 	int		y;

// 	v->points = (t_vx ***)malloc(sizeof(t_vx **) * v->height);
// 	v->z_min = __INT_MAX__;
// 	v->z_max = -__INT_MAX__ - 1;
// 	y = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		parse_vertex_build(v, y, line);
// 		line = get_next_line(fd);
// 		y++;
// 	}
// 	free(line);
// }

static void	file_check(t_v *v, int fd)
{
	char	*line;
	char	**vertex;
	int		width;

	line = get_next_line(fd);
	v->file_h = 0;
	v->file_w = 0;
	while (line)
	{
		vertex = ft_split(line, ' ');
		width = 0;
		while (vertex[width])
			width++;
		if (v->file_w != 0 && v->file_w != width)
		{
			ft_printf("Found wrong line length. Exiting.\n");
			ft_printf("Expected %d, got %d.\n", v->file_w, width);
			ft_printf("Line: %d : %s\n", v->file_h + 1, line);
			exit(0);
		}
		v->file_w = width;
		v->file_h++;
		line = get_next_line(fd);
	}
	free(line);
}

static int	file_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File Open Error!");
		exit(0);
	}
	return (fd);
}

void	parse_file(t_v *v, char *filename)
{
	int	fd;

	fd = file_open(filename);
	file_check(v, fd);
	close(fd);
	fd = file_open(filename);
	parse_vertex(v, fd);
	close(fd);
}