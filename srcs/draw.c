#include "../includes/cub3d.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		verLine(int x, t_game *g_data, int color, t_img img)
{
	int i;

	i = 0;
	
	printf("lineheight - [%d] drawstart - [%d] drawend - [%d]\n", g_data->d_data->lineHeight, g_data->d_data->drawStart, g_data->d_data->drawEnd);
	printf("ceiling color - [%d] \n", g_data->p_data->ceiling_color);
	printf("floor color - [%d] \n", g_data->p_data->floor_color);
	printf("color - [%d] \n", color);
	while (i < g_data->d_data->drawStart)
	{
		my_mlx_pixel_put(&img, x, i, g_data->p_data->ceiling_color);
		i++;
	}
	i = g_data->d_data->drawStart;
	while (i < g_data->d_data->drawEnd)
	{
		my_mlx_pixel_put(&img, x, i, color);
		i++;
	}
	i = g_data->d_data->drawEnd;
	while (i < g_data->p_data->res_y)
	{
		my_mlx_pixel_put(&img, x, i, g_data->p_data->floor_color);
		i++;
	}
	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, img.img, 0, 0);
}

// int			close_window(int keycode, t_mlx *mlx)
// {		
// 		if(keycode == KEY_ESC)
// 			mlx_destroy_window(mlx->mlx, mlx->mlx_win);
// 		return (keycode);
// }

void		draw_game(t_parse *p_data)
{
	t_mlx	mlx;
	t_img	img;
	
	int		temp;

	if ((mlx.mlx = mlx_init()) == NULL)
		printf("error in initializing the mlx init\n");
	mlx.mlx_win = mlx_new_window(mlx.mlx, p_data->res_x, p_data->res_y, "cub3d");
	if ((img.img = mlx_new_image(mlx.mlx, p_data->res_x, p_data->res_y)) == NULL)
		printf("error in creating a new image\n");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	create_game(p_data, mlx, img);
	
	// mlx_hook(mlx.mlx_win, 2, 1L<<0, close_window, &mlx);
	mlx_loop(mlx.mlx);
}


// read_keys();
	// temp = mlx_key_hook(mlx.mlx_win, close_window, &mlx);
	// printf("keycode - %d\n", temp);
	