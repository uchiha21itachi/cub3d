#include "../includes/cub3d.h"

void sortSprites(t_game *g_data)
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
	    sprites_first[i] = g_data->sp_r->dist[i];
    	sprites_second[i] = g_data->sp_r->order[i];
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
	    g_data->sp_r->dist[i] = sprites_first[g_data->p_data->sprite_size - i - 1];
   		g_data->sp_r->order[i] = sprites_second[g_data->p_data->sprite_size - i - 1];
		i++;
	}
	// i = 0;
	// whil/e (i < g_data->p_data->sprite_size)
	// {
	    // printf("g->sp_r->dist[%d]: %f\n", i, g->sp_r->dist[i]);
		// printf("g->sp_r->order[%d]: %d\n", i, g->order->spriteOrder[i]);
	// }
  	free(sprites_first);
  	free(sprites_second);
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
