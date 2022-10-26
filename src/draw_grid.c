/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:51:38 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/26 15:39:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>

//Function applies projection to a point pair, given map data. Horizontal lines.
void	projected_horiz(t_pointpair *pp, t_mapdata *mapdata, int x, int y)
{
	int	z1;
	int	z2;

	z1 = mapdata->height_data[y - 1][x - 1];
	z2 = mapdata->height_data[y - 1][x];
	isometric(&pp->x1, &pp->y1, z1);
	isometric(&pp->x2, &pp->y2, z2);
}

//Function applies projection to a point pair, given map data. Vertical lines.
void	projected_vert(t_pointpair *pp, t_mapdata *mapdata, int x, int y)
{
	int	z1;
	int	z2;

	z1 = mapdata->height_data[y - 1][x - 1];
	z2 = mapdata->height_data[y][x - 1];
	isometric(&pp->x1, &pp->y1, z1);
	isometric(&pp->x2, &pp->y2, z2);
}

//Function connects points from the map with a line grid. Propagates horizontal.
void	draw_horiz(t_mapdata *mapdata, t_imgdata *imgdata)
{
	int			xloc;
	int			yloc;
	t_pointpair	*pp;

	pp = (t_pointpair *)malloc(sizeof(t_pointpair));
	yloc = 1;
	while (yloc <= mapdata->depth)
	{
		xloc = 1;
		while (xloc < mapdata->width)
		{
			pp->x1 = xloc - 1;
			pp->y1 = yloc - 1;
			pp->x2 = xloc;
			pp->y2 = yloc - 1;
			transform(pp, mapdata, 0);
			projected_horiz(pp, mapdata, xloc, yloc);
			translate(pp);
			if (xloc < mapdata->width)
				bresenham_draw(pp, imgdata);
			xloc++;
		}
		yloc++;
	}
	free(pp);
}

//Function connects points from the map with a line grid. Propagates vertical.
void	draw_vert(t_mapdata *mapdata, t_imgdata *imgdata)
{
	int			xloc;
	int			yloc;
	t_pointpair	*pp;

	pp = (t_pointpair *)malloc(sizeof(t_pointpair));
	yloc = 1;
	while (yloc < mapdata->depth)
	{
		xloc = 1;
		while (xloc <= mapdata->width)
		{
			pp->x1 = xloc - 1;
			pp->y1 = yloc - 1;
			pp->x2 = xloc - 1;
			pp->y2 = yloc;
			transform(pp, mapdata, 0);
			projected_vert(pp, mapdata, xloc, yloc);
			translate(pp);
			if (yloc < mapdata->depth)
				bresenham_draw(pp, imgdata);
			xloc++;
		}
		yloc++;
	}
	free(pp);
}
