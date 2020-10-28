/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_parse_data(t_parse *p_data)
{
	int i;

	i = 0;
	if (p_data->map_start >= 0)
	{
		while (i < p_data->x_arr[p_data->map_y - 1])
		{
			free(p_data->map[i]);
			i++;
		}
		free(p_data->map);
		free(p_data->x_arr);
	}
	i = 0;
	while (i < 5)
	{
		if (p_data->textures[i]->counter > 0)
			free(p_data->textures[i]->filename);
		free(p_data->textures[i]);
		i++;
	}
	free(p_data->temp_mlx);
}

void	free_sprites(t_game *g_data)
{
	if (g_data->p_data->sprite_size > 0)
		free(g_data->p_data->sprites);
}

void	free_game_mlx_data(t_game *g_data)
{
	free(g_data->d_data);
	free(g_data->mlx);
	free(g_data->img);
	free(g_data->sp_r);
	free(g_data->p_data);
	free(g_data);
}

int		stop_game_all(t_game *g_data)
{
	free_sprites(g_data);
	free_parse_data(g_data->p_data);
	free_game_mlx_data(g_data);
	exit(EXIT_SUCCESS);
}
