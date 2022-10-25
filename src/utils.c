/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:24:53 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/25 12:01:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>

//Function checks that all the values in a 1D array are the same, size given.
int	ft_chkarr(int *arr, int size)
{
	int	i;

	if (size == 1)
		return (1);
	i = 0;
	while (i < size)
	{	
		if (arr[i] != arr[0])
			return (0);
		i++;
	}
	return (1);
}

//Function frees a 2D int array, given its size.
void	free_twodee(int **intarr, int sz)
{
	int	i;

	i = 0;
	while (i <= sz)
	{
		free(intarr[i]);
		i++;
	}
	free(intarr);
}
