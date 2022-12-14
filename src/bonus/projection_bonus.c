/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:26:33 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 11:24:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"
#include <math.h>

//Function applies a parallel projection. Achieved using 45 deg.
void	parallel(int *xco, int *yco, int zco)
{
	int	xcp;
	int	ycp;

	xcp = *xco;
	ycp = *yco;
	*xco = xcp - (zco * cos(0.785398));
	*yco = ycp - (zco * sin(0.785398));
}

//Function applies projection to a point pair, given map data. Horizontal pairs.
void	projected_horiz_bonus(t_pointpair *pp, t_fulldata *full, int x, int y)
{
	int	z1;
	int	z2;

	z1 = full->map->height_data[y - 1][x - 1] * full->scale;
	z2 = full->map->height_data[y - 1][x] * full->scale;
	if (full->projection == 0)
	{
		isometric(&pp->x1, &pp->y1, z1);
		isometric(&pp->x2, &pp->y2, z2);
	}
	else
	{
		parallel(&pp->x1, &pp->y1, z1);
		parallel(&pp->x2, &pp->y2, z2);
	}
}

//Function applies projection to a point pair, given map data. Horizontal pairs.
void	projected_vert_bonus(t_pointpair *pp, t_fulldata *full, int x, int y)
{
	int	z1;
	int	z2;

	z1 = full->map->height_data[y - 1][x - 1] * full->scale;
	z2 = full->map->height_data[y][x - 1] * full->scale;
	if (full->projection == 0)
	{
		isometric(&pp->x1, &pp->y1, z1);
		isometric(&pp->x2, &pp->y2, z2);
	}
	else
	{
		parallel(&pp->x1, &pp->y1, z1);
		parallel(&pp->x2, &pp->y2, z2);
	}
}
