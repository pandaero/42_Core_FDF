//Function draws a line between points using Bresenham's algorithm.
void	bresenham_draw(t_pointpair points, mlx_image_t *image)
{
	int	x0;
	int	y0;
	int	dx;
	int dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;

	dx = abs(points.x2 - points.x1);
	dy = -1 * abs(points.y2 - points.y1);
	if (points.x1 < points.x2)
		sx = 1;
	else
		sx = -1;
	if (points.y1 < points.y2)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	x0 = points.x1;
	y0 = points.y1;

	while (image)
	{
		//ft_printf("%d, %d, %d, %d, %d, %d\n", x0, y0, dx, dy, sx, sy);
		mlx_put_pixel(image, x0, y0, 0xFFFFFFFF);
		if (x0 == points.x2 && y0 == points.y2)
			break ;
		err2 = 2 * err;
		if (err2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (err2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
