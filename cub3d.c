#include "minilibx/mlx.h"
#include <stdio.h>

int main ()
{
    void *mlx_ptr;
    void *win_ptr;
    int i;
    int j;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        printf ("NULL returned. No connection established");

    win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "hello world");
    i = 299;
    j = 299;
    while (++i <= 600)
    {
        while (++j <= 600)
            mlx_pixel_put(mlx_ptr, win_ptr, i , j, (150,120,120,120));
        j = 299;
    }
    mlx_loop(mlx_ptr);
}