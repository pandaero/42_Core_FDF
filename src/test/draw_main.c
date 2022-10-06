//Tests for the functions in draw.c
#include "../../fdf.h"
#include <limits.h>
#include <string.h>

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
	t_mlxdata	mlxdata;
	t_pointpair	pp;

	mlxdata.mlx = mlx_init(600,600, "Draw Test", true);
	image = mlx_new_image(mlxdata.mlx, 600, 600);
	if (!image)
	{
		mlx_terminate(mlxdata.mlx);
		return (0);
	}
	pp.x1 = 50;
	pp.y1 = 50;
	pp.x2 = 450;
	pp.y2 = 450;
	bresenham_draw(pp, image);
	mlx_image_to_window(mlxdata.mlx, image, 0, 0);
	mlx_loop_hook(mlxdata.mlx, &hook, mlxdata.mlx);
	mlx_loop(mlxdata.mlx);
	mlx_terminate(mlxdata.mlx);
	return (0);
}
//*/
