#include "../includes/cub3d.h"

void	print_data_temp(t_parse *p_data)
{
	int i;

	i = 0;
	// printf("resx - [%d] resy - [%d]\n", p_data->res_x, p_data->res_y);
	// printf("floor color - [%d] ceiling color - [%d]\n",p_data->floor_color, p_data->ceiling_color);
	// printf("texture north - [%s] counter = [%d]\n", p_data->textures[0]->filename, p_data->textures[0]->counter);
	// printf("sprite path - [%s] size = [%d]\n", p_data->sprites[0]->texture->filename, p_data->sprite_size);
	i = 0;
	int j;

	j = 0;

	while (i < p_data->map_y)
	{
		while (j < p_data->map_x[i])
		{
			printf("%d", p_data->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("Player position - [%d][%d]\n Oriantation - [%c]\n",
			p_data->temp_posY, p_data->temp_posX, p_data->orient);

	i = 0;
	while (i < 5)
	{
		printf("texture[%d] - [%s] [%d]\n",i, p_data->textures[i]->filename, p_data->textures[i]->width);
		i++;
	}
	printf("done printing textures\n");
	printf("sprite size - [%d] \n", p_data->sprite_size);
}

//Things to free

//1. textures - intit_parse_data - parsing.c
//2. temp - grab_texture - grab_map.c 
//3. **map - init_map - parse_map.c
//3. map_x - init_map - parse_map.c
//4. *map[] - fill_map - parse_map.c
//5. g_data - start_game - create_game.c *	



//Things left
//1. Memory free
//2. Sprite bug (fixed)
//3. Keys linux mac
//4. Norminiette
//5. Clean Exit
//6. map opening when sprites(Fixed not 100 per sure)
//7. fsanitize while --save
//8. four wall covered test(Fixed)