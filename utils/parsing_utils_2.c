/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	grab_position(t_parse *p_data, char c, int x)
{
	if (p_data->temp_posx != -1 || p_data->temp_posy != -1 ||
		p_data->orient != 32)
	{
		p_data->map[x][p_data->map_y] = 0;
		parsing_error_messege('p', p_data);
		return ;
	}
	p_data->temp_posx = x;
	p_data->temp_posy = p_data->map_y;
	p_data->orient = c;
	p_data->map[x][p_data->map_y] = 0;
}

void	set_player_dir(t_game *g_data, t_parse *p_data)
{
	if (p_data->orient == 'N')
		set_pos_north(g_data);
	else if (p_data->orient == 'S')
		set_pos_south(g_data);
	else if (p_data->orient == 'E')
		set_pos_east(g_data);
	else if (p_data->orient == 'W')
		set_pos_west(g_data);
}

int		check_tex_path(char *line)
{
	int len;

	len = (int)ft_strlen(line);
	if (line[len - 1] == 'm' &&
		line[len - 2] == 'p' &&
		line[len - 3] == 'x')
		return (1);
	return (0);
}

int		check_tex_count(t_parse *p_data)
{
	if (p_data->textures[0]->counter == 1 &&
	p_data->textures[1]->counter == 1 &&
	p_data->textures[2]->counter == 1 &&
	p_data->textures[3]->counter == 1 &&
	p_data->textures[4]->counter == 1)
	{
		return (1);
	}
	return (0);
}

int		check_rgb_range(t_parse *p, int rgb[3], char c)
{
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255 ||
		rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		return (0);
	if (c == 'F')
		p->floor_color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	else if (c == 'C')
		p->ceiling_color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (1);
}
