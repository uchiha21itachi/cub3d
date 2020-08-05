
#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void		draw_2d_map(t_mlx game, t_img img, t_parse *p_data)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i < p_data->map_y)
// 	{
// 		while (j < p_data->len_arr[i])
// 		{	
// 			if(p_data->map[i][j] == 1)
// 				my_mlx_pixel_put(&img, i, j, 0x00FF0000);
// 			else if(p_data->map[i][j] == 0)
// 				my_mlx_pixel_put(&img, i, j, 0x0000FF00);
// 			else
// 				my_mlx_pixel_put(&img, i, j, 0x000000FF);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// }

// void		draw_2d_map(t_mlx game, t_img img, t_parse *p_data)
// {
// 	int i;
// 	int j;

// 	i = 10 * (p_data->res_x / 100);
// 	j = 10 * (p_data->res_x / 100);
	
// 	while (i < (p_data->res_x - (10 * (p_data->res_x/100))))
// 	{				
// 		while (j < (p_data->res_x - (10 * (p_data->res_x/100))))
// 		{
// 			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
// 			j++;
// 		}
// 		j = 10 * (p_data->res_x / 100);
// 		i++;
// 	}
// 	mlx_put_image_to_window(game.mlx, game.mlx_win, img.img, 0, 0);
// 	mlx_loop(game.mlx);
// }

void		create_game(t_parse *p_data)
{
	// t_mlx	game;
	// t_img	img;

	// if ((game.mlx = mlx_init()) == NULL)
		// printf("error in initializing the mlx init\n");
	// game.mlx_win = mlx_new_window(game.mlx, p_data->res_x, p_data->res_y, "cub3d");
	// if ((img.img = mlx_new_image(game.mlx, p_data->res_x, p_data->res_y)) == NULL)
		// printf("error in creating a new image\n");
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	game(p_data);
	// draw_2d_map(game, img, p_data);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	
}


