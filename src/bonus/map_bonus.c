/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:14:15 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 14:26:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

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
static void	md_error(int mapwidth, int fd)
{
	if (mapwidth == -1 || fd == -1)
	{
		perror("Map reading error");
		exit(1);
	}
}

//Function fills map data from a mapfile (or returns error if invalid).
int	map_data_bonus(t_fulldata *full, char *mapfile)
{
	char	*line;
	int		fd;
	int		i;

	full->map->width = map_width(mapfile);
	fd = open(mapfile, O_RDONLY, 0);
	md_error(full->map->width, fd);
	full->map->depth = map_depth(mapfile);
	full->map->height_data = (int **)malloc((full->map->depth) * sizeof(int *));
	i = 0;
	while (i < full->map->depth)
		full->map->height_data[i++] = (int *)malloc((full->map->width) * \
										sizeof(int));
	line = get_next_line(fd);
	i = 0;
	while (i < full->map->depth)
	{
		if (i > 0)
			line = get_next_line(fd);
		height_matrix(full->map->height_data[i], line, full->map->width);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}
