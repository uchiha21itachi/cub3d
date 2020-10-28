/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_game *g_data)
{
	double		olddirx;
	double		oldplanex;

	olddirx = g_data->dirx;
	g_data->dirx = g_data->dirx * cos(-g_data->rotspeedx) - g_data->diry *
		sin(-g_data->rotspeedx);
	g_data->diry = olddirx * sin(-g_data->rotspeedx) + g_data->diry *
		cos(-g_data->rotspeedx);
	oldplanex = g_data->planex;
	g_data->planex = g_data->planex * cos(-g_data->rotspeedx) -
		g_data->planey * sin(-g_data->rotspeedx);
	g_data->planey = oldplanex * sin(-g_data->rotspeedx) +
		g_data->planey * cos(-g_data->rotspeedx);
	render_map(g_data);
}

void	rotate_right(t_game *g_data)
{
	double		olddirx;
	double		oldplanex;

	olddirx = g_data->dirx;
	g_data->dirx = g_data->dirx * cos(g_data->rotspeedx) -
		g_data->diry * sin(g_data->rotspeedx);
	g_data->diry = olddirx * sin(g_data->rotspeedx) +
		g_data->diry * cos(g_data->rotspeedx);
	oldplanex = g_data->planex;
	g_data->planex = g_data->planex * cos(g_data->rotspeedx) -
		g_data->planey * sin(g_data->rotspeedx);
	g_data->planey = oldplanex * sin(g_data->rotspeedx) +
		g_data->planey * cos(g_data->rotspeedx);
	render_map(g_data);
}
