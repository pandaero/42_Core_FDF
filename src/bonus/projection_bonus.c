/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:26:33 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 16:43:47 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

/*
//Function performs a parallel projection of the points entered.
void	parallel(int *xco, int *yco, int *zco)
{

}
*/

//Function applies transformations to grid before using Bresenham's drawing.
void	transform_bonus(t_pointpair *pp, t_fulldata *full)
{
	xyscale(&pp->x1, &pp->y1, full->zoom, 0);
	xyscale(&pp->x2, &pp->y2, full->zoom, 0);
}

//Function applies projection to a point pair, given map data. Horizontal pairs.
void	projected_horiz_bonus(t_pointpair *pp, t_fulldata *full, int x, int y)
{
	int	z1;
	int	z2;

	z1 = full->map->height_data[y - 1][x - 1];
	z2 = full->map->height_data[y - 1][x];
	if (full->projection == 0)
	{
		isometric(&pp->x1, &pp->y1, z1);
		isometric(&pp->x2, &pp->y2, z2);
	}
	/*
	else
	{
		parallel();
		parallel();
	}
	*/
}

//Function applies projection to a point pair, given map data. Horizontal pairs.
void	projected_vert_bonus(t_pointpair *pp, t_fulldata *full, int x, int y)
{
	int	z1;
	int	z2;

	z1 = full->map->height_data[y - 1][x - 1];
	z2 = full->map->height_data[y][x - 1];
	if (full->projection == 0)
	{
		isometric(&pp->x1, &pp->y1, z1);
		isometric(&pp->x2, &pp->y2, z2);
	}
	/*
	else
	{
		parallel();
		parallel();
	}
	*/
}
