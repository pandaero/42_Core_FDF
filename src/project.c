/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:49:57 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/07 01:45:59 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <math.h>

//Function performs scaling on the input grid.
void	xyscale(int *x, int *y, int factor, float uniform)
{
	*x *= round(factor);
	*y *= round((1 - uniform) * factor);
}

//Function applies transformations before using Bresenham's drawing.
void	transform(t_pointpair *pp, t_mapdata *mapdata, float uniform)
{
	int	factor;

	factor = (WIDTH / mapdata->width + HEIGHT / mapdata->depth) / 4;
	xyscale(&pp->x1, &pp->y1, factor, uniform);
	xyscale(&pp->x2, &pp->y2, factor, uniform);
}

//Function to perform translation of the whole image.
void	translate(t_pointpair *pp)
{
	int	x_off;
	int	y_off;

	x_off = X_OFFSET;
	y_off = Y_OFFSET;
	pp->x1 += x_off;
	pp->y1 += y_off;
	pp->x2 += x_off;
	pp->y2 += y_off;
}

//Function projects the map data through isometric projection. 30deg true iso.
void	isometric(int *xco, int *yco, int zco)
{
	int	x_cp;
	int	y_cp;

	x_cp = *xco;
	y_cp = *yco;
	*xco = (x_cp - y_cp) * cos(0.523599);
	*yco = (x_cp + y_cp) * sin(0.523599) - zco;
}
