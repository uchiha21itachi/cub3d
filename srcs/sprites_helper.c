/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_check(t_game *g, unsigned char color[4])
{
	if (COLOR_CODE == 1)
	{
		if (color[1] != 0 || color[2] != 0 ||
			color[3] != 0)
			draw_pix(g, g->sp_r->stripe, g->sp_r->y, color);
	}
	else
	{
		if (color[3] != 255)
			draw_pix(g, g->sp_r->stripe, g->sp_r->y, color);
	}
}

void	sort(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < g->p_data->sprite_size - 1)
	{
		while (j < g->p_data->sprite_size - i - 1)
		{
			if (g->sp_r->s_first[j] > g->sp_r->s_first[j + 1])
			{
				g->sp_r->tempx = g->sp_r->s_first[j];
				g->sp_r->s_first[j] = g->sp_r->s_first[j + 1];
				g->sp_r->s_first[j + 1] = g->sp_r->tempx;
				g->sp_r->tempy = g->sp_r->s_second[j];
				g->sp_r->s_second[j] = g->sp_r->s_second[j + 1];
				g->sp_r->s_second[j + 1] = g->sp_r->tempy;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	sortsprites(t_game *g)
{
	int		i;

	if (!(g->sp_r->s_first = (double *)malloc(g->p_data->sprite_size *
		(sizeof(double)))))
		malloc_error_messege('m', g->p_data);
	if (!(g->sp_r->s_second = (double *)malloc(g->p_data->sprite_size *
		(sizeof(double)))))
		malloc_error_messege('m', g->p_data);
	i = -1;
	while (++i < g->p_data->sprite_size)
	{
		g->sp_r->s_first[i] = g->sp_r->dist[i];
		g->sp_r->s_second[i] = g->sp_r->order[i];
	}
	sort(g);
	i = 0;
	while (i < g->p_data->sprite_size)
	{
		g->sp_r->dist[i] = g->sp_r->s_first[g->p_data->sprite_size - i - 1];
		g->sp_r->order[i] = g->sp_r->s_second[g->p_data->sprite_size - i - 1];
		i++;
	}
	i = 0;
	free(g->sp_r->s_first);
	free(g->sp_r->s_second);
}

int		fill(t_parse *p, int x, int y, int i)
{
	if (p->map[x][y] == 2)
	{
		if (i < p->sprite_size)
		{
			p->sprites[i].texture = p->textures[4];
			p->sprites[i].posx = x + 0.5;
			p->sprites[i].posy = y + 0.5;
			i++;
		}
	}
	return (i);
}

void	fill_sprites_data(t_parse *p_data)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	if (p_data->sprite_size > 0)
	{
		if (!(p_data->sprites = (t_sprite *)malloc(sizeof(t_sprite) *
		p_data->sprite_size)))
			malloc_error_messege('m', p_data);
	}
	while (x < p_data->map_x)
	{
		while (y < p_data->map_y)
		{
			i = fill(p_data, x, y, i);
			y++;
		}
		y = 0;
		x++;
	}
}
