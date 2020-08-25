#include "../includes/cub3d.h"

void	draw_data_init(t_draw *draw)
{
	draw->lineHeight = 0;
	draw->drawStart = 0;
	draw->drawEnd = 0;
}

void	game_data_init(t_parse  *p_data, t_game *game, t_draw *d_data, t_mlx *mlx, t_img *img)
{
	game->posX = (double)p_data->temp_posX  + 0.5;
	game->posY = (double)p_data->temp_posY + 0.5;

	// game->posX = 22;
	// game->posY = 12;
	// game->dirX = -1;
	// game->dirY = 0;
	// game->planeX = 0;
	// game->planeY = 0.66;

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
	game->rotSpeed = 0.0472665;
	game->rotSpeedX = 0.0472665;
	game->p_data = p_data;
	game->d_data = d_data;
	game->mlx = mlx;
	game->img = img;
	set_player_dir(game, p_data);
}




void		draw_texture(t_game *g_data, int x)
{
		double wallX; //where exactly the wall was hit
		double step;
		int texX;
		double texPos;
		int i;
		

		if (g_data->side == 0) 
			wallX = g_data->posY + g_data->perWallDist * g_data->rayDirY;
		else
			wallX = g_data->posX + g_data->perWallDist * g_data->rayDirX;
		
		wallX -= floor((wallX));
		texX = (int)(wallX * (double)(g_data->p_data->textwidth));

		if(g_data->side == 0 && g_data->rayDirX > 0) 
			texX = g_data->p_data->textwidth - texX - 1;
		if(g_data->side == 1 && g_data->rayDirY < 0) 
			texX = g_data->p_data->textwidth - texX - 1;

		step  = 1.0 * g_data->p_data->textheight / g_data->d_data->lineHeight;
		texPos = (g_data->d_data->drawStart - g_data->p_data->res_y / 2 + g_data->d_data->lineHeight / 2) * step;

		i = 0;
		while (i < g_data->d_data->drawStart)
		{
			my_mlx_pixel_put(g_data->img, x, i, g_data->p_data->ceiling_color);
			i++;
		}		
		
		i = g_data->d_data->drawStart;
		while (i < g_data->d_data->drawEnd)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (g_data->p_data->textheight - 1);
			texPos += step;
			unsigned char color[4];
			if (g_data->side == 0 && g_data->rayDirX < 0)
			{	//north
				get_pixel_color(g_data->p_data->textures[0], texX, texY, color);
				draw_pixel(g_data, x, i, color);
			}
			else if (g_data->side == 0 && g_data->rayDirX >= 0)
			{
				get_pixel_color(g_data->p_data->textures[1], texX, texY, color);
				draw_pixel(g_data, x, i, color);
			}
			else if (g_data->side == 1 && g_data->rayDirY < 0)
			{
				get_pixel_color(g_data->p_data->textures[2], texX, texY, color);
				draw_pixel(g_data, x, i, color);
			}
			else 
			{
				get_pixel_color(g_data->p_data->textures[3], texX, texY, color);
				draw_pixel(g_data, x, i, color);
			}
			i++;
		}
		i = g_data->d_data->drawEnd;
		while(i < g_data->p_data->res_y)
		{
				my_mlx_pixel_put(g_data->img, x, i, g_data->p_data->floor_color);
				i++;
		}
			// ZBuffer[x] = perWallDist; //perpendicular distance is used

}




































	// printf("posY:|%f|\n", g_data->posY);
	// int xMap;
	// int yMap;
	// if(keycode == KEY_W)
	// {		
	// 	xMap = (int)((g_data->posX + g_data->dirX * moveSpeed));
	// 	yMap = (int)(g_data->posY);
	// 	printf("xmap = [%d] ymap = [%d]", xMap, yMap);
		// if(p_data->map[yMap][xMap] == '0')
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
