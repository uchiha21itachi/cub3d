/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:30 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:31 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parsing_error_messege(char c, t_parse *p_data)
{
	if (c == 'r')
	{
		p_data->parse_error = 1;
		printf("Error-\n Wrong map file input in Resolution parsing\n");
	}
	else if (c == 'd')
	{
		p_data->parse_error = 1;
		printf("Error-\n Already parsed line is again in file\n");
	}
	else if (c == 'c')
	{
		p_data->parse_error = 1;
		printf("Error-\n Wrong map file input in colour parsing\n\n");
	}
	else if (c == 'e')
	{
		p_data->parse_error = 1;
		printf("Error-\n Empty line in middle of map (Open map)\n\n");
	}
	else if (c == 'u')
	{
		p_data->parse_error = 1;
		printf("Error-\n Invalid Data in Map file (wrong line)\n\n");
	}
	else if (c == 'p')
	{
		p_data->parse_error = 1;
		printf("Error-\n Player position twice in the map \n\n");
	}
	else if (c == 't')
	{
		p_data->parse_error = 1;
		printf("Error-\n Texture file not opening (Invalid File)\n\n");
	}
}

void	check_map_error(char c, t_parse *p_data, int x, int y)
{
	if (c == 'u')
	{
		p_data->parse_error = 1;
		printf("Error-\n Map open at [%d][%d] up \n\n",y, x);
	}
	else if (c == 'd')
	{
		p_data->parse_error = 1;
		printf("Error-\n Map open at [%d][%d] down \n\n",y, x);
	}
	else if (c == 'r')
	{
		p_data->parse_error = 1;
		printf("Error-\n Map open at [%d][%d] right \n\n",y, x);
	}
	else if (c == 'l')
	{
		p_data->parse_error = 1;
		printf("Error-\n Map open at [%d][%d] left \n\n",y, x);
	}
}

void	value_miss_error(char c, t_parse *p_data)
{
	if (c == 'r')
	{
		p_data->parse_error = 1;
		printf("Error-\n Map file does not contain Resolution \n\n");
	}
	else if (c == 'c')
	{
		p_data->parse_error = 1;
		printf("Error-\n Map file does not contain Floor or Ceiling color \n\n");
	}
	else if (c == 'm')
	{
		p_data->parse_error = 1;
		printf("Error-\n Map file does not contain Map \n\n");
	}
	else if (c == 'p')
	{
		p_data->parse_error = 1;
		printf("Error-\n Map file does not contain player initial position \n\n");
	}
	else if (c == 't')
	{
		p_data->parse_error = 1;
		printf("Error-\n Cannot read or get the texture from specified location \n\n");
	}
	
}

void	malloc_error_messege(char c, t_parse *p_data)
{
	if (c == 'm')
	{
		p_data->parse_error = 2;
		printf("Error \n-- while malloc\n Exiting program\n");
	}
	else if (c == 'x')
	{
		p_data->parse_error = 2;
		printf("Error \n -- mlx pointer returned NULL\n Exiting the program\n");
	}
	else if (c == 'x')
	{
		p_data->parse_error = 2;
		printf("Error \n -- Problem in creating a new image\n Exiting the program\n");
	}
}










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
	i = 0;
	while (i < p_data->sprite_size)
	{
		printf("pos x - [%f]\n",p_data->sprites[i].posX);
		printf("pos y - [%f]\n",p_data->sprites[i].posY);
		printf("sprite texture - [%s] \n", p_data->sprites[i].texture->filename);
		i++;
	}
}
// 

void	free_parse_data(t_parse *p_data)
{
	int i;
	
	i = 0;
	if (p_data->map_start >= 0)
	{
		while (i < p_data->map_y)
		{
			free(p_data->map[i]);
			i++;
		}
		free(p_data->map);
		free(p_data->map_x);
	}
	i = 0;
	while (i < 5)
	{
		free(p_data->textures[i]->filename);
		free(p_data->textures[i]);
		i++;
	}
	// i = 0;
	// while(i < p_data->sprite_size)
	// {
		free(p_data->sprites);
	// }
	free(p_data);
}

void	free_game_mlx_data(t_game *g_data)
{
	free(g_data->d_data);
	free(g_data->mlx);
	free(g_data->img);
	free(g_data);
	
}
	


//Things to free

//1. textures - intit_parse_data - parsing.c
//2. temp - grab_texture - grab_map.c 
//3. **map - init_map - parse_map.c
//3. map_x - init_map - parse_map.c
//4. *map[] - fill_map - parse_map.c
//5. g_data - start_game - create_game.c *