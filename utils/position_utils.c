/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_pos_west(t_game *g_data)
{
	g_data->dirx = -1;
	g_data->diry = 0;
	g_data->planex = 0;
	g_data->planey = -0.66;
}

void	set_pos_east(t_game *g_data)
{
	g_data->dirx = 1;
	g_data->diry = 0;
	g_data->planex = 0;
	g_data->planey = 0.66;
}

void	set_pos_south(t_game *g_data)
{
	g_data->dirx = 0;
	g_data->diry = 1;
	g_data->planex = -0.66;
	g_data->planey = 0;
}

void	set_pos_north(t_game *g_data)
{
	g_data->dirx = 0;
	g_data->diry = -1;
	g_data->planex = 0.66;
	g_data->planey = 0;
}
