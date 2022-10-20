// Exercise to create an image with mlx and place a pixel on it.
// On 42 school macOS, (with MLX pre-installed).
// Using the minilibx-linux version.
// run: cc -lmlx -framework OpenGL -framework AppKit screen.c

#include <mlx.h>

typedef struct s_data
{
	void	*image;
	char	*address;
	int		bits_pp;
	int		line_len;
	int		endian;
}			t_data;

int	memoffset(int x, int y, int line_len, int bits_pp)
{
	int offset;

	offset = (y * line_len + x * (bits_pp / 8));
	return (offset);
}

void	quick_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->address + memoffset(x, y, data->line_len, data->bits_pp);
	*(unsigned int *)dest = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	image;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 700, 400, "Hello");
	image.image = mlx_new_image(mlx, 700, 400);
	image.address = mlx_get_data_addr(image.image, &image.bits_pp, \
										&image.line_len, &image.endian);
	quick_put_pixel(&image, 10, 10, 0x00FFFFFF);
	mlx_put_image_to_window(mlx, mlx_window, image.image, 0, 0);
	mlx_loop(mlx);
	return (0);
}
