// Tests for the functions in draw.c
#include "../../fdf.h"
#include <limits.h>
#include <string.h>
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

/* Test for bresenham_draw
// cc -lmlx -framework OpenGL -framework AppKit draw_main.c ../draw.c ../quick_pixel.c
int	main(void)
{
	t_imgdata	*img;
	t_mlxdata	*mlx;
	t_pointpair	*pp;

	img = (t_imgdata *)malloc(sizeof(t_imgdata));
	pp = (t_pointpair *)malloc(sizeof(t_pointpair));
	mlx = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	mlx->mlx = mlx_init();
	mlx->mlxwindow = mlx_new_window(mlx->mlx, 1200, 900, "Bresenham Test");
	img->image = mlx_new_image(mlx->mlx, 1200, 900);
	img->address = mlx_get_data_addr(img->image, &img->bits_pp, \
										&img->line_len, &img->endian);
	if (!img->image || !mlx->mlxwindow || !mlx->mlx)
	{
		printf("MLX Error.\n");
		return (0);
	}
	pp->x1 = 50;
	pp->y1 = 50;
	pp->x2 = 450;
	pp->y2 = 700;
	bresenham_draw(pp, img);
	mlx_put_image_to_window(mlx->mlx, mlx->mlxwindow, img->image, 0, 0);
	mlx_hook(mlx->mlxwindow, 17, 0, &exithook, mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	free(img);
	free(pp);
	return (0);
}
//*/
