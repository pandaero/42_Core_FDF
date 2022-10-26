// Program creates a circle to be moved by the keys

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 1200
#define HEIGHT 900

typedef struct s_imgdata
{
	void	*image;
	char	*address;
	int		bits_pp;
	int		line_len;
	int		endian;
}			t_imgdata;

typedef struct s_full
{
	void		*mlx;
	void		*mlxwin;
	t_imgdata	*img1;
	t_imgdata	*img2;
	int			movex;
	int			movey;
	int			frame;
}				t_full;

//Function writes a pixel to an image address directly.
void	quick_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dest;

	dest = 0;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dest = data->address + (y * data->line_len + x * (data->bits_pp / 8));
		*(unsigned int *)dest = color;
	}
}

//Function places 4 points from a centre. Empty cross-like.
void	plotfour(t_imgdata *data, int cx, int cy, int dx, int dy)
{
	int	colour;

	colour = 0x00FFFFFF;
	quick_pixel(data, cx + dx, cy + dy, colour);
	quick_pixel(data, cx + dx, cy - dy, colour);
	quick_pixel(data, cx - dx, cy + dy, colour);
	quick_pixel(data, cx - dx, cy - dy, colour);
}

//Function places 8 points from a centre. Empty asterisk-like.
void	ploteight(t_imgdata *data, int cx, int cy, int dx, int dy)
{
	plotfour(data, cx, cy, dx, dy);
	plotfour(data, cx, cy, dy, dx);
}

//Function draws a Bresenham circle radius r centred on x,y.
void	draw_circle(t_imgdata *imgdata, int cx, int cy, int r)
{
	int error;
	int	x;
	int y;

	error = -r;
	x = r;
	y = 0;
	while (x > y)
	{
		ploteight(imgdata, cx, cy, x, y);
		error += y;
		y++;
		error += y;
		if (error >= 0)
		{
			x--;
			error -= x;
			error -= x;
		}
	}
}

//Function sets the image to full black.
void	wipe_image(t_imgdata *data)
{
	int x;
	int y;
	
	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			quick_pixel(data, x, y, 0);
			y++;
		}
		x++;
	}
}

//Function to close the program following a close-window click.
static int	closing(t_full *full)
{
	mlx_destroy_window(full->mlx, full->mlxwin);
	exit(0);
}

//Function to close the program following an ESC key release.
static int	keyclosing(int key, t_full *full)
{
	if (key == 53)
	{
		mlx_destroy_window(full->mlx, full->mlxwin);
		exit(0);
	}
	return (0);
}

//Function for key press actions.
static int	keypress(int key, t_full *full)
{
	if (key == 13)
		full->movey -= 10;
	if (key == 1)
		full->movey += 10;
	if (key == 0)
		full->movex -= 10;
	if (key == 2)
		full->movex += 10;
	return (0);
}

//Function does something to render next frame.
int	next_frame(t_full *full)
{
	wipe_image(full->img1);
	draw_circle(full->img1, WIDTH/2 + full->movex, HEIGHT/2 + full->movey, 100);
	mlx_put_image_to_window(full->mlx, full->mlxwin, full->img1, 0, 0);
	return (0);
}

int	main(void)
{
	t_full	*full;

	full = (t_full *)malloc(sizeof(t_full));
	full->img1 = (t_imgdata *)malloc(sizeof(t_imgdata));
	full->mlx = mlx_init();
	full->mlxwin = mlx_new_window(full->mlx, WIDTH, HEIGHT, "Circle");
	full->img1 = mlx_new_image(full->mlx, WIDTH, HEIGHT);
	full->img1->address = mlx_get_data_addr(full->img1, \
		&full->img1->bits_pp, &full->img1->line_len, &full->img1->endian);
	full->movex = 0;
	full->movey = 0;
	mlx_hook(full->mlxwin, 17, 0, closing, full);
	mlx_hook(full->mlxwin, 3, 0, keyclosing, full);
	mlx_hook(full->mlxwin, 2, 0, keypress, full);
	mlx_loop_hook(full->mlx, next_frame, full);
	free(full->img1);
	free(full);
	return (0);
}
