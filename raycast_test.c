#include "cub3d.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
  {1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1},
  {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
  {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1},
  {1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
  {1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
  {1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


t_game	*game_data_init(t_parse  *p_data, t_game *game)
{
	game->posX = 22.0;
	game->posY = 15.0;
	game->dirX = -1;
	game->dirY = 0;
	game->planeX = 0;
	game->planeY = 0.66;
	game->time = 0;
	game->old_time = 0;
	game->mapX = -1;//
	game->mapY = -1;//
	game->cameraX = 0;
	game->rayDirX = 0;
	game->rayDirY = 0;

 //length of ray from current position to next x or y-side
	game->sideDistX = 0;
	game->sideDistY = 0;

//length of ray from one x or y-side to next x or y-side
	game->deltaDistX = 0;
	game->deltaDistY = 0;

//what direction to step in x or y-direction (either +1 or -1)
	game->stepX = 0;
	game->stepY = 0;

	game->side = 0;
	game->perWallDist = 0;
	game->moveSpeed = 5;
	game->rotSpeed = 3;
	return(game);
}

t_draw	*draw_data_init(t_draw *draw)
{
	draw->lineHeight = 0;
	draw->drawStart = 0;
	draw->drawEnd = 0;
	return(draw);
}


void	game(t_parse  *p_data, t_mlx mlx, t_img img)
{
	t_game	*game;
	t_draw	*draw;
	int		colour;
	int		x;
	int		hit;

	x = 0;
	hit = 0;
	colour = 31176;
	if (!(game = (t_game *)malloc(sizeof(t_game))))
		printf("error in mallocing game in game.c\n");
	game = game_data_init(p_data, game);
	
	if (!(draw = (t_draw *)malloc(sizeof(t_draw))))
		printf("error in mallocing draw in draw.c\n");
	draw = draw_data_init(draw);
	//screen(screenWidth, screenHeight, 0, "Raycaster");

	while (x < screenWidth)
	{
		//calculate ray position and direction
		game->cameraX = 2 * x / (double)screenWidth - 1;
		game->rayDirX = game->dirX + game->planeX * game->cameraX;
		game->rayDirY = game->dirY + game->planeY * game->cameraX;
		
		//which box of the map we're in
		game->mapX = game->posX;
		game->mapY = game->posY;

		game->deltaDistX = (game->rayDirY == 0) ? 0 : ((game->rayDirX == 0) ? 1 : fabs(1 / game->rayDirX));
		game->deltaDistY = (game->rayDirX == 0) ? 0 : ((game->rayDirY == 0) ? 1 : fabs(1 / game->rayDirY));
		
		hit = 0;

		if (game->rayDirX < 0)
		{
			game->stepX = -1;
			game->sideDistX = (game->posX - game->mapX) * game->deltaDistX;
		}
		else
		{
			game->stepX = 1;
			game->sideDistX = (game->mapX + 1.0 - game->posX) * game->deltaDistX;
		}
		if (game->rayDirY < 0)
		{
			game->stepY = -1;
			game->sideDistY = (game->posY - game->mapY) * game->deltaDistY;
		}
		else
		{
			game->stepX = 1;
			game->sideDistY = (game->mapX + 1.0 - game->posY) * game->deltaDistY;
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
			if (worldMap[game->mapX][game->mapY] == 1)
				hit = 1;
		}
		if (game->side == 0)
			game->perWallDist = (game->mapX - game->posX + (1 - game->stepX) / 2) / game->rayDirX;
		else
			game->perWallDist = (game->mapY - game->posY + (1 - game->stepY) / 2) / game->rayDirY;
	
	    //Calculate height of line to draw on screen
		draw->lineHeight = (int)(screenHeight / game->perWallDist);
		
		//calculate lowest and highest pixel to fill in current stripe
		//lowest
		draw->drawStart = (-(draw->lineHeight) / 2) + screenHeight / 2;
		if(draw->drawStart < 0)
			draw->drawStart = 0;
		
		//highest
		draw->drawEnd = (draw->lineHeight / 2) + screenHeight / 2;
		if (draw->drawEnd >= screenHeight)
			draw->drawEnd = screenHeight - 1;	
		      
		if (game->side == 1) 
			colour = 9843300;
		else
			colour = 31176;
		verLine(x, draw, mlx, img, colour);


		x++;

	}


}
