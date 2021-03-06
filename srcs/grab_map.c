/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:13 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:14 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_resolution(char *line, t_parse *p_data)
{
	if (p_data->res_x != -1 || p_data->res_y != -1)
	{
		parsing_error_messege('d', p_data);
		return ;
	}
	if (check_r_line(line) == 0)
	{
		parsing_error_messege('r', p_data);
		return ;
	}
	while (*line++ && (p_data->res_y == -1 || p_data->res_x == -1))
	{
		line = remove_space_digit(line, 's');
		p_data->res_x = get_min(ft_atoi(line), 2560);
		line = remove_space_digit(line, 'd');
		p_data->res_y = get_min(ft_atoi(line), 1440);
	}
	if (p_data->res_x <= 0 || p_data->res_y <= 0)
		parsing_error_messege('r', p_data);
}

void	get_fc_color(char *line, t_parse *p_data)
{
	int		rgb[3];
	char	c;

	if (check_color_line(line) == 0 || check_color_order(line) == 0)
		parsing_error_messege('c', p_data);
	c = *line;
	line++;
	line = remove_space_digit(line, 's');
	rgb[0] = ft_atoi(line);
	line = remove_space_digit(line, 'd');
	line = remove_space_digit(line, 's');
	line++;
	line = remove_space_digit(line, 's');
	rgb[1] = ft_atoi(line);
	line = remove_space_digit(line, 'd');
	line = remove_space_digit(line, 's');
	line++;
	line = remove_space_digit(line, 's');
	rgb[2] = ft_atoi(line);
	if (check_rgb_range(p_data, rgb, c) == 0)
		parsing_error_messege('j', p_data);
}

void	grab_texture(t_parse *p_data, char *filename, int i)
{
	int		temp_arr[3];
	char	*temp;

	temp = ft_strdup(filename);
	p_data->textures[i]->filename = temp;
	p_data->textures[i]->counter++;
	p_data->textures[i]->ptr = mlx_xpm_file_to_image(p_data->temp_mlx, filename,
	&p_data->textures[i]->width, &p_data->textures[i]->height);
	if (p_data->textures[i]->ptr == NULL)
	{
		value_miss_error('t', p_data);
		return ;
	}
	temp_arr[0] = 32;
	temp_arr[1] = p_data->textures[i]->width * 4;
	temp_arr[2] = 0;
	p_data->textures[i]->data = mlx_get_data_addr(p_data->textures[i]->ptr,
	&temp_arr[0], &temp_arr[1], &temp_arr[2]);
	if (p_data->textures[i]->data == 0)
		value_miss_error('t', p_data);
}

int		get_tex_i(char *line, t_parse *p_data)
{
	int		i;

	i = -1;
	if (line[0] == 'N' && line[1] == 'O')
		i = 0;
	else if (line[0] == 'S' && line[1] == 'O')
		i = 1;
	else if (line[0] == 'E' && line[1] == 'A')
		i = 2;
	else if (line[0] == 'W' && line[1] == 'E')
		i = 3;
	else if (line[0] == 'S' && line[1] == ' ')
	{
		i = 4;
		p_data->sprite_size = 0;
	}
	else if (check_tex_count(p_data) == 1 &&
	ft_isspace_isdigit(line[1], 'd') == 1)
	{
		i = 5;
	}
	else
		i = 6;
	return (i);
}

void	get_tex_path(char *line, t_parse *p_data, char *temp_line)
{
	int		i;

	i = get_tex_i(line, p_data);
	if (i == 6)
		parsing_error_messege('t', p_data);
	else if (i == 5)
		parse_map(temp_line, p_data);
	else if (i >= 0 && i <= 4)
	{
		line += 2;
		line = remove_space_digit(line, 's');
		if (p_data->textures[i]->counter != 0)
		{
			parsing_error_messege('d', p_data);
			return ;
		}
		if (check_file_exists(line) == 0)
		{
			parsing_error_messege('t', p_data);
			return ;
		}
		grab_texture(p_data, line, i);
	}
}
