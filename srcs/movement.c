/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_game *g_data)
{
	int			xmap;
	int			ymap;

	xmap = (int)(g_data->posx + g_data->dirx * g_data->movespeed);
	ymap = (int)(g_data->posy + g_data->diry * g_data->movespeed);
	if (g_data->p_data->map[xmap][(int)(g_data->posy)] == 0)
		g_data->posx += g_data->dirx * g_data->movespeed;
	if (g_data->p_data->map[(int)(g_data->posx)][ymap] == 0)
		g_data->posy += g_data->diry * g_data->movespeed;
	render_map(g_data);
}

void	move_down(t_game *g_data)
{
	int			xmap;
	int			ymap;

	xmap = (int)(g_data->posx - g_data->dirx * g_data->movespeed);
	ymap = (int)(g_data->posy - g_data->diry * g_data->movespeed);
	if (g_data->p_data->map[xmap][(int)g_data->posy] == 0)
		g_data->posx -= g_data->dirx * g_data->movespeed;
	if (g_data->p_data->map[(int)g_data->posx][ymap] == 0)
		g_data->posy -= g_data->diry * g_data->movespeed;
	render_map(g_data);
}

void	move_left(t_game *g_data)
{
	int			xmap;
	int			ymap;
	double		olddirx;
	double		tempx;
	double		tempy;

	g_data->rotspeed = 1.5708;
	olddirx = g_data->dirx;
	tempx = g_data->dirx * cos(-g_data->rotspeed) - g_data->diry *
		sin(-g_data->rotspeed);
	tempy = olddirx * sin(-g_data->rotspeed) + g_data->diry *
		cos(-g_data->rotspeed);
	xmap = (int)(g_data->posx + tempx * g_data->movespeed);
	ymap = (int)(g_data->posy + tempy * g_data->movespeed);
	if (g_data->p_data->map[xmap][(int)g_data->posy] == 0)
		g_data->posx += tempx * g_data->movespeed;
	if (g_data->p_data->map[(int)g_data->posx][ymap] == 0)
		g_data->posy += tempy * g_data->movespeed;
	render_map(g_data);
}

void	move_right(t_game *g_data)
{
	int			xmap;
	int			ymap;
	double		olddirx;
	double		tempx;
	double		tempy;

	g_data->rotspeed = -1.5708;
	olddirx = g_data->dirx;
	tempx = g_data->dirx * cos(g_data->rotspeed) - g_data->diry *
		sin(g_data->rotspeed);
	tempy = olddirx * sin(g_data->rotspeed) + g_data->diry *
		cos(g_data->rotspeed);
	xmap = (int)(g_data->posx - tempx * g_data->movespeed);
	ymap = (int)(g_data->posy - tempy * g_data->movespeed);
	if (g_data->p_data->map[xmap][(int)g_data->posy] == 0)
		g_data->posx -= tempx * g_data->movespeed;
	if (g_data->p_data->map[(int)g_data->posx][ymap] == 0)
		g_data->posy -= tempy * g_data->movespeed;
	render_map(g_data);
}
