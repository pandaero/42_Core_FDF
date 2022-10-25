/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:06:33 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/25 11:53:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//Function works out the memory address offset of a pixel from its image.
static int	memoffset(int x, int y, int line_len, int bits_pp)
{
	int offset;

	offset = (y * line_len + x * (bits_pp / 8));
	return (offset);
}

//Function places a pixel in an image more quickly than with the pixel_put fn.
void	quick_put_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		dest = data->address + memoffset(x, y, data->line_len, data->bits_pp);
	*(unsigned int *)dest = color;
}
