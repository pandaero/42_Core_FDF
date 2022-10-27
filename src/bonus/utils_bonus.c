/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:51:38 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 17:08:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

//Function initialises many values for the FdF program.
void	initialise(t_fulldata *full)
{
	full->projection = 0;
	full->translation_horiz = X_OFFSET;
	full->translation_vert = Y_OFFSET;
	full->zoom = (WIDTH / full->map->width + HEIGHT / full->map->depth) / 4;
	full->mlx = mlx_init();
	full->mlxwin = mlx_new_window(full->mlx, WIDTH, HEIGHT, "FdF Bonus");
	full->img->image = mlx_new_image(full->mlx, WIDTH, HEIGHT);
	full->img->address = mlx_get_data_addr(full->img->image, \
			&full->img->bits_pp, &full->img->line_len, &full->img->endian);
}
