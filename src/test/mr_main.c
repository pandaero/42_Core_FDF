//Tests for the functions in map_reader.c
#include "../../fdf.h"

/* map_depth test
// run: gcc -Wall -Werror -Wextra mr_main.c ../ *.c ../../libft/libft.a
#include <stdio.h>

int	main(void)
{
	printf("Map depth: %d\n", map_depth("../../test_maps/42.fdf"));
	return (0);
}
//*/

/* map_width test
// run: gcc -Wall -Werror -Wextra mr_main.c ../ *.c ../../libft/libft.a
#include <stdio.h>

int	main(void)
{
	printf("Map width: %d\n", map_width("../../test_maps/42.fdf"));
	return (0);
}
//*/

/* map_data test
// run: gcc -Wall -Werror -Wextra mr_main.c ../ *.c ../../libft/libft.a
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_mapdata	*data;
	int			ret;
	int			i, j;

	data = (t_mapdata *)malloc(sizeof(t_mapdata));
	ret = map_data(data, "../../test_maps/42.fdf");
	printf("Return Value: %d\n", ret);
	printf("Array:\n");
	i = 0;
	while (i < map_depth("../../test_maps/42.fdf"))
	{
		j = 0;
		while (j < map_width("../../test_maps/42.fdf"))
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
	free(data);
	return (0);
}
//*/
