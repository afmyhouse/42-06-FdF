/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/31 16:00:29 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	parse_vertex(t_v *v, int fd)
{
	char	*line;
	char	**vertex;
	int		p[3];

	line = get_next_line(fd);
	v->points = (t_vx ***)malloc(sizeof(t_vx **) * v->height);
	v->z_min = __INT_MAX__;
	v->z_max = -__INT_MAX__ - 1;
	p[1] = 0;
	while (line)
	{
		vertex = ft_split(line, ' ');
		free(line);
		v->points[p[1]] = (t_vx **)malloc(sizeof(t_vx *) * v->width);
		p[0] = -1;
		while (++p[0] < v->width)
		{
			p[2] = ft_atoi(vertex[p[0]]);
			v->points[p[1]][p[0]] = set_vx(p[0], p[1], p[2]);
			v->z_min = (v->z_min > p[2]) * p[2] + !(v->z_min > p[2]) * v->z_min;
			v->z_max = (v->z_max < p[2]) * p[2] + !(v->z_max < p[2]) * v->z_max;
		}
		ft_free_str(vertex);
		line = get_next_line(fd);
		p[1]++;
	}
	ft_free_str(vertex);
	free(line);
}

static void	file_check(t_v *view, int fd)
{
	char	*line;
	char	**vertex;
	int		width;

	line = get_next_line(fd);
	view->height = 0;
	view->width = 0;
	while (line)
	{
		vertex = ft_split(line, ' ');
		free(line);
		width = 0;
		while (vertex[width])
			width++;
		if (view->width != 0 && view->width != width)
		{
			ft_printf("Found wrong line length. Exiting.\n");
			ft_printf("Expected %d, got %d.\n", view->width, width);
			ft_printf("Line: %d : %s\n", view->height + 1, line);
			exit(0);
		}
		view->width = width;
		view->height++;
		ft_free_str(vertex);
		line = get_next_line(fd);
	}
	ft_free_str(vertex);
	free(line);
}

static int	file_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File Error!");
		exit(0);
	}
	return (fd);
}

void	parse_file(t_v *view, char *filename)
{
	int	fd;

	fd = file_open(filename);
	file_check(view, fd);
	close(fd);
	fd = file_open(filename);
	parse_vertex(view, fd);
	close(fd);
}
