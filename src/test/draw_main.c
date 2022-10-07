//Tests for the functions in draw.c
#include "../../fdf.h"
#include <limits.h>
#include <string.h>
#include <stdlib.h>

/*
//Function that serves for hook actions for mlx.
void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
//*/

/* bresenham_draw Test
// gcc draw_main.c ../draw.c ../../libft/libft.a ../../mlx42/libmlx42.a -lglfw
// gcc draw_main.c ../draw.c ../../minilibx/libmlx_intel-mac.a -lXext -lX11
int	main(void)
{
	mlx_image_t	*image;
	t_mlxdata	*mlxdata;
	t_pointpair	*pp;

	pp = (t_pointpair *)malloc(sizeof(t_pointpair));
	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	mlxdata->mlx = mlx_init(WIDTH, HEIGHT, "Draw Test", true);
	mlxdata->image = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
	if (!image)
	{
		mlx_terminate(mlxdata->mlx);
		return (0);
	}
	pp->x1 = 50;
	pp->y1 = 50;
	pp->x2 = 450;
	pp->y2 = 700;
	bresenham_draw(pp, mlxdata->image);
	mlx_image_to_window(mlxdata->mlx, mlxdata->image, 0, 0);
	mlx_loop_hook(mlxdata->mlx, &hook, mlxdata->mlx);
	mlx_loop(mlxdata->mlx);
	mlx_terminate(mlxdata->mlx);
	return (0);
}
//*/

/* draw_grid Test
// gcc draw_main.c ../draw.c ../../libft/libft.a ../../mlx42/libmlx42.a -lglfw
// gcc draw_main.c ../draw.c ../../minilibx/libmlx_intel-mac.a -lXext -lX11
int	main(void)
{
	mlx_image_t	*image;
	t_mlxdata	*mlxdata;
	t_mapdata	*mapdata;
	int			ret;

	mapdata = (t_mapdata *)malloc(sizeof(t_mapdata));
	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	mlxdata->mlx = mlx_init(600,600, "Grid Draw Test", true);
	mlxdata->image = mlx_new_image(mlxdata->mlx, 600, 600);
	if (!image)
	{
		mlx_terminate(mlxdata->mlx);
		return (0);
	}
	ret = map_data(mapdata, "../../test_maps/42.fdf");
	if (ret == -1)
		return (0);
	draw_grid(mapdata, mlxdata);
	mlx_image_to_window(mlxdata->mlx, mlxdata->image, 0, 0);
	mlx_loop_hook(mlxdata->mlx, &hook, mlxdata->mlx);
	mlx_loop(mlxdata->mlx);
	mlx_terminate(mlxdata->mlx);
	free(mapdata);
	free(mlxdata);
	return (0);
}
//*/
