/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:36:06 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 09:24:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "fdf.h"

typedef struct s_fulldata
{
	void		*mlx;
	void		*mlxwin;
	t_imgdata	*img;
	t_mapdata	*map;
	int			zoom;
	int			translation_horiz;
	int			translation_vert;
	float		rotation;
	int			projection;
}				t_fulldata;

// PROGRAM-RELATED
//Function initialises many values for the FdF program.
void	initialise(t_fulldata *full);
//Function determines actions for each new frame.
int		frame(t_fulldata *fulldata);
//Function fills map data from a mapfile (or returns error if invalid).
int		map_data_bonus(t_fulldata *full, char *mapfile);

// IMAGE-RELATED
//Function sets a window-sized image to black.
void	wipe_image(t_imgdata *data);

// GRAPHIC TRANSFORMATIONS
//Function applies a parallel projection. Achieved using 45 deg.
void	parallel(int *xco, int *yco, int zco);
//Function rotates a point pair through an angle in radians.
void	rotate(t_pointpair *pp, t_fulldata *full);
//Function scales the point pair values by a factor.
void	scale_bonus(t_pointpair *pp, t_fulldata *full);
//Function translates the points.
void	translate_bonus(t_pointpair *pp, t_fulldata *full);
//Function applies projection to a point pair, given map data. Horizontal pairs.
void	projected_horiz_bonus(t_pointpair *pp, t_fulldata *full, int x, int y);
//Function applies projection to a point pair, given map data. Vertical pairs.
void	projected_vert_bonus(t_pointpair *pp, t_fulldata *full, int x, int y);
//Function connects points from the grid horizontally.
void	draw_horiz_bonus(t_fulldata *full);
//Function connects points from the grid vertically.
void	draw_vert_bonus(t_fulldata *full);

#endif
