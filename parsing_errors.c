/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:44:07 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/05 22:44:08 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	parsing_error_messege(char c)
{
	if (c == 'r')
		printf ("Error - Invalid entry in map file in resolution \n");
	else if (c == 'm')
		printf("Error - Invalid entry in map file in map(fill_map_array)\n");
	else if (c == 'p')
		printf("Error - Player position is twice in map\n");
}


void	print_parse_data(t_parse *p_data)
{
	printf ("Resolution X - %d\n", p_data->res_x);
	printf ("Resolution Y - %d\n", p_data->res_y);
	printf ("Map size Y - %d\n", p_data->map_y);

	// printf ("path North = %s\n", p_data.no_path);
	// printf ("path South = %s\n", p_data.so_path);
	// printf ("path West = %s\n", p_data.we_path);
	// printf ("path East = %s\n", p_data.ea_path);
	// printf ("path Sprite = %s\n", p_data.s_path);

	print_map(p_data);

}


void	print_map(t_parse *p_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (i < p_data->map_y)
	{
		while (j < p_data->len_arr[i])
		{
			if (p_data->map[i][j] == 9)
				printf("* ");
			else
				printf("%d ", p_data->map[i][j]);
			j++;
		}
		printf ("\n");
		j = 0;
		i++;
	}
}
void	print_temp_map(t_parse *p_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (i < p_data->map_y)
	{
		while (j < p_data->len_arr[i])
		{
			printf("%d ", p_data->temp_map[i][j]);
			j++;
		}
		printf ("\n");
		j = 0;
		i++;
	}
}
