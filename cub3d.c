#include "minilibx/mlx.h"
#include <stdio.h>

int main (void)
{
    void *img;
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        printf ("NULL returned. No connection established");
    img = mlx_new_image(mlx_ptr, 1920, 1080);
}













    // void *mlx_ptr;
    // void *win_ptr;
    // int i;
    // int j;

    // mlx_ptr = mlx_init();
    // if (!mlx_ptr)
    //     printf ("NULL returned. No connection established");

    // win_ptr = mlx_new_window(mlx_ptr, 1024, 1024, "hello world");
    // i = 100;
    // j = 100;
    // while (++i <= 600)
    // {
    //     while (++j <= 600)
    //         mlx_pixel_put(mlx_ptr, win_ptr, i , j, 0x0000FF00);
    //     j = 100;
    // }
    // mlx_loop(mlx_ptr);
