// Tests for the functions in map_reader.c
#include "../../fdf.h"

/* Test for map_depth
// run: cc -Wall -Werror -Wextra mr_main.c ../map_reader.c ../utils.c ../../libft/libft.a
#include <stdio.h>

int	main(void)
{
	printf("Map depth: %d\n", map_depth("../../test_maps/42.fdf"));
	return (0);
}
//*/

/* Test for map_width
// run: cc -Wall -Werror -Wextra mr_main.c ../map_reader.c ../utils.c ../../libft/libft.a
#include <stdio.h>

int	main(void)
{
	printf("Map width: %d\n", map_width("../../test_maps/42.fdf"));
	return (0);
}
//*/

/* Test for map_data
// compile: cc -g -Wall -Wextra mr_main.c ../map_reader.c ../utils.c ../../libft/libft.a
// run: ./a.out ../../test_maps/42.fdf
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_mapdata	*data;
	int			ret;
	int			i, j;

	data = (t_mapdata *)malloc(sizeof(t_mapdata));
	ret = map_data(data, argv[1]);
	printf("Input file: %s\n", argv[1]);
	printf("Return Value: %d\n", ret);
	if (ret == -1)
		return (0);
	printf("Array: (%d x %d)\n", data->width, data->depth);
	i = 0;
	while (i < data->depth)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->height_data[i][j] >= 10)
				printf("%d ", data->height_data[i][j]);
			else
				printf("%d  ", data->height_data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_twodee(data->height_data, data->depth);
	free(data);
	return (0);
}
//*/
