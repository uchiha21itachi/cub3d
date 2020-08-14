#include "../includes/cub3d.h"

void	draw_data_init(t_draw *draw)
{
	draw->lineHeight = 0;
	draw->drawStart = 0;
	draw->drawEnd = 0;
}

void	game_data_init(t_parse  *p_data, t_game *game)
{
	game->posX = (double)p_data->temp_posX;
	game->posY = (double)p_data->temp_posY;

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
}


void		create_game(t_parse *p_data, t_mlx mlx, t_img img)
{
	t_game	*g_data;
	t_draw	*d_data;
	int		x;
	int		hit;
	int		color;

	color = p_data->ceiling_color;
	x = 0;
	if (!(g_data = (t_game *)malloc(sizeof(t_game) * 1)))
		malloc_error_messege('m', p_data);
	if (!(d_data = (t_draw *)malloc(sizeof(t_draw) * 1)))
		malloc_error_messege('m', p_data);
	game_data_init(p_data, g_data);
	printf("player x [%f] y [%f]", g_data->posX, g_data->posY);
	while (x < p_data->res_x)
	{
		g_data->cameraX = 2 * x / (double)p_data->res_x - 1;

		g_data->rayDirX = g_data->dirX + g_data->planeX * g_data->cameraX;
		g_data->rayDirY = g_data->dirY + g_data->planeY * g_data->cameraX;
		
		g_data->mapX = (int)g_data->posX;
		g_data->mapY = (int)g_data->posY;
		// printf("player x [%f] y [%f]", g_data->posX, g_data->posY);

		g_data->deltaDistX = (g_data->rayDirY == 0) ? 0 : ((g_data->rayDirX == 0) ? 1 : fabs(1 / g_data->rayDirX));
		g_data->deltaDistY = (g_data->rayDirX == 0) ? 0 : ((g_data->rayDirY == 0) ? 1 : fabs(1 / g_data->rayDirY));
		
		hit = 0;

		if (g_data->rayDirX < 0)
		{
			g_data->stepX = -1;
			g_data->sideDistX = (g_data->posX - g_data->mapX) * g_data->deltaDistX;
		}
		else
		{
			g_data->stepX = 1;
			g_data->sideDistX = (g_data->mapX + 1.0 - g_data->posX) * g_data->deltaDistX;
		}
		if (g_data->rayDirY < 0)
		{
			g_data->stepY = -1;
			g_data->sideDistY = (g_data->posY - g_data->mapY) * g_data->deltaDistY;
		}
		else
		{
			g_data->stepX = 1;
			g_data->sideDistY = (g_data->mapX + 1.0 - g_data->posY) * g_data->deltaDistY;
		}

		while (hit == 0)
		{
			if (g_data->sideDistX < g_data->sideDistY)
			{
				g_data->sideDistX += g_data->deltaDistX;
				g_data->mapX += g_data->stepX;
				g_data->side = 0;
			}
			else
			{
				g_data->sideDistY += g_data->deltaDistY;
				g_data->mapY = g_data->stepY;
				g_data->side = 1;
			}
			if (p_data->map[g_data->mapX][g_data->mapY] == 1)
				hit = 1;
		}

		if (g_data->side == 0)
			g_data->perWallDist = (g_data->mapX - g_data->posX + (1 - g_data->stepX) / 2) / g_data->rayDirX;
		else
			g_data->perWallDist = (g_data->mapY - g_data->posY + (1 - g_data->stepY) / 2) / g_data->rayDirY;
		
		d_data->lineHeight = (int)(p_data->res_y / g_data->perWallDist);
		
		d_data->drawStart = (-(d_data->lineHeight) / 2) + p_data->res_y / 2;
		if(d_data->drawStart < 0)
			d_data->drawStart = 0;

		d_data->drawEnd = (d_data->lineHeight / 2) + p_data->res_y / 2;
		if (d_data->drawEnd >= p_data->res_y)
			d_data->drawEnd = p_data->res_y - 1;
		
		if (g_data->side == 1)
			color = color / 2;
		
		verLine(x, d_data, mlx, img, color);
		x++;
	}
	free(g_data);
	free(d_data);
}