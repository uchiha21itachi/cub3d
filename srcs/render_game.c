#include "../includes/cub3d.h"

void	get_draw_values(t_game *g)
{
	if (g->side == 0)
		g->perwalldist = (g->mapx - g->posx + (1 - g->stepx) / 2) / g->raydirx;
	else
		g->perwalldist = (g->mapy - g->posy + (1 - g->stepy) / 2) / g->raydiry;
	if (g->perwalldist <= 0.0000001f)
		return ;
	g->d_data->lineheight = (int)(g->p_data->res_y / g->perwalldist);
	g->d_data->drawstart = (-(g->d_data->lineheight) / 2) +
		g->p_data->res_y / 2;
	if (g->d_data->drawstart < 0)
		g->d_data->drawstart = 0;
	g->d_data->drawend = (g->d_data->lineheight / 2) + g->p_data->res_y / 2;
	if (g->d_data->drawend >= g->p_data->res_y)
		g->d_data->drawend = g->p_data->res_y - 1;
}

void	dda(t_game *g)
{
	if (g->sidedistx < g->sidedisty)
	{
		g->sidedistx += g->deltadistx;
		g->mapx += g->stepx;
		g->side = 0;
	}
	else
	{
		g->sidedisty += g->deltadisty;
		g->mapy += g->stepy;
		g->side = 1;
	}
	if (g->p_data->map[g->mapy][g->mapx] == 1)
		g->hit = 1;
}

void	get_render_values_help(t_game *g, int x)
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->posx - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->posx) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->posy - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->posy) * g->deltadisty;
	}
}

void	get_render_values(t_game *g, int x)
{
	g->camerax = 2 * x / (double)g->p_data->res_x - 1;
	g->raydirx = g->dirx + g->planex * g->camerax;
	g->raydiry = g->diry + g->planey * g->camerax;
	g->mapx = (int)g->posx;
	g->mapy = (int)g->posy;
	g->deltadistx = fabs(1 / g->raydirx);
	g->deltadisty = fabs(1 / g->raydiry);
	get_render_values_help(g, x);
}

void	render_map(t_game *g)
{
	int		x;
	int		zbuffer[g->p_data->res_x];

	x = 0;
	while (x < g->p_data->res_x)
	{
		if (g->posy > g->p_data->map_y - 1 || g->posy < 0 || g->posx < 0 ||
		(g->posx > g->p_data->map_x[(int)g->posy]))
			return ;
		if (g->p_data->map[(int)g->posy][(int)g->posx] == 1)
			return ;
		get_render_values(g, x);
		g->hit = 0;
		while (g->hit == 0)
			dda(g);
		get_draw_values(g);
		if (g->perwalldist <= 0.0000001f)
			return ;
		draw_texture(g, x);
		zbuffer[x] = g->perwalldist;
		x++;
	}
	get_sprites(g, x, zbuffer);
	mlx_put_image_to_window(g->mlx->mlx, g->mlx->mlx_win, g->img->img, 0, 0);
}
