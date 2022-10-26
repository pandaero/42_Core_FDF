/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:06:33 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/26 14:31:08 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//Function places a pixel in an image more quickly than with the pixel_put fn.
void	quick_put_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dest;

	dest = 0;
	if (x >= 0 && x < 900 && y >= 0 && y < 1200)
		dest = data->address + (y * data->line_len + x * (data->bits_pp / 8));
	*(unsigned int *)dest = color;
}
