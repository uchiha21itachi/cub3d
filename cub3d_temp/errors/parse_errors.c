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

#include "../cub3d.h"

void	parsing_error_messege(char c, t_parse *p_data)
{
	if (c == 'r')
	{
		p_data->parse_error = 1;
		printf("Wrong map file input in Resolution parsing\n");
	}
	else if (c == 'd')
	{
		p_data->parse_error = 1;
		printf("Error- Already parsed line is again in file\n");
	}
	else if (c == 'c')
	{
		p_data->parse_error = 1;
		printf("Error- Wrong map file input in colour parsing\n\n");
	}
	else if (c == 'e')
	{
		p_data->parse_error = 1;
		printf("Error- Empty line in middle of map (Open map)\n\n");
	}
	else if (c == 'u')
	{
		p_data->parse_error = 1;
		printf("Error- Invalid Data in Map file (wrong line)\n\n");
	}
	else if (c == 'p')
	{
		p_data->parse_error = 1;
		printf("Error- Player position twice in the map \n\n");
	}
}

void	malloc_error_messege(char c, t_parse *p_data)
{
	if (c == 'm')
	{
		p_data->parse_error = 2;
		printf("Error -- while malloc\n Exiting program\n");
	}
}

void	print_data_temp(t_parse *p_data)
{
	int i;

	i = 0;
	// while (i < p_data->map_y)
	// {
	// 	printf("length of x[%d] = %d\n", i, p_data->map_x[i]);
	// 	i++;
	// }
	// printf("resx - [%d] resy - [%d], parse error - [%d]\n",
			// p_data->res_x, p_data->res_y, p_data->parse_error);
	// printf("floor color - [%d] ceiling color - [%d], parse error - [%d]\n",
			// p_data->floor_color, p_data->ceiling_color, p_data->parse_error);

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
			p_data->temp_posX, p_data->temp_posY, p_data->orient);
}


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
	free(p_data);
}