// Exercise to create a window with mlx and close it with a specific key press.
// On 42 school macOS, (with MLX pre-installed).
// Using the minilibx-linux version.
// run: cc -lmlx -framework OpenGL -framework AppKit screen_close.c

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	char	*window;
}			t_vars;

int	close(int keycode, t_vars *vars)
{
	printf("Key: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 700, 400, "Hello");
	mlx_hook(vars.window, 3, 0, close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
