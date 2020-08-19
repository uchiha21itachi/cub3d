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
		parsing_error_messege('d', p_data);
	if (check_r_line(line) == 0)
	{
		parsing_error_messege('r', p_data);
	}
	while (*line++ && (p_data->res_y == -1 || p_data->res_x == -1))
	{
		line = remove_space_digit(line, 's');
		p_data->res_x = get_min(ft_atoi(line), 2560);
		line = remove_space_digit(line, 'd');
		p_data->res_y = get_min(ft_atoi(line), 1440);
	}
	if (p_data->res_x == -1 || p_data->res_y == -1)
	{
		parsing_error_messege('r', p_data);
	
	}
}

void	get_fc_color(char *line, t_parse *p_data)
{
	int		r;
	int		g;
	int		b;
	char	c;

	if (check_color_line(line) == 0 || check_color_order(line) == 0)
		parsing_error_messege('c', p_data);
	c = *line;
	line++;
	line = remove_space_digit(line, 's');
	r = ft_atoi(line);
	line = remove_space_digit(line, 'd');
	line = remove_space_digit(line, 's');
	line++;
	line = remove_space_digit(line, 's');
	g = ft_atoi(line);
	line = remove_space_digit(line, 'd');
	line = remove_space_digit(line, 's');
	line++;
	line = remove_space_digit(line, 's');
	b = ft_atoi(line);
	if (c == 'F')
		p_data->floor_color = create_trgb(0, r, g, b);
	else if (c == 'C')
		p_data->ceiling_color = create_trgb(0, r, g, b);
}

void	grab_texture(t_parse  *p_data, char *filename, int i)
{
	int 	temp_arr[3];
	char	*temp;

	temp = ft_strdup(filename);
	p_data->textures[i]->filename = temp;
	p_data->textures[i]->counter++;
	p_data->textures[i]->ptr = mlx_xpm_file_to_image(p_data->temp_mlx, filename, &p_data->textures[i]->width, &p_data->textures[i]->height);
	if (p_data->textures[i]->ptr == NULL)
		value_miss_error('t', p_data);
	temp_arr[0] = 32;
	temp_arr[1] = p_data->textures[i]->width * 4;
	temp_arr[2] = 0;

	p_data->textures[i]->data = mlx_get_data_addr(p_data->textures[i]->ptr, &temp_arr[0], &temp_arr[1], &temp_arr[2]);
	if (p_data->textures[i]->data == 0)
		value_miss_error('t', p_data);
	// free (temp);

}	

void	get_tex_path(char *line, t_parse *p_data)
{
	int i;

	i = 0;
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
		printf("sprite path \n");
		return ;
	}
	else
		parsing_error_messege('t', p_data);
	line += 2;
	line = remove_space_digit(line, 's');

	if (p_data->textures[i]->counter != 0)
		parsing_error_messege('d', p_data);
	if (check_file_exists(line) == 0)
		parsing_error_messege('t', p_data);
	grab_texture(p_data, line, i);
}


//---------------------CHANGESSSSS----------------------