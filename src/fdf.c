/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:27:04 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/26 20:33:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

//Function to close the program following a close-window click.
static int	closing(t_mlxdata *mlxdata)
{
	mlx_destroy_window(mlxdata->mlx, mlxdata->mlxwindow);
	exit(0);
}

//Function to close the program following an ESC key release.
static int	keyclosing(int key, t_mlxdata *mlxdata)
{
	if (key == 53)
	{
		mlx_destroy_window(mlxdata->mlx, mlxdata->mlxwindow);
		exit(0);
	}
	return (0);
}

//Function calls mlx elements.
static void	mlxevents(t_mlxdata *mlxdata, t_imgdata *imgdata)
{
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->mlxwindow, \
							imgdata->image, 0, 0);
	mlx_hook(mlxdata->mlxwindow, 17, 0, closing, mlxdata);
	mlx_hook(mlxdata->mlxwindow, 3, 0, keyclosing, mlxdata);
	mlx_loop(mlxdata->mlx);
}

//Function frees program allocated elements.
static void	free_prog(t_mlxdata *mlxdata, void *imgdata, t_mapdata *mapdata)
{
	mlx_destroy_window(mlxdata->mlx, mlxdata->mlxwindow);
	free_twodee(mapdata->height_data, mapdata->depth);
	free(mapdata);
	free(mlxdata);
	free(imgdata);
}

//Function executes the program.
int	main(int argc, char **argv)
{
	t_mlxdata	*mlxdata;
	t_mapdata	*mapdata;
	t_imgdata	*imdt;

	error_handling(argc, argv[1]);
	mapdata = (t_mapdata *)malloc(sizeof(t_mapdata));
	map_data(mapdata, argv[1]);
	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	imdt = (t_imgdata *)malloc(sizeof(t_imgdata));
	mlxdata->mlx = mlx_init();
	mlxdata->mlxwindow = mlx_new_window(mlxdata->mlx, WIDTH, HEIGHT, "FdF");
	imdt->image = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
	imdt->address = mlx_get_data_addr(imdt->image, &imdt->bits_pp, \
										&imdt->line_len, &imdt->endian);
	if (!imdt->image || !mlxdata->mlxwindow || !mlxdata->mlx)
	{
		ft_printf("MLX init, or Malloc Error\n");
		free_prog(mlxdata, imdt, mapdata);
		return (0);
	}
	draw_horiz(mapdata, imdt);
	draw_vert(mapdata, imdt);
	mlxevents(mlxdata, imdt);
	free_prog(mlxdata, imdt, mapdata);
	return (0);
}
