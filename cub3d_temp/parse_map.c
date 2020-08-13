/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:36 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:37 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_map(t_parse *p_data)
{
	if (p_data->map_y == 0)
	{
		if (!(p_data->map = (int**)malloc(1 * sizeof(int *))))
			malloc_error_messege('m', p_data);
		if (!(p_data->map_x = (int*)malloc(1 * sizeof(int))))
			malloc_error_messege('m', p_data);
	}
	p_data->map_start = 0;
}

void		fill_map(char *line, t_parse *p_data)
{
	int		x;

	x = 0;
	p_data->map_x[p_data->map_y] = (int)ft_strlen(line);
	if (!(p_data->map[p_data->map_y] = (int *)malloc(sizeof(int) * p_data->map_x[p_data->map_y])))
		malloc_error_messege('m', p_data);
	while (x < p_data->map_x[p_data->map_y])
	{
		if (*line == '0')
			p_data->map[p_data->map_y][x] = 0;
		else if (*line == '1')
			p_data->map[p_data->map_y][x] = 1;
		else if (*line == '2')
			p_data->map[p_data->map_y][x] = 2;
		else if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
		{
			printf("inside grab position\n");
			grab_position(p_data, *line, x);
		}
		else if (*line == ' ')
			p_data->map[p_data->map_y][x] = 3;
		else
			parsing_error_messege('u', p_data);
		x++;
		line++;
	}
}

void		parse_map(char *line, t_parse *p_data)
{
	if (p_data->map_y == 0)
		init_map(p_data);
	else
	{
		update_mapx_size(p_data);
		update_map_size(p_data);
	}
	fill_map(line, p_data);
	p_data->map_y++;
}