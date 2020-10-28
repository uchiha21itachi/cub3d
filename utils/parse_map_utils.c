/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		copy1(t_parse *p_data, int **temp_map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < p_data->map_x)
	{
		while (y < p_data->map_y)
		{
			if (x < p_data->x_arr[y])
				temp_map[x][y] = p_data->map[x][y];
			else
				temp_map[x][y] = 3;
			y++;
		}
		y = 0;
		x++;
	}
}

void		update_map_size(t_parse *p_data)
{
	int		**temp_map;
	int		i;

	i = 0;
	if (!(temp_map = (int **)malloc(sizeof(int *) * p_data->map_x)))
		malloc_error_messege('m', p_data);
	while (i < p_data->map_x)
	{
		if (!(temp_map[i] = (int *)malloc(sizeof(int) * (p_data->map_y + 1))))
			malloc_error_messege('m', p_data);
		i++;
	}
	copy1(p_data, temp_map);
	i = 0;
	while (i < p_data->x_arr[p_data->map_y - 1])
	{
		free(p_data->map[i]);
		i++;
	}
	free(p_data->map);
	p_data->map = temp_map;
}

void		update_xarr_size(t_parse *p_data)
{
	int		*temp_x_arr;
	int		i;

	i = 0;
	if (!(temp_x_arr = (int*)malloc((p_data->map_y) * sizeof(int))))
		malloc_error_messege('m', p_data);
	while (i < p_data->map_y)
	{
		temp_x_arr[i] = p_data->x_arr[i];
		i++;
	}
	free(p_data->x_arr);
	if (!(p_data->x_arr = (int*)malloc((p_data->map_y + 1) * sizeof(int))))
		malloc_error_messege('m', p_data);
	i = 0;
	while (i < p_data->map_y)
	{
		p_data->x_arr[i] = temp_x_arr[i];
		i++;
	}
	free(temp_x_arr);
}
