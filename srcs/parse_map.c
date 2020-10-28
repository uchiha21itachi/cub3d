/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_map(t_parse *p_data, int len)
{
	int		i;

	i = -1;
	if (p_data->map_y == 0)
	{
		p_data->map_x = len;
		if (!(p_data->map = (int**)malloc(1 * sizeof(int *) *
			p_data->map_x)))
			malloc_error_messege('m', p_data);
		while (++i < p_data->map_x)
		{
			if (!(p_data->map[i] = (int*)malloc(1 * sizeof(int))))
				malloc_error_messege('m', p_data);
		}
		if (!(p_data->x_arr = (int *)malloc(1 * sizeof(int))))
			malloc_error_messege('m', p_data);
		p_data->x_arr[p_data->map_y] = p_data->map_x;
	}
	p_data->map_start = 0;
}

void		fill_map_help(t_parse *p_data, int x)
{
	while (x < p_data->map_x)
	{
		p_data->map[x][p_data->map_y] = 3;
		x++;
	}
}

void		fill_map(char *line, t_parse *p_data)
{
	int		x;
	int		len;

	x = -1;
	len = (int)ft_strlen(line);
	while (++x < len)
	{
		if (*line == '0')
			p_data->map[x][p_data->map_y] = 0;
		else if (*line == '1')
			p_data->map[x][p_data->map_y] = 1;
		else if (*line == '2')
		{
			p_data->sprite_size++;
			p_data->map[x][p_data->map_y] = 2;
		}
		else if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
			grab_position(p_data, *line, x);
		else if (*line == ' ')
			p_data->map[x][p_data->map_y] = 3;
		else
			parsing_error_messege('u', p_data);
		line++;
	}
	fill_map_help(p_data, x);
}

void		parse_map(char *line, t_parse *p_data)
{
	if (p_data->map_x == 0)
		init_map(p_data, (int)ft_strlen(line));
	else
	{
		if ((int)ft_strlen(line) > p_data->map_x)
			p_data->map_x = (int)ft_strlen(line);
		update_map_size(p_data);
		update_xarr_size(p_data);
		p_data->x_arr[p_data->map_y] = p_data->map_x;
	}
	fill_map(line, p_data);
	p_data->map_y++;
}
