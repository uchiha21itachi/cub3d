#include "../includes/cub3d.h"

void sortSprites(int* order, double* dist, t_game *g_data)
{
  //std::vector<std::pair<double, int>> sprites(g_data->p_data->sprite_size);
	double *sprites_first;
	double *sprites_second;
	int		i;
	int		j;
	double	tempx;
	double	tempy;
	

	sprites_first = (double *)malloc((g_data->p_data->sprite_size) * sizeof(double));
	sprites_second = (double *)malloc((g_data->p_data->sprite_size) * sizeof(double));
	i = 0;
	while(i <  g_data->p_data->sprite_size)
	{
	    sprites_first[i] = dist[i];
    	sprites_second[i] = order[i];
		i++;
	}
   
  	// std::sort(sprites.begin(), sprites.end());
	i = 0;
	j = 0;
	while(i < g_data->p_data->sprite_size-1)
	{
		while(j < g_data->p_data->sprite_size-i-1)
		{
			if (sprites_first[j] > sprites_first[j+1]) 
			{		
				tempx = sprites_first[j];
				sprites_first[j] = sprites_first[j + 1];
				sprites_first[j +1] = tempx;

				tempy = sprites_second[j];
				sprites_second[j]= sprites_second[j + 1];
				sprites_second[j +1]= tempy;
			}
			j++;
		}
		i++;
		j = 0;
	}
	i = 0;
	while (i < g_data->p_data->sprite_size)
	{
	    dist[i] = sprites_first[g_data->p_data->sprite_size - i - 1];
   		order[i] = sprites_second[g_data->p_data->sprite_size - i - 1];
		i++;
	}
	// i = 0;
	// whil/e (i < g_data->p_data->sprite_size)
	// {
	    // printf("dist[%d]: %f\n", i, dist[i]);
		// printf("order[%d]: %d\n", i, order[i]);
	// }
  	free(sprites_first);
  	free(sprites_second);
}

void        draw_sprites(t_game *g_data, int x, int *Zbuffer)
{
    int     *spriteOrder;
	double  *spriteDistance;
	int 	i;

	if (!(spriteOrder = (int *)malloc((g_data->p_data->sprite_size) * sizeof(int))))
		malloc_error_messege('m', g_data->p_data);
	if (!(spriteDistance = (double *)malloc((g_data->p_data->sprite_size) * sizeof(double))))
		malloc_error_messege('m', g_data->p_data);
	i = 0;
	while (i < g_data->p_data->sprite_size)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ( (g_data->posX - g_data->p_data->sprites[i].posX) 
					* (g_data->posX - g_data->p_data->sprites[i].posX)
					+ (g_data->posY - g_data->p_data->sprites[i].posY)
					* (g_data->posX - g_data->p_data->sprites[i].posX));			
		i++;
	}	
	sortSprites(spriteOrder, spriteDistance, g_data);

//   for(int i = 0; i < g_data->p_data->sprite_size; i++) {
    // printf("*****dist[%d]: %f\n", i, spriteDistance[i]);
	// printf("*****order[%d]: %d\n", i, spriteOrder[i]);
//   }
//   printf ("\n\n\n");

	
	double			spriteX;
	double			spriteY;
	double			invDet;
	double			transformX;
	double			transformY;
	int				spriteScreenX;
	int				spriteHeight;
	int				spriteWidth;
	int				drawStartY;
	int				drawEndY;
	int				drawStartX;
	int				drawEndX;
	int				stripe;
	int				texX;
	int				texY;
	
	i = 0;
	while (i < g_data->p_data->sprite_size)
	{
		// printf("pos x = [%f] pos y - [%f] \n", g_data->posX, g_data->posY);
		// printf("I = [%d] spriteorder[i]- [%d] \n", i, spriteOrder[i]);
		
		spriteX = g_data->p_data->sprites[spriteOrder[i]].posX - g_data->posX;
		spriteY = g_data->p_data->sprites[spriteOrder[i]].posY - g_data->posY;
		// printf("spritex - [%f] spritey [%f] \n", spriteX, spriteY);
		
		invDet = 1.0 / (g_data->planeX * g_data->dirY - g_data->dirX * g_data->planeY);
		// printf("invdet = [%f] \n", invDet);
		
		transformX = invDet * (g_data->dirY * spriteX - g_data->dirX * spriteY);
		transformY = invDet * (-g_data->planeY * spriteX + g_data->planeX * spriteY);
		// printf("Transfprm X - [%f] TransformY [%f] \n", transformX, transformY);

		spriteScreenX = (int)( (g_data->p_data->res_x / 2) * (1 + transformX / transformY));
	
		//calculate height of the sprite on screen
		spriteHeight = abs((int) (g_data->p_data->res_y / (transformY)));
		// printf("spritescreenx - [%d] spriteheight [%d] \n", spriteScreenX, spriteHeight);

		//calculate lowest and highest pixel to fill in current stripe
		drawStartY = -spriteHeight / 2 + g_data->p_data->res_y / 2;
		if(drawStartY < 0) 
			drawStartY = 0;
		printf("drawstartY- [%d]\n", drawStartY);
		
		drawEndY = spriteHeight / 2 + g_data->p_data->res_y / 2;
	
		if(drawEndY >= g_data->p_data->res_y) 
			drawEndY = g_data->p_data->res_y - 1;
		printf("drawendY- [%d]\n", drawEndY);

		//calculate width of the sprite
		spriteWidth = abs((int)(g_data->p_data->res_y / (transformY)));
		printf("spritewidth- [%d] spriteheight [%d] \n", spriteWidth, spriteHeight);
		
		drawStartX = -spriteWidth / 2 + spriteScreenX;
	
		if(drawStartX < 0) 
			drawStartX = 0;
		// printf("drawstartX- [%d]\n", drawStartX);

		
		drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= g_data->p_data->res_x) 
			drawEndX = g_data->p_data->res_x - 1;
		// printf("drawendX- [%d]\n", drawEndX);


		// printf("textwidth - [%d] textheight - [%d]\n", g_data->p_data->textwidth, g_data->p_data->textheight);
		// printf("stripe - [%d] \n", stripe);
		// printf("texx - [%d]\n", texX);
		// printf("Transform X - [%f] TransformY [%f] \n", transformX, transformY);
		// printf("stripe [%d] zbuffer[stripe] [%d] \n", stripe, Zbuffer[stripe]);
		// printf("y - [%d] resx - [%d] spriteheight - [%d]\n", y, g_data->p_data->res_x, spriteHeight);

		stripe = drawStartX;

		int y;
		int d;
		

		while (stripe < drawEndX)
		{
			unsigned char	color[4];

			texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * g_data->p_data->textwidth / spriteWidth) / 256;
			if(transformY > 0 && stripe > 0 && stripe < g_data->p_data->res_x && transformY < (double)Zbuffer[stripe] + 0.6)
			{
				y = drawStartY;
				while (y < drawEndY)
				{
					d = (y) * 256 - g_data->p_data->res_y * 128 + spriteHeight * 128;
					texY = ((d * g_data->p_data->textheight) / spriteHeight) / 256;
					get_pixel_color(g_data->p_data->sprites[spriteOrder[i]].texture, texX, texY, color);				
					if (color[0] != 0 || color[1] != 0 || color[2] != 0 || color[3] != 0)
					{
						draw_pixel(g_data, stripe, y, color);
					}
					y++;
				}			
			}
			stripe++;
		}
		i++;
	}
	
	free(spriteOrder);
	free(spriteDistance);
	// mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->vars.img.img, 0, 0);
	
}


void		fill_sprites_data(t_parse *p_data)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;

	if (!(p_data->sprites = (t_sprite *)malloc(sizeof(t_sprite) * p_data->sprite_size)))
			malloc_error_messege('m', p_data);
;
	while (y < p_data->map_y)
	{
		while (x < p_data->map_x[y])
		{
			if (p_data->map[y][x] == 2)
			{

				if (i < p_data->sprite_size)
				{
					p_data->sprites[i].texture = p_data->textures[4];
					p_data->sprites[i].posX = x + 0.5;
					p_data->sprites[i].posY = y + 0.5;
					i++;
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
}
