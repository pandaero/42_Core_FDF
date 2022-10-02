//Tests for the functions in map_reader.c
#include "../../fdf.h"

/* map_depth test
// run: gcc -Wall -Werror -Wextra mr_main.c ../.c ../../libft/libft.a
#include <stdio.h>

int main(void)
{
    printf("Map depth: %d\n", map_depth("../../test_maps/42.fdf"));
    return (0);
}
//*/

//*
// run: gcc -Wall -Werror -Wextra mr_main.c ../ *.c ../../libft/libft.a
#include <stdio.h>

int main(void)
{
    printf("Map width: %d\n", map_width("../../test_maps/42.fdf"));
    return (0);
}
//*/

/* ft_map_converter test
// run: gcc -Wall -Werror -Wextra mr_main.c ../ *.c ../../libft/libft.a
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    int fd;
    int **arr;

    fd = open("./test_maps/42.fdf", O_RDONLY, 0);
    arr = (int **) map_arr(fd);
    printf("TL Values: %d %d %d %d", arr[0][0], arr[0][1],
            arr[1][0], arr[1][1]);
    return (0);
}
//*/

/* line_read test
// run:
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char    **strarr;
    char    *str1 = "2345";
    char    *str2 = "34567";
    char    *str3 = "45678";
    int     *array;
    int     i;

    strarr = (char **)malloc(3 * 10 * sizeof(*strarr));
    i = 0;
    while (str1[i] || str2[i] || str3[i])
    {
        if (str1[i])
            strarr[0][i] = str1[i];
        if (str2[i])
            strarr[1][i] = str2[i];
        if (str3[i])
            strarr[2][i] = str3[i];
        i++;
    }
    return (0);
    array = line_read(strarr);
    return (0);
}
//*/
