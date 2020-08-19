#include "../includes/cub3d.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		verLine(int x, t_game *g_data, int color, t_img *img)
{
	int i;

	i = 0;
	
	// printf("lineheight - [%d] drawstart - [%d] drawend - [%d]\n", g_data->d_data->lineHeight, g_data->d_data->drawStart, g_data->d_data->drawEnd);
	// printf("ceiling color - [%d] \n", g_data->p_data->ceiling_color);
	// printf("floor color - [%d] \n", g_data->p_data->floor_color);
	// printf("color - [%d] \n", color);
	while (i < g_data->d_data->drawStart)
	{
		my_mlx_pixel_put(img, x, i, g_data->p_data->ceiling_color);
		i++;
	}
		// printf("Later mapX - [%d], mapY [%d]\n", g_data->mapX ,g_data->mapY);

	i = g_data->d_data->drawStart;
	while (i < g_data->d_data->drawEnd)
	{
		my_mlx_pixel_put(img, x, i, color);
		i++;
	}
	i = g_data->d_data->drawEnd;
	while (i < g_data->p_data->res_y)
	{
		my_mlx_pixel_put(img, x, i, g_data->p_data->floor_color);
		i++;
	}

}
		// printf("xmap = [%d] ymap = [%d]\n", xMap, yMap);
		// printf("map[%d][%d] - [%d]\n", yMap, xMap, g_data->p_data->map[yMap][xMap]);
			// printf("****posX:|%f|\n", g_data->posX);
			// printf("after****posX:|%f|\n", g_data->posX);
			// printf("****posY:|%f|\n", g_data->posY);
			// printf("after****posY:|%f|\n", g_data->posY);
		// printf("****g_data.player.posX:|%f|\n", g_data->posX);
		// g_data->posX -= 1;
		// printf("****after game.player.posX:|%f|\n", g_data->posX);

int			move_player(int keycode, t_game *g_data)
{
	
	// printf("keycode: [%d]\n", keycode);
	
	
	int xMap;
	int yMap;


	if(keycode == KEY_W)
		move_up(g_data);
	if(keycode == KEY_S)
		move_down(g_data);
	if (keycode == KEY_D)
		move_right(g_data);
	if(keycode == KEY_A)
		move_left(g_data);
	if(keycode == KEY_RIGHT)
		rotate_right(g_data);
    if(keycode == KEY_LEFT)
		rotate_left(g_data);
	if(keycode == KEY_ESC)
			mlx_destroy_window(g_data->mlx->mlx, g_data->mlx->mlx_win);
	return (keycode);
}


void		draw_game(t_parse *p_data)
{
	t_mlx	*mlx;
	t_img	img;
	t_game	*g_data;
	t_draw	*d_data;
	
	if (!(d_data = (t_draw *)malloc(sizeof(t_draw) * 1)))
		malloc_error_messege('m', p_data);

	if (!(g_data = (t_game *)malloc(sizeof(t_game) * 1)))
		malloc_error_messege('m', p_data);
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx) * 1)))
		malloc_error_messege('m', p_data);


	if ((mlx->mlx = p_data->temp_mlx) == NULL)
		printf("error in initializing the mlx init\n");
	
	mlx->mlx_win = mlx_new_window(mlx->mlx, p_data->res_x, p_data->res_y, "cub3d");
	
	if ((img.img = mlx_new_image(mlx->mlx, p_data->res_x, p_data->res_y)) == NULL)
		printf("error in creating a new image\n");
	
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);	
	
	game_data_init(p_data, g_data, d_data, mlx, &img);
	render_map(g_data);	
	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);


	mlx_hook(g_data->mlx->mlx_win, 2, 1L<<0, move_player, g_data);
	mlx_loop(mlx->mlx);
	free_game_mlx_data(g_data);
}

	// create_game(p_data, mlx, img);

// read_keys();
	// temp = mlx_key_hook(mlx.mlx_win, close_window, &mlx);
	// printf("keycode - %d\n", temp);
	