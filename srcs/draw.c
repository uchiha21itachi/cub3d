#include "../includes/cub3d.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void		get_pixel_color(t_texture *texture, int x, int y, unsigned char *result)
{

	int index;
	int i;

	// printf("texture width - [%d] texture height - [%d]\n", texture->width, texture->height);
		
	if (x >= texture->width || y >= texture->height)
		return ;
	if (x < 0 || y < 0)
		return ;
	index = (x + y * texture->width) * 4;
	i = -1;
	while (++i < 4)
	{
		result[i] = (int)texture->data[index + i];
	}
	// printf("result[0] - [%d]\n", result[0]);
	// printf("result[1] - [%d]\n", result[1]);
	// printf("result[2] - [%d]\n", result[2]);
	// printf("result[3] - [%d]\n", result[3]);
}

void	draw_pixel(t_game *g_data, unsigned int x, unsigned int y, unsigned char color[4])
{
	int index;
	int	i;

	if (x >= g_data->p_data->res_x || y >= g_data->p_data->res_y)
		return ;
	index = x * 4 + (y * g_data->img->line_length);
	i = -1;
	while (++i < 4)
		g_data->img->addr[index + i] = color[i];
}

int			move_player(int keycode, t_game *g_data)
{
	printf("in\n");
	if (g_data->posY > g_data->p_data->map_y)
	{
		printf("inside return y great\n");
		return (keycode);
	}
	if (g_data->posX > g_data->p_data->map_x[(int)g_data->posY])
	{
		printf("inside return X great\n");
		return (keycode);
	}
	
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
	printf("out\n");
	
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
	// mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);


	mlx_hook(g_data->mlx->mlx_win, 2, 1L<<0, move_player, g_data);
	mlx_loop(mlx->mlx);
	free_game_mlx_data(g_data);
}
