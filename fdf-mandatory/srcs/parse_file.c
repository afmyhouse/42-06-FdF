/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/06 17:54:22 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	free_parser(char **vertex, char *line)
{
	int	width;

	if (line)
	{
		free(line);
		line = NULL;
	}
	if (vertex)
	{
		width = 0;
		while (vertex[width])
		{
			free(vertex[width]);
			width++;
		}
		free(vertex);
		vertex = NULL;
	}
}

static void	parse_vertex(t_v *v, int fd)
{
	char	*line;
	char	**vertex;
	int		p[3];

	line = get_next_line(fd);
	v->points = (t_vx ***)malloc(sizeof(t_vx **) * v->height);
	v->zmin = __INT_MAX__;
	v->zmax = -__INT_MAX__ - 1;
	p[1] = -1;
	while (line && ++p[1] < v->height)
	{
		vertex = ft_split(line, ' ');
		v->points[p[1]] = (t_vx **)malloc(sizeof(t_vx *) * v->width);
		p[0] = -1;
		while (++p[0] < v->width)
		{
			p[2] = ft_atoi(vertex[p[0]]);
			v->points[p[1]][p[0]] = set_vx(p[0], p[1], p[2]);
			v->zmin = (v->zmin > p[2]) * p[2] + !(v->zmin > p[2]) * v->zmin;
			v->zmax = (v->zmax < p[2]) * p[2] + !(v->zmax < p[2]) * v->zmax;
		}
		free_parser(vertex, line);
		line = get_next_line(fd);
	}
	free(line);
}

static int	file_check(t_v *v, int fd)
{
	char	*line;
	char	**vertex;
	int		width;

	v->err = 0;
	line = get_next_line(fd);
	v->width = 0;
	v->height = 0;
	while (line)
	{
		line = ft_strtrim_free(line, " \n");
		vertex = ft_split(line, ' ');
		width = 0;
		while (vertex[width])
			width++;
		v->err = v->err + !v->err * (v->width != 0 && v->width != width);
		v->width = width;
		v->height++;
		free_parser(vertex, line);
		line = get_next_line(fd);
	}
	free(line);
	return (v->err);
}

static int	file_open(t_v *v, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File OPEN error detected!\n", 2);
		exit_hook(v);
	}
	return (fd);
}

void	parse_file(t_v *v, char *filename)
{
	int	fd;

	fd = file_open(v, filename);
	if (file_check(v, fd))
	{
		printf("File FORMAT error detected during file check!\n");
		close(fd);
		exit_hook(v);
	}
	close(fd);
	fd = file_open(v, filename);
	parse_vertex(v, fd);
	close(fd);
}
