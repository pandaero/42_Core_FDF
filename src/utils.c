/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:24:53 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/02 17:56:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//Function checks that all the values in a 1D array are the same.
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
