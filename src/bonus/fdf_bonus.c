/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:32:01 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/27 19:16:04 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"
#include <stdlib.h>

//Function closes the program for the close-window hook.
static int	closing(t_fulldata *fulldata)
{
	mlx_destroy_window(fulldata->mlx, fulldata->mlxwin);
	exit(0);
}

//Function handles key releases.
static int	keyrelease(int key, t_fulldata *fulldata)
{
	if (key == 53)
	{
		mlx_destroy_window(fulldata->mlx, fulldata->mlxwin);
		exit(0);
	}
	return (0);
}

//Function handles key presses.
static int	keypress(int key, t_fulldata *fulldata)
{
	if (key == 2)
		fulldata->translation_horiz += 10;
	if (key == 0)
		fulldata->translation_horiz -= 10;
	if (key == 13)
		fulldata->translation_vert -= 10;
	if (key == 1)
		fulldata->translation_vert += 10;
	if (key == 14)
		fulldata->rotation += 0.2;
	if (key == 12)
		fulldata->rotation -= 0.2;
	if (key == 15)
		fulldata->zoom += 1;
	if (key == 3)
		fulldata->zoom -= 1;
	if (key == 8 || key == 48)
	{
		if (fulldata->projection == 0)
			fulldata->projection = 1;
		else if (fulldata->projection == 1)
			fulldata->projection = 0;
	}
	return (0);
}

//Function for the main (bonus) FdF program.
int	main(int argc, char **argv)
{
	t_fulldata	*full;

	if (argc != 2)
		return (1);
	full = (t_fulldata *)malloc(sizeof(t_fulldata));
	full->map = (t_mapdata *)malloc(sizeof(t_mapdata));
	map_data_bonus(full, argv[1]);
	full->img = (t_imgdata *)malloc(sizeof(t_imgdata));
	initialise(full);
	mlx_hook(full->mlxwin, 2, 0, keypress, full);
	mlx_hook(full->mlxwin, 3, 0, keyrelease, full);
	mlx_hook(full->mlxwin, 17, 0, closing, full);
	mlx_loop_hook(full->mlx, frame, full);
	mlx_loop(full->mlx);
	free(full);
	return (0);
}
