
#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void		create_game(char  *file)
{
	t_mlx	game;
	t_img	img;

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(game.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(game.mlx, game.mlx_win, img.img, 0, 0);
	mlx_loop(game.mlx);
}
