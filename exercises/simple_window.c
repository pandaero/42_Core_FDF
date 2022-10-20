// Exercise to open a window and write pixels to it.
// Using minilibx_mms_20191025_beta
// run: cc -lmlx -framework OpenGL -framework AppKit simple_window.c

#include "../minilibx_mms/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*window;
}			t_vars;

int	closing(int key, t_vars *mlxvars)
{
	mlx_destroy_window(mlxvars->mlx, mlxvars->window);
	return (0);
}

int	key_hook(int key, t_vars *mlxvars)
{
	printf("Hey there!\n");
	return (0);
}

int	main()
{
	t_vars	*vars;
	void	*image;
	int		winret;
	int		*sizex;
	int		*sizey;
	int		i;

	sizex = 0;
	sizey = 0;
	i = 0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return(0);
	//mlx_get_screen_size(mlx, sizex, sizey);
	vars->window = mlx_new_window(vars->mlx, 500, 500, "Title");
	image = mlx_new_image(vars->mlx, 500, 500);
	winret = mlx_put_image_to_window(vars->mlx, vars->window, image, 0, 0);
	while (i < 500/3)
	{
		mlx_pixel_put(vars->mlx, vars->window, 500/2, i, 0x00FFFFFF);
		i++;
	}
	mlx_hook(vars->window, 17, 0, closing, vars);
	mlx_key_hook(vars->window, key_hook, &vars);
	mlx_loop(vars->mlx);
	mlx_destroy_image(vars->mlx, image);
	mlx_destroy_window(vars->mlx, vars->window);
	return (0);
}