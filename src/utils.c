/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:24:53 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/26 16:13:03 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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

//Function frees a 2D int array, given its (row) size.
void	free_twodee(int **intarr, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		free(intarr[i]);
		i++;
	}
	free(intarr);
}

//Function handles input errors.
void	error_handling(int argcnt, char *file)
{
	int	fd;

	if (argcnt != 2)
	{
		if (argcnt > 2)
			ft_printf("Too many arguments.\n");
		else
			ft_printf("Too few arguments.\n");
		exit(1);
	}		
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("File Error");
		exit(1);
	}
	else
		close(fd);
}
