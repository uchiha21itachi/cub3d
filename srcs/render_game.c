#include "../includes/cub3d.h"

void		render_map(t_game *g_data)
{
	int		x;
	int		hit;
	int		color;
	int		Zbuffer[g_data->p_data->res_x];

	x = 0;

	while (x < g_data->p_data->res_x)
	{
		if (g_data->posY > g_data->p_data->map_y - 1)
		return ;
	if (g_data->posX > g_data->p_data->map_x[(int)g_data->posY])
		return ;
		//  printf("x [%d]\n",g_data->p_data->map_x[(int)g_data->posY]);
		//  printf("pos x [%f]\n",g_data->posX);
		
	

		g_data->cameraX = 2 * x / (double)g_data->p_data->res_x - 1;
					// printf("camera X - [%f]\n", g_data->cameraX);

		g_data->rayDirX = g_data->dirX + g_data->planeX * g_data->cameraX;
		g_data->rayDirY = g_data->dirY + g_data->planeY * g_data->cameraX;
		// printf("raydirX - [%f] raydirY - [%f] \n", g_data->rayDirX, g_data->rayDirY);
		
		
		g_data->mapX = (int)g_data->posX;
		g_data->mapY = (int)g_data->posY;
		// printf("initial mapX - [%d], mapY [%d]\n", g_data->mapX ,g_data->mapY);

		g_data->deltaDistX = fabs(1 / g_data->rayDirX);
		g_data->deltaDistY = fabs(1 / g_data->rayDirY);
		hit = 0;

		// printf("deltadisX [%f] deltadisY [%f]\n", g_data->deltaDistX, g_data->deltaDistY);

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
			g_data->stepY = 1;
			g_data->sideDistY = (g_data->mapY + 1.0 - g_data->posY) * g_data->deltaDistY;
		}
	 	// printf("sidedistX - [%f], sideDistY [%f]\n", g_data->sideDistX ,g_data->sideDistY);
		// printf("stepX - [%d], stepY [%d]\n", g_data->stepX ,g_data->stepY);
		// printf("Initial mapX - [%d], mapY [%d]\n", g_data->mapX ,g_data->mapY);

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
				g_data->mapY += g_data->stepY;
				g_data->side = 1;
			}
			if (g_data->p_data->map[g_data->mapY][g_data->mapX] == 1)
				hit = 1;
		}
	 	// printf("Later sidedistX - [%f], sideDistY [%f]\n", g_data->sideDistX ,g_data->sideDistY);
		// printf("side - [%d]\n", g_data->side);
		if (g_data->mapX < 0 || g_data->mapY < 0 || g_data->mapY >= g_data->p_data->map_y ||
			g_data->mapX >= g_data->p_data->map_x[g_data->mapY])
		{
			printf("\n\n\n--------------------------------------------------------------\n");
			printf("Later mapX - [%d], mapY [%d]\n", g_data->mapX ,g_data->mapY);
			printf("--------------------------------------------------------------\n\n");
		}

		if (g_data->side == 0)
			g_data->perWallDist = (g_data->mapX - g_data->posX + (1 - g_data->stepX) / 2) / g_data->rayDirX;
		else
			g_data->perWallDist = (g_data->mapY - g_data->posY + (1 - g_data->stepY) / 2) / g_data->rayDirY;
		
		 if (g_data->perWallDist <= 0.0000001f)
		{
			printf("*******returning\n\n");
			// printf("game.player.posX:|%f|\n", g_data->posX);	
			// printf("game.player.posY:|%f|\n", g_data->posY);
		 	return;
		 }

		g_data->d_data->lineHeight = (int)(g_data->p_data->res_y / g_data->perWallDist);
		
		g_data->d_data->drawStart = (-(g_data->d_data->lineHeight) / 2) + g_data->p_data->res_y / 2;
		if(g_data->d_data->drawStart < 0)
			g_data->d_data->drawStart = 0;

		g_data->d_data->drawEnd = (g_data->d_data->lineHeight / 2) + g_data->p_data->res_y / 2;
		if (g_data->d_data->drawEnd >= g_data->p_data->res_y)
			g_data->d_data->drawEnd = g_data->p_data->res_y - 1;
	 	// printf("perWallDist [%f]\n",g_data->perWallDist);
		// printf("game.player.posX:|%f|\n", g_data->posX);		
		draw_texture(g_data, x);
		// printf("game.player.posY:|%f|\n", g_data->posY);

		Zbuffer[x] = g_data->perWallDist;
		if ( x == 100)
		{
			// printf("Zbuffer at 100 [%d]\n", Zbuffer[x]);
			printf("perwalldist at 100 [%f]\n", g_data->perWallDist);

		}
		x++;
	}
	draw_sprites(g_data, x, Zbuffer);
	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);

}