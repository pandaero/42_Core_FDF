// Tests for the functions in draw_grid.c
#include "../../fdf.h"
#include <stdlib.h>
#include <stdio.h>

/*
//Function that serves for hook actions for mlx. (Only quit with ESC)
static int	exithook(t_mlxdata *mlxdata)
{
	mlx_destroy_window(mlxdata->mlx, mlxdata->mlxwindow);
	exit(0);
}
//*/

/* Test for draw_grid.c
// cc -lmlx -framework OpenGL -framework AppKit dg_main.c ../draw_grid.c ../draw.c ../map_reader.c ../projection.c ../quick_pixel.c  ../utils.c ../../libft/libft.a
int	main(int argc, char **argv)
{
	t_mlxdata	*mlx;
	t_imgdata	*img;
	t_mapdata	*map;
	t_pointpair	*pp;
	int			ret;

	mlx = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	img = (t_imgdata *)malloc(sizeof(t_imgdata));
	map = (t_mapdata *)malloc(sizeof(t_mapdata));
	pp = (t_pointpair *)malloc(sizeof(t_pointpair));
	mlx->mlx = mlx_init();
	mlx->mlxwindow = mlx_new_window(mlx->mlx, 1200, 900, "Grid Test");
	img->image = mlx_new_image(mlx->mlx, 1200, 900);
	img->address = mlx_get_data_addr(img->image, &img->bits_pp, \
										&img->line_len, &img->endian);
	if (!img->image || !mlx->mlxwindow || !mlx->mlx)
	{
		printf("MLX Error.\n");
		return (0);
	}
	ret = map_data(map, argv[1]);
	if (ret == -1)
	{
		printf("Map Error.\n");
		return (0);
	}
	draw_horiz(map, img);
	draw_vert(map, img);
	mlx_put_image_to_window(mlx->mlx, mlx->mlxwindow, img->image, 0, 0);
	mlx_hook(mlx->mlxwindow, 17, 0, &exithook, mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	free(img);
	free_twodee(map->height_data, map->depth);
	free(map);
	free(pp);
	return (0);
}
//*/
