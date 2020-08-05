/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:43:59 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/05 22:44:00 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parse		*get_resolution(char *line, t_parse *p_data)
{
	if (check_r_line(line) == 0)
		parsing_error_messege('r');
	while (*line && (p_data->res_y == 0 || p_data->res_x == 0))
	{
		line = remove_spaces(line);
		p_data->res_x = get_min(ft_atoi(line), 2560);
		line = remove_digits(line);
		p_data->res_y = get_min(ft_atoi(line), 1440);
		line++;
	}
	if (p_data->res_x == 0 || p_data->res_y == 0)
	{
		p_data->map_error = 1;
		parsing_error_messege('r');		
	}
	return (p_data);
}


t_parse		*check_line(char *line, t_parse *p_data)
{
	int			i;
	char		*temp_line;

	temp_line = ft_strdup(line);
	line = remove_spaces(line);
	if(*line == 'R')
		p_data = get_resolution(line, p_data);		
	else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		p_data = get_tex_path(line, p_data);
	else if (ft_isdigit(*line))
		p_data = parse_map(temp_line, p_data);
	else
		printf ("Unexpected error occured in check line while parsing \n\n");	
	free(temp_line);
	return (p_data);
}

t_parse		*parse_data_init(t_parse *p_data, int map_y_size)
{
	p_data->res_x = 0;
	p_data->res_y = 0;
	p_data->map_x = 0;
	p_data->map_check_ret = 1;
	p_data->map_error = 0;
	p_data->map_y = map_y_size;
	p_data->temp_counter = 0;
	p_data->temp_player->posX = -1;
	p_data->temp_player->posY = -1;
	return (p_data);
}

void	parse(char **file, int map_y_size)
{
	int		fd;
	char	*line;
	int 	ret;
	t_parse	*p_data;

	fd = open(file[1], O_RDONLY);
	if (fd < 0)
	{
		printf ("unable to open the file \n");
		exit (0);
	}
	p_data = ft_calloc(sizeof(t_parse), 1);
	//might need to change from calloc to malloc

	p_data->temp_player = (t_player *)malloc(sizeof(t_player *));
	p_data = parse_data_init(p_data, map_y_size);
	printf ("fd is = %d\n", fd);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		p_data = check_line (line, p_data);
		free (line);
	}
	p_data = check_line (line, p_data);
	free (line);
	// print_parse_data(p_data);
	p_data = check_map(p_data);
	create_game(p_data);
	free_map(p_data);
	free(p_data->temp_player);
}
