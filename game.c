/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:43:33 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/05 22:43:35 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_game	*game_data_init(t_parse  *p_data, t_game *game)
{
	if (!(game->player = (t_player *)malloc(sizeof (t_player) * 1)))
		printf("error in parsing player in game.c\n");
	game->player->posX = p_data->temp_player->posX;
	game->player->posY = p_data->temp_player->posY;
	game->dirX = -1;
	game->dirY = 0;
	game->planeX = 0;
	game->planeY = 0.66;
	game->time = 0;
	game->old_time = 0;
	game->mapX = -1;
	game->mapY = -1;
	game->cameraX = 0;
	game->rayDirX = 0;
	game->rayDirY = 0;
	game->sideDistX = 0;
	game->sideDistY = 0;
	game->deltaDistX = 0;
	game->deltaDistY = 0;
	game->stepX = 0;
	game->stepY = 0;
	game->side = 0;
	game->perWallDist = 0;
	return(game);
}

t_draw	*draw_data_init(t_draw *draw)
{
	draw->lineHeight = 0;
	draw->drawStart = 0;
	draw->drawEnd = 0;
	return(draw);
}

void	game(t_parse  *p_data)
{
	t_game	*game;
	t_draw	*draw;
	int x;
	int hit;

	x = 0;
	hit = 0;
	if (!(game = (t_game *)malloc(sizeof(t_game))))
		printf("error in mallocing game in game.c\n");
	game = game_data_init(p_data, game);
	
	if (!(draw = (t_draw *)malloc(sizeof(t_draw))))
		printf("error in mallocing draw in draw.c\n");
	draw = draw_data_init(draw);

	while (x < p_data->len_arr[x])
	{
		game->cameraX = 2 * x / p_data->len_arr[x] - 1;

		game->rayDirX = game->dirX + game->planeX * game->cameraX;
		game->rayDirY = game->dirY + game->planeY * game->cameraX;

		game->mapX = game->player->posX;
		game->mapY = game->player->posY;

		game->deltaDistX = (game->rayDirY == 0) ? 0 : ((game->rayDirX == 0) ? 1 : fabs(1 / game->rayDirX));
		game->deltaDistY = (game->rayDirX == 0) ? 0 : ((game->rayDirY == 0) ? 1 : fabs(1 / game->rayDirY));

		hit = 0;
		if (game->rayDirX < 0)
		{
			game->stepX = -1;
			game->sideDistX = (game->player->posX - game->mapX) * game->deltaDistX;
		}
		else
		{
			game->stepX = 1;
			game->sideDistX = (game->mapX + 1.0 - game->player->posX) * game->deltaDistX;
		}
		if (game->rayDirY < 0)
		{
			game->stepY = -1;
			game->sideDistY = (game->player->posY - game->mapY) * game->deltaDistY;
		}
		else
		{
			game->stepX = 1;
			game->sideDistY = (game->mapX + 1.0 - game->player->posY) * game->deltaDistY;
		}
		while (hit == 0)
		{
			if (game->sideDistX < game->sideDistY)
			{
				game->sideDistX += game->deltaDistX;
				game->mapX += game->stepX;
				game->side = 0;
			}
			else
			{
				game->sideDistY += game->deltaDistY;
				game->mapY = game->stepY;
				game->side = 1;
			}
			if (p_data->map[game->mapX][game->mapY] == 1)
				hit = 1;
		}
		if (game->side == 0)
			game->perWallDist = (game->mapX - game->player->posX + (1 - game->stepX) / 2) / game->rayDirX;
		else
			game->perWallDist = (game->mapY - game->player->posY + (1 - game->stepY) / 2) / game->rayDirY;
	
		draw->lineHeight = (int)(p_data->res_y / game->perWallDist);
		draw->drawStart = (-(draw->lineHeight) / 2) + p_data->res_y / 2;
		if(draw->drawStart < 0)
			draw->drawStart = 0;
		draw->drawEnd = (draw->lineHeight / 2) + p_data->res_y / 2;
		if (draw->drawEnd >= p_data->res_y)
			draw->drawEnd = p_data->res_y - 1;
	}
}
