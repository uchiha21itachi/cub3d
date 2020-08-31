#include "../includes/cub3d.h"

void	get_draw_values(t_game *g)
{
	if (g->side == 0)
		g->perWallDist = (g->mapX - g->posX + (1 - g->stepX) / 2) / g->rayDirX;
	else
		g->perWallDist = (g->mapY - g->posY + (1 - g->stepY) / 2) / g->rayDirY;
	if (g->perWallDist <= 0.0000001f)
		return ;
	g->d_data->lineHeight = (int)(g->p_data->res_y / g->perWallDist);
	g->d_data->drawStart = (-(g->d_data->lineHeight) / 2) +
		g->p_data->res_y / 2;
	if (g->d_data->drawStart < 0)
		g->d_data->drawStart = 0;
	g->d_data->drawEnd = (g->d_data->lineHeight / 2) + g->p_data->res_y / 2;
	if (g->d_data->drawEnd >= g->p_data->res_y)
		g->d_data->drawEnd = g->p_data->res_y - 1;
}

void	dda(t_game *g)
{
	if (g->sideDistX < g->sideDistY)
	{
		g->sideDistX += g->deltaDistX;
		g->mapX += g->stepX;
		g->side = 0;
	}
	else
	{
		g->sideDistY += g->deltaDistY;
		g->mapY += g->stepY;
		g->side = 1;
	}
	if (g->p_data->map[g->mapY][g->mapX] == 1)
		g->hit = 1;
}

void	get_render_values_help(t_game *g, int x)
{
	if (g->rayDirX < 0)
	{
		g->stepX = -1;
		g->sideDistX = (g->posX - g->mapX) * g->deltaDistX;
	}
	else
	{
		g->stepX = 1;
		g->sideDistX = (g->mapX + 1.0 - g->posX) * g->deltaDistX;
	}
	if (g->rayDirY < 0)
	{
		g->stepY = -1;
		g->sideDistY = (g->posY - g->mapY) * g->deltaDistY;
	}
	else
	{
		g->stepY = 1;
		g->sideDistY = (g->mapY + 1.0 - g->posY) * g->deltaDistY;
	}
}

void	get_render_values(t_game *g, int x)
{
	g->cameraX = 2 * x / (double)g->p_data->res_x - 1;
	g->rayDirX = g->dirX + g->planeX * g->cameraX;
	g->rayDirY = g->dirY + g->planeY * g->cameraX;
	g->mapX = (int)g->posX;
	g->mapY = (int)g->posY;
	g->deltaDistX = fabs(1 / g->rayDirX);
	g->deltaDistY = fabs(1 / g->rayDirY);
	get_render_values_help(g, x);
}

void	render_map(t_game *g)
{
	int		x;
	int		zbuffer[g->p_data->res_x];

	x = 0;
	while (x < g->p_data->res_x)
	{
		if (g->posY > g->p_data->map_y - 1 || g->posY < 0 || g->posX < 0 ||
		(g->posX > g->p_data->map_x[(int)g->posY]))
			return ;
		if (g->p_data->map[(int)g->posY][(int)g->posX] == 1)
			return ;
		get_render_values(g, x);
		g->hit = 0;
		while (g->hit == 0)
			dda(g);
		get_draw_values(g);
		if (g->perWallDist <= 0.0000001f)
			return ;
		draw_texture(g, x);
		zbuffer[x] = g->perWallDist;
		x++;
	}
	get_sprites(g, x, zbuffer);
	if (g->p_data->screenshot == 0)
		mlx_put_image_to_window(g->mlx->mlx, g->mlx->mlx_win, g->img->img, 0, 0);
}

