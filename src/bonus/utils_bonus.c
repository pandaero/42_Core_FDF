/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:51:38 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 17:54:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

//Function activates for each frame.
int	frame(t_fulldata *fulldata)
{
	wipe_image(fulldata->img);
	draw_horiz_bonus(fulldata);
	draw_vert_bonus(fulldata);
	mlx_put_image_to_window(fulldata->mlx, fulldata->mlxwin, \
						fulldata->img->image, 0, 0);
	return (0);
}

//Function initialises many values for the FdF program.
void	initialise(t_fulldata *full)
{
	full->projection = 0;
	full->rotation = 0;
	full->translation_horiz = X_OFFSET;
	full->translation_vert = Y_OFFSET;
	full->zoom = (WIDTH / full->map->width + HEIGHT / full->map->depth) / 4;
	full->mlx = mlx_init();
	full->mlxwin = mlx_new_window(full->mlx, WIDTH, HEIGHT, "FdF Bonus");
	full->img->image = mlx_new_image(full->mlx, WIDTH, HEIGHT);
	full->img->address = mlx_get_data_addr(full->img->image, \
			&full->img->bits_pp, &full->img->line_len, &full->img->endian);
}

//Function sets a window-sized image to black.
void	wipe_image(t_imgdata *data)
{
	int	x;
	int	y;

	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			quick_put_pixel(data, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}
