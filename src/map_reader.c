/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:49:26 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/26 16:19:30 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Function reads from a map file to determine the depth of the map.
int	map_depth(char *mapfile)
{
	char	*line;
	int		fd;
	int		depth;

	fd = open(mapfile, O_RDONLY, 0);
	line = mapfile;
	depth = 0;
	while (line != 0)
	{
		line = get_next_line(fd);
		free(line);
		depth++;
	}
	close(fd);
	return (depth - 1);
}

//Function reads from a map file to determine the width/breadth of the map.
int	map_width(char *mapfile)
{
	char	*row;
	int		*width;
	int		multival[3];

	width = (int *)malloc(map_depth(mapfile) * sizeof(*width));
	if (!width)
		return (-2);
	multival[0] = open(mapfile, O_RDONLY, 0);
	row = get_next_line(multival[0]);
	multival[1] = 0;
	while (row != 0)
	{
		if (multival[1] > 0)
			row = get_next_line(multival[0]);
		if (row != 0)
			width[multival[1]] = ft_nwrds(row, ' ');
		free(row);
		multival[1]++;
	}
	close(multival[0]);
	multival[2] = width[0];
	if (ft_chkarr(width, map_depth(mapfile)) != 1)
		multival[2] = -1;
	free(width);
	return (multival[2]);
}

//Function fills an int array with data from a map file line.
static void	height_matrix(int *height_row, char *line, int len)
{
	char	**elms;
	int		i;

	elms = ft_split(line, ' ');
	i = 0;
	while (i < len)
	{
		height_row[i] = ft_atoi(elms[i]);
		free(elms[i]);
		i++;
	}
	free(elms);
}

//Function performs error actions for map_data
static void	md_error(void)
{
	perror("Map reading error");
	exit(1);
}

//Function fills map data from a mapfile (or returns error if invalid).
int	map_data(t_mapdata *data, char *mapfile)
{
	char	*line;
	int		fd;
	int		i;

	data->width = map_width(mapfile);
	fd = open(mapfile, O_RDONLY, 0);
	if (data->width == -1 || fd == -1)
		md_error();
	data->depth = map_depth(mapfile);
	data->height_data = (int **)malloc((data->depth) * sizeof(int *));
	i = 0;
	while (i < data->depth)
		data->height_data[i++] = (int *)malloc((data->width) * sizeof(int));
	line = get_next_line(fd);
	i = 0;
	while (i < data->depth)
	{
		if (i > 0)
			line = get_next_line(fd);
		height_matrix(data->height_data[i], line, data->width);
		free(line);
		i++;
	}
	return (1);
}
