/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:21:21 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 19:27:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"
#include <stdlib.h>

//Function performs transformations to point pair, horizontal variant.
static void	transform_horiz(t_pointpair *pp, t_fulldata *data, int x, int y)
{
	scale_bonus(pp, data);
	rotate(pp, data);
	projected_horiz_bonus(pp, data, x, y);
	translate_bonus(pp, data);
}

//Function performs transformations to point pair, vertical variant.
static void	transform_vert(t_pointpair *pp, t_fulldata *data, int x, int y)
{
	scale_bonus(pp, data);
	rotate(pp, data);
	projected_vert_bonus(pp, data, x, y);
	translate_bonus(pp, data);
}

//Function connects points from the map with a line grid. Propagates horizontal.
void	draw_horiz_bonus(t_fulldata *full)
{
	int			xloc;
	int			yloc;
	t_pointpair	*pp;

	pp = (t_pointpair *)malloc(sizeof(t_pointpair));
	yloc = 1;
	while (yloc <= full->map->depth)
	{
		xloc = 1;
		while (xloc < full->map->width)
		{
			pp->x1 = xloc - 1;
			pp->y1 = yloc - 1;
			pp->x2 = xloc;
			pp->y2 = yloc - 1;
			transform_horiz(pp, full, xloc, yloc);
			if (xloc < full->map->width)
				bresenham_draw(pp, full->img);
			xloc++;
		}
		yloc++;
	}
	free(pp);
}

//Function draws the vertical part of the projection.
void	draw_vert_bonus(t_fulldata *full)
{
	int			xloc;
	int			yloc;
	t_pointpair	*pp;

	pp = (t_pointpair *)malloc(sizeof(t_pointpair));
	yloc = 1;
	while (yloc < full->map->depth)
	{
		xloc = 1;
		while (xloc <= full->map->width)
		{
			pp->x1 = xloc - 1;
			pp->y1 = yloc - 1;
			pp->x2 = xloc - 1;
			pp->y2 = yloc;
			transform_vert(pp, full, xloc, yloc);
			if (yloc < full->map->depth)
				bresenham_draw(pp, full->img);
			xloc++;
		}
		yloc++;
	}
	free(pp);
}
