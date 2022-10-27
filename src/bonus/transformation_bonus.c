/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:48:45 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 17:51:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"
#include <math.h>

//Function scales the point pair values by a factor.
void	scale_bonus(t_pointpair *pp, t_fulldata *full)
{
	xyscale(&pp->x1, &pp->y1, full->zoom, 0);
	xyscale(&pp->x2, &pp->y2, full->zoom, 0);
}

//Function translates the points.
void	translate_bonus(t_pointpair *pp, t_fulldata *full)
{
	pp->x1 += full->translation_horiz;
	pp->y1 += full->translation_vert;
	pp->x2 += full->translation_horiz;
	pp->y2 += full->translation_vert;
}

//Function rotates a point pair through an angle in radians.
void	rotate(t_pointpair *pp, t_fulldata *full)
{
	int	x1cp;
	int	y1cp;
	int	x2cp;
	int	y2cp;

	x1cp = pp->x1;
	y1cp = pp->y1;
	x2cp = pp->x2;
	y2cp = pp->y2;
	pp->x1 = (x1cp * cos(full->rotation)) - (y1cp * sin(full->rotation));
	pp->y1 = (x1cp * sin(full->rotation)) + (y2cp * cos(full->rotation));
	pp->x2 = (x2cp * cos(full->rotation)) - (y1cp * sin(full->rotation));
	pp->y2 = (x2cp * sin(full->rotation)) + (y2cp * cos(full->rotation));
}
