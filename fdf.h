/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:21:11 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/02 17:52:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

//Function reads from a 2D char string array to make a 1D int array.
int		*line_read(char **strarr);
//Function converts map input file to integer 2D-array.
int		**map_arr(int fd);
//Function frees a 2D array of allocated memory.
void	arr_free(char **arr);
//Function reads from a map file to determine the depth of the map.
int		map_depth(char *mapfile);
//Function reads from a map file to determine the width/breadth of the map.
int		map_width(char *mapfile);
//Function checks that all the values in an array are the same.
int 	ft_chkarr(int *arr, int size);
//Function works out the size of a 1D array by looking at the pointers.
int 	ft_arrsize(int *arr);
#endif