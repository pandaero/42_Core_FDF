/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:21:21 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 17:05:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"
#include <stdlib.h>

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
			transform_bonus(pp, full);
			projected_horiz_bonus(pp, full, xloc, yloc);
			translate_bonus(pp, full);
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
			transform_bonus(pp, full);
			projected_vert_bonus(pp, full, xloc, yloc);
			translate_bonus(pp, full);
			if (yloc < full->map->depth)
				bresenham_draw(pp, full->img);
			xloc++;
		}
		yloc++;
	}
	free(pp);
}
