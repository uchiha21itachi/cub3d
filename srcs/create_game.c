/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/10/27 16:42:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_data_init(t_game *game)
{
	game->d_data->lineheight = 0;
	game->d_data->drawstart = 0;
	game->d_data->drawend = 0;
	game->d_data->wallx = 0;
	game->d_data->tex_x = 0;
	game->d_data->tex_y = 0;
	game->d_data->step = 0;
	game->d_data->texpos = 0;
}

void	mlx_data_init(t_game *g)
{
	g->mlx->mlx = g->p_data->temp_mlx;
	if (g->mlx->mlx == NULL)
		malloc_error_messege('x', g->p_data);
	g->mlx->mlx_win = mlx_new_window(g->mlx->mlx,
		g->p_data->res_x, g->p_data->res_y, "cub3d");
	g->img->img = mlx_new_image(g->mlx->mlx,
		g->p_data->res_x, g->p_data->res_y);
	if (g->img->img == NULL)
		malloc_error_messege('x', g->p_data);
	g->img->addr = mlx_get_data_addr(g->img->img,
		&g->img->bits_per_pixel, &g->img->line_length, &g->img->endian);
}

void	game_data_init(t_parse *p_data, t_game *game)
{
	if (!(game->d_data = (t_draw *)malloc(sizeof(t_draw) * 1)))
		malloc_error_messege('m', p_data);
	if (!(game->sp_r = (t_rensp *)malloc(sizeof(t_rensp) * 1)))
		malloc_error_messege('m', p_data);
	if (!(game->mlx = (t_mlx *)malloc(sizeof(t_mlx) * 1)))
		malloc_error_messege('m', p_data);
	if (!(game->img = (t_img*)malloc(sizeof(t_img) * 1)))
		malloc_error_messege('m', p_data);
	game->posx = (double)p_data->temp_posx + 0.5;
	game->posy = (double)p_data->temp_posy + 0.5;
	game->side = 0;
	game->perwalldist = 0;
	game->movespeed = 0.15;
	game->rotspeed = 0.0472665;
	game->rotspeedx = 0.0472665;
	game->p_data = p_data;
	draw_data_init(game);
	set_player_dir(game, p_data);
	mlx_data_init(game);
}

void	start_game(t_parse *p_data)
{
	t_game	*g_data;

	if (!(g_data = (t_game *)malloc(sizeof(t_game) * 1)))
		malloc_error_messege('m', p_data);
	fill_sprites_data(p_data);
	game_data_init(p_data, g_data);
	render_map(g_data);
	if (p_data->screenshot == 1)
	{
		take_screenshot(g_data);
		stop_game_all(g_data);
	}
	else
	{
		mlx_hook(g_data->mlx->mlx_win, 2, 1L << 0, move_player, g_data);
		mlx_hook(g_data->mlx->mlx_win, 17, 1L << 17, cross_window, g_data);
		mlx_loop(g_data->mlx->mlx);
	}
}
