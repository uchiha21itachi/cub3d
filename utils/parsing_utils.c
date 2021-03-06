/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:19:25 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:19:28 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_r_line(char *line)
{
	int		counter;

	if (*line == 'R')
		line++;
	counter = 0;
	while (*line)
	{
		if (ft_isspace_isdigit(*line, 's'))
			line = remove_space_digit(line, 's');
		else if (ft_isspace_isdigit(*line, 'd'))
		{
			line = remove_space_digit(line, 'd');
			counter++;
		}
		else if (*line == '\0')
			return (0);
		else
			return (0);
	}
	if (counter != 2)
		return (0);
	return (1);
}

int		check_color_line(char *line)
{
	int		counter[2];

	counter[0] = 0;
	counter[1] = 0;
	line++;
	while (*line)
	{
		if (ft_isspace_isdigit(*line, 's'))
			line = remove_space_digit(line, 's');
		else if (ft_isspace_isdigit(*line, 'd'))
		{
			line = remove_space_digit(line, 'd');
			counter[0]++;
		}
		else if (*line == ',')
		{
			line++;
			counter[1]++;
		}
		else
			return (0);
	}
	if (counter[1] == 2 && counter[0] == 3)
		return (1);
	return (0);
}

int		check_color_order(char *line)
{
	int counter;

	counter = 0;
	if (*line != 'F' && *line != 'C')
		return (0);
	line++;
	while (*line)
	{
		if (ft_isspace_isdigit(*line, 's'))
			line = remove_space_digit(line, 's');
		if (!(ft_isspace_isdigit(*line, 'd')) && counter < 3)
			return (0);
		line = remove_space_digit(line, 'd');
		if (ft_isspace_isdigit(*line, 's'))
			line = remove_space_digit(line, 's');
		counter++;
		if (*line != ',' && counter < 3)
			return (0);
		if (*line != '\0')
			line++;
	}
	return (1);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		check_file_exists(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}
