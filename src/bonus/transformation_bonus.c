/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:48:45 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 16:57:04 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

//Function translates the points.
void	translate_bonus(t_pointpair *pp, t_fulldata *full)
{
	pp->x1 += full->translation_horiz;
	pp->y1 += full->translation_vert;
	pp->x2 += full->translation_horiz;
	pp->y2 += full->translation_vert;
}
