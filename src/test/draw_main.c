#include "../../fdf.h"
#include <limits.h>

//Function handles key-press actions.
int	print_key(int key, void *data)
{
	int i = 0;
	ft_printf("%d", key);
	if (key == 65307)
		ft_printf("Escape Key");
	return (0);
}

//* bresenham_draw Test
// gcc draw_main.c ../draw.c ../../minilibx-linux/libmlx_Linux.a -lXext -lX11
// gcc draw_main.c ../draw.c ../../minilibx/libmlx_intel-mac.a -lXext -lX11
int	main(void)
{
	t_mlxdata	mlxdata;
	t_pointpair	pp;
	void		*mlxx;
	void		*window;

	mlxx = mlx_init();
	window = mlx_new_window(mlxx, 1000, 1000, "Draw Test");
	mlxdata.mlx = mlxx;
	mlxdata.window = window;
	pp.x1 = 50;
	pp.x2 = 500;
	pp.y2 = 50;
	pp.y2 = 500;
	//bresenham_draw(pp, mlxdata);
	int	i = 10;
	while (i < 500)
	{
		mlx_pixel_put(mlxdata.mlx, mlxdata.window, 500, i, INT_MAX/2);
		mlx_pixel_put(mlxdata.mlx, mlxdata.window, 501, i, INT_MAX/2);
		i++;
	}	
	mlx_key_hook(mlxdata.window, print_key, 0);
	//return 0;
	mlx_loop(mlxx);
	return (0);
}
