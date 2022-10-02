/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:49:26 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/02 18:38:17 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../fdf.h"

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

/*
//Function reads from a 2D char string array to make a 1D int array.
int	*line_read(char **strarr)
{
	int	*arrline;
	int	numel;
	int i;

	numel = 0;
	while (strarr[numel])
	{
		numel++;
	}
	arrline = malloc(numel * sizeof(*arrline));
	i = 0;
	while (strarr[i])
	{
		arrline[i] = ft_atoi(strarr[i]);
		i++;
	}
	return (arrline);
}

//Function converts map input file to integer 2D-array.
int	**map_arr(int fd)
{
	char	*line;
	char	**strarr;
	int		**arr;
	int		*arrline;
	int		i;
	int		j;

	i = 0;
	line = 0;
	while (line != 0)
	{
		line = get_next_line(fd);
		strarr = ft_split(line, ' ');
		arrline = line_read(strarr);
		free(line);
		j = 0;
		while (arr[i][j])
		{
			arr[i][j] = arrline[j];
			j++;
		}
		arr_free(strarr);
		i++;
	}
	return (arr);
}

int	map_max_height(int fd)
{
	
	while()
	{
		(get next line)
		(ft split)
		(scan for max)
			(if greater than last, replace)
	}
	return (fd);
}
*/