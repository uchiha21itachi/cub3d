/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:07:43 by yassharm          #+#    #+#             */
/*   Updated: 2020/10/28 13:07:52 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		move_player(int keycode, t_game *g_data)
{
	if (g_data->posy > g_data->p_data->map_y)
		return (keycode);
	if (g_data->posx > g_data->p_data->map_x)
		return (keycode);
	if (keycode == KEY_W)
		move_up(g_data);
	if (keycode == KEY_S)
		move_down(g_data);
	if (keycode == KEY_D)
		move_right(g_data);
	if (keycode == KEY_A)
		move_left(g_data);
	if (keycode == KEY_RIGHT)
		rotate_right(g_data);
	if (keycode == KEY_LEFT)
		rotate_left(g_data);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(g_data->mlx->mlx, g_data->mlx->mlx_win);
		stop_game_all(g_data);
	}
	return (keycode);
}

int		cross_window(t_game *g_data)
{
	stop_game_all(g_data);
	return (0);
}
