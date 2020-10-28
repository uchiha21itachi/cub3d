/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	grab_draw_tex_values(t_game *g)
{
	if (g->side == 0)
		g->d_data->wallx = g->posy + g->perwalldist * g->raydiry;
	else
		g->d_data->wallx = g->posx + g->perwalldist * g->raydirx;
	g->d_data->wallx -= floor((g->d_data->wallx));
	g->d_data->tex_x = (int)(g->d_data->wallx * (double)(g->p_data->textwidth));
	if (g->side == 0 && g->raydirx > 0)
		g->d_data->tex_x = g->p_data->textwidth - g->d_data->tex_x - 1;
	if (g->side == 1 && g->raydiry < 0)
		g->d_data->tex_x = g->p_data->textwidth - g->d_data->tex_x - 1;
	g->d_data->step = 1.0 * g->p_data->textheight / g->d_data->lineheight;
	g->d_data->texpos = (g->d_data->drawstart - g->p_data->res_y / 2
		+ g->d_data->lineheight / 2) * g->d_data->step;
}

void	draw_ceiling_floor(t_game *g_data, int x, char c)
{
	int				i;

	if (c == 'c')
	{
		i = 0;
		while (i < g_data->d_data->drawstart)
		{
			my_mlx_pixel_put(g_data->img, x, i, g_data->p_data->ceiling_color);
			i++;
		}
	}
	if (c == 'f')
	{
		i = g_data->d_data->drawend;
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

	i = g->d_data->drawstart;
	while (i < g->d_data->drawend)
	{
		g->d_data->tex_y = (int)g->d_data->texpos &
			(g->p_data->textheight - 1);
		g->d_data->texpos += g->d_data->step;
		if (g->side == 0 && g->raydirx < 0)
			j = 3;
		else if (g->side == 0 && g->raydirx >= 0)
			j = 2;
		else if (g->side == 1 && g->raydiry < 0)
			j = 0;
		else
			j = 1;
		get_pixel_color(g->p_data->textures[j], g->d_data->tex_x,
			g->d_data->tex_y, color);
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
