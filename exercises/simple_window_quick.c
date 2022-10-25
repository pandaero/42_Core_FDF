// Exercise to open a window and write pixels to it.
// Using minilibx-linux
// run: cc -lmlx -framework OpenGL -framework AppKit simple_window_quick.c

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*window;
}			t_vars;

typedef struct s_imgdata
{
	void	*image;
	char	*address;
	int		bits_pp;
	int		line_len;
	int		endian;
}			t_imgdata;

int	closing(t_vars *mlxvars)
{
	mlx_destroy_window(mlxvars->mlx, mlxvars->window);
	exit(0);
}

int	key_closing(int key, t_vars *mlxvars)
{
	if (key == 53)
	{
		mlx_destroy_window(mlxvars->mlx, mlxvars->window);
		exit(0);
	}
	return (0);
}

//Function works out the memory address offset of a pixel from its image.
static int	memoffset(int x, int y, int line_len, int bits_pp)
{
	int	offset;

	offset = (y * line_len + x * (bits_pp / 8));
	return (offset);
}

//Function places a pixel in an image more quickly than with the pixel_put fn.
void	quick_put_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < 500 && y >= 0 && y < 500)
		dest = data->address + (y * data->line_len + x * (data->bits_pp / 8));
	*(unsigned int *)dest = color;
}

int	main(void)
{
	t_vars		*vars;
	t_imgdata	*imgdata;
	void		*image;
	int			i;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	imgdata = calloc(1, sizeof(t_imgdata));
	vars->window = mlx_new_window(vars->mlx, 500, 500, "Title");
	imgdata->image = mlx_new_image(vars->mlx, 500, 500);
	imgdata->address = mlx_get_data_addr(imgdata->image, &imgdata->bits_pp, \
										&imgdata->line_len, &imgdata->endian);
	i = 0;
	while (i <= 500)
	{
		quick_put_pixel(imgdata, 500 / 2, i, 0x00FFFFFF);
		i++;
	}
	quick_put_pixel(imgdata, 500 / 2, 500 / 2, 0x00FF0000);
	mlx_put_image_to_window(vars->mlx, vars->window, imgdata->image, 0, 0);
	mlx_hook(vars->window, 17, 0, closing, vars);
	mlx_hook(vars->window, 3, 0, key_closing, vars);
	mlx_loop(vars->mlx);
	return (0);
}
