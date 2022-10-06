#include "../../fdf.h"
#include <limits.h>
#include <string.h>

//Graphical image used by MLX
mlx_image_t	*image;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

/*
//Function handles key-press actions.
int	print_key(int key, void *data)
{
	int i = 0;
	ft_printf("%d", key);
	if (key == 65307)
		ft_printf("Escape Key");
	return (0);
}
*/
//* bresenham_draw Test
// gcc draw_main.c ../draw.c ../../libft/libft.a ../../mlx42/libmlx42.a -lglfw
// gcc draw_main.c ../draw.c ../../minilibx/libmlx_intel-mac.a -lXext -lX11
int	main(void)
{
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
	/*
	int	i = 10;
	while (i < 500)
	{
		mlx_put_pixel(image, 250, i, 0x00FF00FF);
		//mlx_put_pixel(mlxdata.mlx, mlxdata.window, 501, i, INT_MAX/2);
		i++;
	}//*/
	//mlx_key_hook(mlxdata.window, print_key, 0);
	//return 0;
	mlx_image_to_window(mlxdata.mlx, image, 0, 0);
	mlx_loop_hook(mlxdata.mlx, &hook, mlxdata.mlx);
	mlx_loop(mlxdata.mlx);
	mlx_terminate(mlxdata.mlx);
	return (0);
}
