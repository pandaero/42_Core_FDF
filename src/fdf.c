/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:27:04 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/07 08:22:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "../fdf.h"

static int	error_handling(int argcnt, char *file)
{
	int	fd;

	if (argcnt != 2)
	{
		if (argcnt > 2)
			ft_printf("Too many arguments.\n");
		else
			ft_printf("Too few arguments.\n");
		return (1);
	}		
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("File Error");
		return (1);
	}
	return (0);
}

//Function that serves for hook actions for mlx.
static void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

//Function calls mlx elements.
static void	mlxevents(t_mlxdata *data)
{
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	mlx_loop_hook(data->mlx, &hook, data->mlx);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

//Function executes the program.
int	main(int argc, char **argv)
{
	t_mlxdata	*mlxdata;
	t_mapdata	*mapdata;

	if (error_handling(argc, argv[1]) == 1)
		return (0);
	mapdata = (t_mapdata *)malloc(sizeof(t_mapdata));
	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	mlxdata->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	mlxdata->image = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
	if (!mlxdata->image || map_data(mapdata, argv[1]) == -1 || !mlxdata)
	{
		mlx_terminate(mlxdata->mlx);
		ft_printf("Map, MLX, or Malloc Error\n");
		return (0);
	}
	draw_horiz(mapdata, mlxdata);
	draw_vert(mapdata, mlxdata);
	mlxevents(mlxdata);
	free_twodee(mapdata->height_data, mapdata->depth);
	free(mapdata);
	free(mlxdata);
	return (0);
}
