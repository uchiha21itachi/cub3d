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

t_parse		get_r(char *line, t_parse p_data, int i)
{
	p_data.res_x = 0;
	p_data.res_y = 0;
	while (line[i] != '\0' && (p_data.res_y == 0 || p_data.res_x == 0))
	{
		while (ft_isspace(line[i]))
			i++;
		while (ft_isdigit(line[i]))
		{
			p_data.res_x = p_data.res_x * 10 + (line[i] - 48);
			i++;
		}
		while (ft_isspace(line[i]))
			i++;
		if (!ft_isdigit(line[i]))
		{
			parse_error_mes('u');
			break;
		}
		while (ft_isdigit(line[i]))
		{
			p_data.res_y = p_data.res_y * 10 + (line[i] - 48);
			i++;
		}
		i++;
	}
	return (p_data);
}

t_parse		get_tex_path(char *line, t_parse p_data, int i)
{
	if (line[i] == 'N' && line[i+1] == 'O')
	{
		i += 2;
		while (ft_isspace(line[i]))
			i++;
		printf ("path North = %s\n", line + i);
	}
	return (p_data);
}

void		check_line(char *line)
{
	int		i;
	t_parse	p_data;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if(line[i] == 'R')
	{
		i++;
		p_data = get_r(line, p_data, i);
		printf ("Resolution X - %d\n", p_data.res_x);
		printf ("Resolution Y - %d\n", p_data.res_y);
	}
	else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
	{
		p_data = get_tex_path(line, p_data, i);
	}
	// else
	// {
	// 	printf ("Unexpected error occured in check line while parsing \n");	
	// }
	
	

}

void	parse(char **file)
{
	int		fd;
	char	*line;
	int 	ret;

	fd = open(file[1], O_RDONLY);
	if (fd < 0)
	{
		printf ("unable to open the file \n");
		exit (0);
	}
	printf ("fd is = %d\n", fd);
	
	while ((ret = get_next_line(fd, &line) > 0))
	{
		check_line (line);
		free (line);
	}
}
