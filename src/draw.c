/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:49:48 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/05 20:45:44 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//Function draws a line between points using Bresenham's algorithm.
void	bresenham_draw(t_pointpair points, t_mlxdata mlx)
{
	int	x_step;
	int	y_step;
	int	decision;
	int	y_out;
	int	x_var;

	x_step = points.x2 - points.x1;
	y_step = points.y2 - points.y1;
	decision = 2 * y_step - x_step;
	y_out = points.y1;
	x_var = 0;
	while (x_var++ <= points.x2)
	{
		mlx_pixel_put(mlx.mlx, mlx.window, x_var, y_out, 0xFFFFFFFF);
		if (decision > 0)
		{
			y_out++;
			decision -= 2*x_step;
		}
		decision += 2*y_step;
	}
}
