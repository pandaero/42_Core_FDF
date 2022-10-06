/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:49:48 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/06 20:42:56 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>

//Function defines the parameters for the Bresenham line algorithm.
void	bresenham_define(t_bresenham *param, t_pointpair points)
{
	param->dx = abs(points.x2 - points.x1);
	param->dy = -1 * abs(points.y2 - points.y1);
	if (points.x1 < points.x2)
		param->sx = 1;
	else
		param->sx = -1;
	if (points.y1 < points.y2)
		param->sy = 1;
	else
		param->sy = -1;
	param->err = param->dx + param->dy;
	param->x0 = points.x1;
	param->y0 = points.y1;
}

//Function draws a line between points using Bresenham's algorithm.
void	bresenham_draw(t_pointpair points, mlx_image_t *image)
{
	t_bresenham	*param;

	param = (t_bresenham *)malloc(sizeof(t_bresenham));
	bresenham_define(param, points);
	while (image)
	{
		mlx_put_pixel(image, param->x0, param->y0, 0xFFFFFFFF);
		if (param->x0 == points.x2 && param->y0 == points.y2)
			break ;
		param->err2 = 2 * param->err;
		if (param->err2 >= param->dy)
		{
			param->err += param->dy;
			param->x0 += param->sx;
		}
		if (param->err2 <= param->dx)
		{
			param->err += param->dx;
			param->y0 += param->sy;
		}
	}
	free(param);
}
