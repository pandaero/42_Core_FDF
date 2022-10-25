/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:21:11 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/25 11:57:43 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef WIDTH
#  define WIDTH 640
# endif
# ifndef HEIGHT
#  define HEIGHT 480
# endif
# ifndef X_OFFSET
#  define X_OFFSET 250
# endif
# ifndef Y_OFFSET
#  define Y_OFFSET 100
# endif

# include "./libft/libft.h"
# include <mlx.h>

typedef struct s_mapdata
{
	int	width;
	int	depth;
	int	**height_data;
}		t_mapdata;

typedef struct s_pointpair
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}		t_pointpair;

typedef struct s_bresenham
{
	int	x0;
	int	y0;
	int	dx;
	int dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;
}		t_bresenham;

typedef struct s_imgdata
{
	void	*image;
	char	*address;
	int		bits_pp;
	int		line_len;
	int		endian;
}			t_imgdata;

typedef struct s_mlxdata
{
	void	*mlx;
	void	*image;
}			t_mlxdata;

//Function checks that all the values in a 1D array are the same.
int		ft_chkarr(int *arr, int size);
//Function reads from a map file to determine the depth of the map.
int		map_depth(char *mapfile);
//Function reads from a map file to determine the width/breadth of the map.
int		map_width(char *mapfile);
//Function fills map data from a mapfile (or returns error if invalid).
int		map_data(t_mapdata *data, char *mapfile);
//Function frees a 2D int array.
void	free_twodee(int **ptr, int lim);
//Function places a pixel in an image more quickly than with the pixel_put fn.
void	quick_put_pixel(t_imgdata *data, int x, int y, int color);
//Function draws a line between points using Bresenham's algorithm.
void	bresenham_draw(t_pointpair *points, mlx_image_t *image);
//Function applies transformations before using Bresenham's drawing.
void	transform(t_pointpair *pp, t_mapdata *mapdata, float uniform);
//Function performs scaling on the input grid.
void	xyscale(int *x, int *y, int factor, float uni);
//Function to perform translation of the whole image.
void	translate(t_pointpair *pp);
//Function projects the map data through isometric projection.
void	isometric(int *xco, int *yco, int zco);
//Function connects points from the map with a line grid. Propagates from TL.
void	draw_horiz(t_mapdata *mapdata, t_mlxdata *mlxdata);
//Function connects points from the map with a line grid. Propagates from TL.
void	draw_vert(t_mapdata *mapdata, t_mlxdata *mlxdata);
#endif