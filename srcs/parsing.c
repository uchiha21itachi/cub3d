/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_data_init(t_parse *p_data)
{
	int i;

	i = 0;
	p_data->res_x = -1;
	p_data->res_y = -1;
	p_data->floor_color = -1;
	p_data->ceiling_color = -1;
	p_data->parse_error = 0;
	p_data->map_y = 0;
	p_data->map_start = -1;
	p_data->temp_posX = -1;
	p_data->temp_posY = -1;
	p_data->orient = 32;
	p_data->textwidth = 64;
	p_data->textheight = 64;
	p_data->temp_mlx = mlx_init();
	while (i < 5)
	{
		if (!(p_data->textures[i] = (t_texture *)malloc(sizeof(t_texture) * 1)))
			malloc_error_messege('m', p_data);
		p_data->textures[i]->counter = 0;
		i++;
	}
	p_data->sprite_size = -1;
}

void	check_line(char *line, t_parse *p_data)
{
	int			i;
	char		*temp_line;

	temp_line = ft_strdup(line);
	line = remove_space_digit(line, 's');
	if (*line == 'R')
		get_resolution(line, p_data);
	else if (*line == 'F' || *line == 'C')
	{
		if ((*line == 'F' && p_data->floor_color != -1) ||
			(*line == 'C' && p_data->ceiling_color != -1))
			parsing_error_messege('d', p_data);
		else
			get_fc_color(line, p_data);
	}
	else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		get_tex_path(line, p_data);
	else if (ft_isspace_isdigit(*line, 'd') && p_data->map_start < 1)
		parse_map(temp_line, p_data);
	else if (p_data->map_start == 0 && *line == '\0')
		parsing_error_messege('e', p_data);
	else if (*line != '\0')
		parsing_error_messege('u', p_data);
	free(temp_line);
}

void	parse_1(int fd, t_parse *p_data)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line) > 0) && p_data->parse_error < 1)
	{
		check_line(line, p_data);
		free(line);
	}
	check_line(line, p_data);
	free(line);
	if (p_data->parse_error > 0)
		arg_error('e');
}

void	parse(char **file)
{
	int		fd;
	char	*line;
	int		ret;
	t_parse	*p_data;

	if ((fd = open(file[1], O_RDONLY)) < 0 ||
		(p_data = (t_parse *)malloc(sizeof(t_parse))) == NULL)
	{
		arg_error('f');
		exit(0);
	}
	parse_data_init(p_data);
	parse_1(fd, p_data);
	if (p_data->parse_error < 1)
		check_map(p_data);
	if (p_data->parse_error < 1)
		fill_sprites_data(p_data);
	if (p_data->parse_error < 1)
		start_game(p_data);
	// print_data_temp(p_data);
	free_parse_data(p_data);
}
