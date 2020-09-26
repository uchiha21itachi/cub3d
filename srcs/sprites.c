#include "../includes/cub3d.h"

void	sprite_data_init(t_game *g)
{
	g->sp_r->spriteX = 0;
	g->sp_r->spriteY = 0;
	g->sp_r->invDet = 0;
	g->sp_r->transformX = 0;
	g->sp_r->transformY = 0;
	g->sp_r->sScreenX = 0;
	g->sp_r->sHeight = 0;
	g->sp_r->sWidth = 0;
	g->sp_r->drawStartX = 0;
	g->sp_r->drawStartY = 0;
	g->sp_r->drawEndX = 0;
	g->sp_r->drawEndY = 0;
	g->sp_r->stripe = 0;
	g->sp_r->y = 0;
	g->sp_r->d = 0;
	g->sp_r->tempx = 0;
	g->sp_r->tempy = 0;
	if (!(g->sp_r->order = (int *)malloc((g->p_data->sprite_size) *
		sizeof(int))))
		malloc_error_messege('m', g->p_data);
	if (!(g->sp_r->dist = (double *)malloc((g->p_data->sprite_size) *
		sizeof(double))))
		malloc_error_messege('m', g->p_data);
}

void	get_order_distance(t_game *g)
{
	int		i;

	i = 0;
	while (i < g->p_data->sprite_size)
	{
		g->sp_r->order[i] = i;
		g->sp_r->dist[i] = ((g->posX - g->p_data->sprites[i].posX)
					* (g->posX - g->p_data->sprites[i].posX)
					+ (g->posY - g->p_data->sprites[i].posY)
					* (g->posY - g->p_data->sprites[i].posY));
		i++;
	}
}

void	get_sprite_ren_values(t_game *g, int i)
{
	g->sp_r->spriteX = g->p_data->sprites[g->sp_r->order[i]].posX - g->posX;
	g->sp_r->spriteY = g->p_data->sprites[g->sp_r->order[i]].posY -
		g->posY;
	g->sp_r->invDet = 1.0 / (g->planeX * g->dirY - g->dirX * g->planeY);
	g->sp_r->transformX = g->sp_r->invDet * (g->dirY * g->sp_r->spriteX -
		g->dirX * g->sp_r->spriteY);
	g->sp_r->transformY = g->sp_r->invDet * (-g->planeY * g->sp_r->spriteX +
		g->planeX * g->sp_r->spriteY);
	g->sp_r->sScreenX = (int)((g->p_data->res_x / 2) *
		(1 + g->sp_r->transformX / g->sp_r->transformY));
	g->sp_r->sHeight = abs((int)(g->p_data->res_y /
		(g->sp_r->transformY)));
	g->sp_r->drawStartY = -g->sp_r->sHeight / 2 + g->p_data->res_y / 2;
	if (g->sp_r->drawStartY < 0)
		g->sp_r->drawStartY = 0;
	g->sp_r->drawEndY = g->sp_r->sHeight / 2 + g->p_data->res_y / 2;
	if (g->sp_r->drawEndY >= g->p_data->res_y)
		g->sp_r->drawEndY = g->p_data->res_y - 1;
	g->sp_r->sWidth = abs((int)(g->p_data->res_y / (g->sp_r->transformY)));
	g->sp_r->drawStartX = -g->sp_r->sWidth / 2 + g->sp_r->sScreenX;
	if (g->sp_r->drawStartX < 0)
		g->sp_r->drawStartX = 0;
	g->sp_r->drawEndX = g->sp_r->sWidth / 2 + g->sp_r->sScreenX;
	if (g->sp_r->drawEndX >= g->p_data->res_x)
		g->sp_r->drawEndX = g->p_data->res_x - 1;
}

void	draw_sprites(t_game *g, int *zbuffer, int i)
{
	unsigned char	color[4];

	g->sp_r->texX = (int)(256 * (g->sp_r->stripe - (-g->sp_r->sWidth / 2
		+ g->sp_r->sScreenX)) *
		g->p_data->textwidth / g->sp_r->sWidth) / 256;
	if (g->sp_r->transformY > 0 && g->sp_r->stripe > 0 &&
		g->sp_r->stripe < g->p_data->res_x &&
		g->sp_r->transformY < (double)zbuffer[g->sp_r->stripe] + 0.6)
	{
		g->sp_r->y = g->sp_r->drawStartY;
		while (g->sp_r->y < g->sp_r->drawEndY)
		{
			g->sp_r->d = (g->sp_r->y) * 256 - g->p_data->res_y * 128 +
				g->sp_r->sHeight * 128;
			g->sp_r->texY = ((g->sp_r->d * g->p_data->textheight) /
				g->sp_r->sHeight) / 256;
			get_pixel_color(g->p_data->sprites[g->sp_r->order[i]].texture,
				g->sp_r->texX, g->sp_r->texY, color);
			if (color[1] != 0 || color[2] != 0 ||
				color[3] != 0)
				draw_pix(g, g->sp_r->stripe, g->sp_r->y, color);
			g->sp_r->y++;
		}
	}
}

void	get_sprites(t_game *g_data, int x, int *zbuffer)
{
	int		i;

	i = 0;
	sprite_data_init(g_data);
	get_order_distance(g_data);
	sortsprites(g_data);
	i = 0;
	while (i < g_data->p_data->sprite_size)
	{
		get_sprite_ren_values(g_data, i);
		g_data->sp_r->stripe = g_data->sp_r->drawStartX;
		while (g_data->sp_r->stripe < g_data->sp_r->drawEndX)
		{
			draw_sprites(g_data, zbuffer, i);
			g_data->sp_r->stripe++;
		}
		i++;
	}
	free(g_data->sp_r->order);
	free(g_data->sp_r->dist);
}
