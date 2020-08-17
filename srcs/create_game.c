#include "../includes/cub3d.h"

void	draw_data_init(t_draw *draw)
{
	draw->lineHeight = 0;
	draw->drawStart = 0;
	draw->drawEnd = 0;
}

void	game_data_init(t_parse  *p_data, t_game *game, t_draw *d_data, t_mlx *mlx, t_img img)
{
	game->posX = (double)p_data->temp_posX;
	game->posY = (double)p_data->temp_posY;

	// game->posX = 22;
	// game->posY = 12;

	game->dirX = -1;
	game->dirY = 0;
	game->planeX = 0;
	game->planeY = 0.66;
	game->time = 0;
	game->old_time = 0;
	game->cameraX = 0;
	game->rayDirX = 0;
	game->rayDirY = 0;
	game->mapX = -1;
	game->mapY = -1;
	game->deltaDistX = 0;
	game->deltaDistY = 0;
	game->sideDistX = 0;
	game->sideDistY = 0;
	game->stepX = 0;
	game->stepY = 0;
	game->side = 0;
	game->perWallDist = 0;
	game->moveSpeed = 0.15;
	game->rotSpeed = 0.0872665;
	game->p_data = p_data;
	game->d_data = d_data;
	game->mlx = mlx;
	game->img = img;
}



int			move_player(int keycode, t_game *g_data)
{
	
	//the constant value is in squares/second
	
	printf("keycode: [%d]\n", keycode);
	printf("posX:|%f|\n", g_data->posX);
	// printf("posY:|%f|\n", g_data->posY);
	// int xMap;
	// int yMap;
	// if(keycode == KEY_W)
	// {		
	// 	xMap = (int)((g_data->posX + g_data->dirX * moveSpeed));
	// 	yMap = (int)(g_data->posY);
	// 	printf("xmap = [%d] ymap = [%d]", xMap, yMap);
	// 	if(p_data->map[yMap][xMap] == '0')
	// 		g_data->posX += g_data->dirX * moveSpeed;
	// 	if(p_data->map[(int)((g_data->posY + g_data->dirY * moveSpeed))][(int)(g_data->posX)] == '0')
	// 		g_data->posY += g_data->dirY * moveSpeed;
	// 	printf("****game.player.posX:|%f|\n", g_data->posX);
	// 	printf("****game.player.posY:|%f|\n", g_data->posY);

	// 	render_map(a_data);
	// }
	// if(keycode == KEY_S)
	// {
	// 	if(p_data->map[(int)g_data->posY][(int)(g_data->posX - g_data->dirX * moveSpeed)] == '0')
	// 		g_data->posX -= g_data->dirX * moveSpeed;
	// 	if(p_data->map[(int)(g_data->posY - g_data->dirY * moveSpeed)][(int)g_data->posX] == '0')
	// 		g_data->posY -= g_data->dirY * moveSpeed;
	// 	printf("****game.player.posX:|%f|\n", g_data->posX);
	// 	printf("****game.player.posY:|%f|\n", g_data->posY);
	// 	render_map(a_data);
	// }
	if(keycode == KEY_ESC)
			mlx_destroy_window(g_data->mlx->mlx, g_data->mlx->mlx_win);
	return (keycode);
}

void		create_game(t_parse *p_data, t_mlx mlx, t_img img)
{
	t_game	*g_data;
	t_draw	*d_data;
	
	if (!(g_data = (t_game *)malloc(sizeof(t_game) * 1)))
		malloc_error_messege('m', p_data);
	if (!(d_data = (t_draw *)malloc(sizeof(t_draw) * 1)))
		malloc_error_messege('m', p_data);
	
	game_data_init(p_data, g_data, d_data, &mlx, img);
	render_map(g_data);
	mlx_hook(mlx.mlx_win, 2, 1L<<0, move_player, g_data);

	free(g_data);
	free(d_data);
}


