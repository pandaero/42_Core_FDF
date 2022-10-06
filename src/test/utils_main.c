//Tests for the functions in map_reader.c
#include "../../fdf.h"

/* ft_chkarr test
// run: gcc -Wall -Werror -Wextra utils_main.c ../ *.c ../../libft/libft.a
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

/* Array size check tester - exercise
// run: gcc utils_main.c
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