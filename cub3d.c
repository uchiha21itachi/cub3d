/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:13:53 by yassharm          #+#    #+#             */
/*   Updated: 2020/07/11 03:13:55 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parse		*get_r(char *line, t_parse *p_data)
{
	p_data->res_x = 0;
	p_data->res_y = 0;
	while (*line && (p_data->res_y == 0 || p_data->res_x == 0))
	{
		line = remove_spaces(line);
		p_data->res_x = get_min(ft_atoi(line), 2560);
		line = remove_digits(line);
		p_data->res_y = get_min(ft_atoi(line), 1440);
		line++;
	}
	if (p_data->res_x == 0 || p_data->res_y == 0)
		parsing_error_messege('i');
	printf ("Resolution X - %d\n", p_data->res_x);
	printf ("Resolution Y - %d\n", p_data->res_y);
	return (p_data);
}

t_parse		*get_tex_path(char *line, t_parse *p_data)
{
	if (*line == 'N' && *(line + 1) == 'O')
	{
		line += 2;
		line = remove_spaces(line);
		// p_data->no_path = line;
		printf ("path North = %s\n", line);

	}
	else if (*line == 'S' && *(line + 1) == 'O')
	{
		line += 2;
		line = remove_spaces(line);
		// p_data->so_path = line;
		printf ("path South = %s\n", line);
	}
	else if (*line == 'W' && *(line + 1) == 'E')
	{
		line += 2;
		line = remove_spaces(line);
		// p_data->we_path = line;
		printf ("path West = %s\n", line);

	}
	else if(*line == 'E' && *(line + 1) == 'A')
	{
		line += 2;
		line = remove_spaces(line);
		// p_data->ea_path = line;
		printf ("path East = %s\n", line);

	}
	else if (*line == 'S' && *(line + 1) == ' ')
	{
		line += 2;
		line = remove_spaces(line);
		// p_data->s_path = line;
		printf ("path Sprite = %s\n", line);

	}
	return (p_data);
}


t_parse		*check_line(char *line, t_parse *p_data)
{
	int		i;
	int		space;

	space = count_spaces(line);
	line = remove_spaces(line);
	if(*line == 'R')
		p_data = get_r(line, p_data);		
	else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		p_data = get_tex_path(line, p_data);
	else if (ft_isdigit(*line))
	{
		parse_map(line, p_data, space);
	}
	else
	{
		printf ("Unexpected error occured in check line while parsing \n\n");	
	}
	return (p_data);
}

void	parse(char **file)
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
	p_data = parse_data_init(p_data);
	printf ("fd is = %d\n", fd);
	
	while ((ret = get_next_line(fd, &line) > 0))
	{
		p_data = check_line (line, p_data);
		free (line);
	}
	p_data = check_line (line, p_data);
	free (line);
	free(p_data);
}
