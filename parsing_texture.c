/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:44:32 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/05 22:44:34 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
