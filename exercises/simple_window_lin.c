// Exercise to open a window and write pixels to it.
// Using minilibx-linux
// run: cc -lmlx -framework OpenGL -framework AppKit simple_window.c

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*window;
}			t_vars;

int	closing(int key, t_vars *mlxvars)
{
	if (key == 53)
	{
		mlx_destroy_window(mlxvars->mlx, mlxvars->window);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	*vars;
	void	*image;
	int		i;

	i = 0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return(0);
	vars->window = mlx_new_window(vars->mlx, 500, 500, "Title");
	image = mlx_new_image(vars->mlx, 500, 500);
	mlx_put_image_to_window(vars->mlx, vars->window, image, 0, 0);
	while (i < 500/3)
	{
		mlx_pixel_put(vars->mlx, vars->window, 500/2, i, 0x00FFFFFF);
		i++;
	}
	mlx_hook(vars->window, 3, 0, closing, vars);
	mlx_loop(vars->mlx);
	return (0);
}