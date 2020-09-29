#include "../includes/cub3d.h"

void	sprite_data_init(t_game *g)
{
	g->sp_r->spritex = 0;
	g->sp_r->spritey = 0;
	g->sp_r->invdet = 0;
	g->sp_r->transformx = 0;
	g->sp_r->transformy = 0;
	g->sp_r->sscreen_x = 0;
	g->sp_r->sheight = 0;
	g->sp_r->swidth = 0;
	g->sp_r->drawstartx = 0;
	g->sp_r->drawstarty = 0;
	g->sp_r->drawendx = 0;
	g->sp_r->drawendy = 0;
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
		g->sp_r->dist[i] = ((g->posx - g->p_data->sprites[i].posx)
					* (g->posx - g->p_data->sprites[i].posx)
					+ (g->posy - g->p_data->sprites[i].posy)
					* (g->posy - g->p_data->sprites[i].posy));
		i++;
	}
}

void	get_sprite_ren_values(t_game *g, int i)
{
	g->sp_r->spritex = g->p_data->sprites[g->sp_r->order[i]].posx - g->posx;
	g->sp_r->spritey = g->p_data->sprites[g->sp_r->order[i]].posy -
		g->posy;
	g->sp_r->invdet = 1.0 / (g->planex * g->diry - g->dirx * g->planey);
	g->sp_r->transformx = g->sp_r->invdet * (g->diry * g->sp_r->spritex -
		g->dirx * g->sp_r->spritey);
	g->sp_r->transformy = g->sp_r->invdet * (-g->planey * g->sp_r->spritex +
		g->planex * g->sp_r->spritey);
	g->sp_r->sscreen_x = (int)((g->p_data->res_x / 2) *
		(1 + g->sp_r->transformx / g->sp_r->transformy));
	g->sp_r->sheight = abs((int)(g->p_data->res_y /
		(g->sp_r->transformy)));
	g->sp_r->drawstarty = -g->sp_r->sheight / 2 + g->p_data->res_y / 2;
	if (g->sp_r->drawstarty < 0)
		g->sp_r->drawstarty = 0;
	g->sp_r->drawendy = g->sp_r->sheight / 2 + g->p_data->res_y / 2;
	if (g->sp_r->drawendy >= g->p_data->res_y)
		g->sp_r->drawendy = g->p_data->res_y - 1;
	g->sp_r->swidth = abs((int)(g->p_data->res_y / (g->sp_r->transformy)));
	g->sp_r->drawstartx = -g->sp_r->swidth / 2 + g->sp_r->sscreen_x;
	if (g->sp_r->drawstartx < 0)
		g->sp_r->drawstartx = 0;
	g->sp_r->drawendx = g->sp_r->swidth / 2 + g->sp_r->sscreen_x;
	if (g->sp_r->drawendx >= g->p_data->res_x)
		g->sp_r->drawendx = g->p_data->res_x - 1;
}

void	draw_sprites(t_game *g, int *zbuffer, int i)
{
	unsigned char	color[4];

	g->sp_r->tex_x = (int)(256 * (g->sp_r->stripe - (-g->sp_r->swidth / 2
		+ g->sp_r->sscreen_x)) *
		g->p_data->textwidth / g->sp_r->swidth) / 256;
	if (g->sp_r->transformy > 0 && g->sp_r->stripe > 0 &&
		g->sp_r->stripe < g->p_data->res_x &&
		g->sp_r->transformy < (double)zbuffer[g->sp_r->stripe] + 0.6)
	{
		g->sp_r->y = g->sp_r->drawstarty;
		while (g->sp_r->y < g->sp_r->drawendy)
		{
			g->sp_r->d = (g->sp_r->y) * 256 - g->p_data->res_y * 128 +
				g->sp_r->sheight * 128;
			g->sp_r->tex_y = ((g->sp_r->d * g->p_data->textheight) /
				g->sp_r->sheight) / 256;
			get_pixel_color(g->p_data->sprites[g->sp_r->order[i]].texture,
				g->sp_r->tex_x, g->sp_r->tex_y, color);
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
		g_data->sp_r->stripe = g_data->sp_r->drawstartx;
		while (g_data->sp_r->stripe < g_data->sp_r->drawendx)
		{
			draw_sprites(g_data, zbuffer, i);
			g_data->sp_r->stripe++;
		}
		i++;
	}
	free(g_data->sp_r->order);
	free(g_data->sp_r->dist);
}
