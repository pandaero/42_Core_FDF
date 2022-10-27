/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:18:22 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 17:12:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

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
