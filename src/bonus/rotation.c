/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:03:34 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/26 21:19:26 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"
#include <math.h>

//Function rotates a point pair through the given angle in radians.
void	rotate(t_pointpair *pp, float angle)
{
	int	x1cp;
	int	y1cp;
	int	x2cp;
	int	y2cp;

	x1cp = pp->x1;
	y1cp = pp->y1;
	x2cp = pp->x2;
	y2cp = pp->y2;
	pp->x1 = (x1cp * cos(angle)) - (y1cp * sin(angle));
	pp->y1 = (x1cp * sin(angle)) + (y2cp * cos(angle)); 
	pp->x2 = (x2cp * cos(angle)) - (y1cp * sin(angle));
	pp->y2 = (x2cp * sin(angle)) + (y2cp * cos(angle));
}
