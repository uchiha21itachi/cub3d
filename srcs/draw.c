#include "../includes/cub3d.h"

void	grab_draw_tex_values(t_game *g)
{
	if (g->side == 0)
		g->d_data->wallX = g->posY + g->perWallDist * g->rayDirY;
	else
		g->d_data->wallX = g->posX + g->perWallDist * g->rayDirX;
	g->d_data->wallX -= floor((g->d_data->wallX));
	g->d_data->texX = (int)(g->d_data->wallX * (double)(g->p_data->textwidth));
	if (g->side == 0 && g->rayDirX > 0)
		g->d_data->texX = g->p_data->textwidth - g->d_data->texX - 1;
	if (g->side == 1 && g->rayDirY < 0)
		g->d_data->texX = g->p_data->textwidth - g->d_data->texX - 1;
	g->d_data->step = 1.0 * g->p_data->textheight / g->d_data->lineHeight;
	g->d_data->texPos = (g->d_data->drawStart - g->p_data->res_y / 2
		+ g->d_data->lineHeight / 2) * g->d_data->step;
}

void	draw_ceiling_floor(t_game *g_data, int x, char c)
{
	int				i;

	if (c == 'c')
	{
		i = 0;
		while (i < g_data->d_data->drawStart)
		{
			my_mlx_pixel_put(g_data->img, x, i, g_data->p_data->ceiling_color);
			i++;
		}
	}
	if (c == 'f')
	{
		i = g_data->d_data->drawEnd;
		while (i < g_data->p_data->res_y)
		{
			my_mlx_pixel_put(g_data->img, x, i, g_data->p_data->floor_color);
			i++;
		}
	}
}

void	draw_walls(t_game *g, int x)
{
	unsigned char	color[4];
	int				i;
	int				j;

	i = g->d_data->drawStart;
	while (i < g->d_data->drawEnd)
	{
		g->d_data->texY = (int)g->d_data->texPos &
			(g->p_data->textheight - 1);
		g->d_data->texPos += g->d_data->step;
		if (g->side == 0 && g->rayDirX < 0)
			j = 0;
		else if (g->side == 0 && g->rayDirX >= 0)
			j = 1;
		else if (g->side == 1 && g->rayDirY < 0)
			j = 2;
		else
			j = 3;
		get_pixel_color(g->p_data->textures[j], g->d_data->texX,
			g->d_data->texY, color);
		draw_pix(g, x, i, color);
		i++;
	}
}

void	draw_texture(t_game *g_data, int x)
{
	grab_draw_tex_values(g_data);
	draw_ceiling_floor(g_data, x, 'c');
	draw_walls(g_data, x);
	draw_ceiling_floor(g_data, x, 'f');
}
