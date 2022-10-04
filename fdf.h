/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:21:11 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/03 17:42:43 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

typedef struct s_mapdata
{
	int	width;
	int	depth;
	int	**height_data;
}		t_mapdata;

//Function checks that all the values in a 1D array are the same.
int		ft_chkarr(int *arr, int size);
//Function reads from a map file to determine the depth of the map.
int		map_depth(char *mapfile);
//Function reads from a map file to determine the width/breadth of the map.
int		map_width(char *mapfile);
//Function fills map data from a mapfile (or returns error if invalid).
int		map_data(t_mapdata *data, char *mapfile);
//Function frees a 2D array of allocated memory.
void	arr_free(char **arr);
#endif