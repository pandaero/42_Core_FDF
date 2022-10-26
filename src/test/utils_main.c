// Tests for the functions in utils.c
#include "../../fdf.h"

/* Test for ft_chkarr
// run: cc -Wall -Werror -Wextra utils_main.c ../utils.c ../../libft/libft.a
int main(void)
{
	int	arr1[] = {0, 0, 0, 10, 0};
	int	arr2[5] = {3, 3, 3, 3, 3};
	int	arr3[1] = {5};

	ft_printf("ft_chkarr\n");
	ft_printf("Multi, non:   %d\n", ft_chkarr(arr1, 5));
	ft_printf("Multi, equal: %d\n", ft_chkarr(arr2, 5));
	ft_printf("Single:       %d\n", ft_chkarr(arr3, 1));
	return (0);
}
//*/

/* Test for free_twodee
// run:
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	**matrix;
	int	i;
	int	j;

	matrix = (int **)malloc(2 * sizeof(int *));
	matrix[0] = (int *)malloc(2 * sizeof(int));
	matrix[1] = (int *)malloc(2 * sizeof(int));
	matrix[0][0] = 5;
	matrix[0][1] = 10;
	matrix[1][0] = 2;
	matrix[1][1] = 4;
	//Show matrix
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	//Free matrix
	free_twodee(matrix, 2);
	return (0);
}
//*/

/* Exercise to check array size methods
// run: cc utils_main.c
#include <stdio.h>

int main(void)
{
	int	arr1[8] = {0, 0, 0, 10, 0, 5, 6 ,7};
	int	arr2[5] = {3, 3, 3, 3, 3};
	int	arr3[1] = {5};

	printf("ft_arrsize\n");
	printf(" arr1:     %p\n", arr1);
	printf("&arr1:     %p\n", &arr1);
	printf("arr1 + 1:  %p\n", arr1 + 1);
	printf("&arr1 + 1: %p\n", &arr1 + 1);
	printf("Size arr1: %d\n", *(&arr1 + 1) - arr1);
	printf("Size arr2: %d\n", *(&arr2 + 1) - arr2);
	printf("Size arr3: %d\n", *(&arr3 + 1) - arr3);
	return (0);
}
//*/