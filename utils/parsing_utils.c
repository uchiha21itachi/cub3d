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
		// printf("line  before [%c] [%s]\n", *line, line);
		if (ft_isspace_isdigit(*line, 's'))
		{
			line = remove_space_digit(line, 's');
			// printf("line inside isspace [%c] [%s]\n", *line, line);
		}
		else if (ft_isspace_isdigit(*line, 'd'))
		{
			// printf("line inside isdigit before remove digit[%c] [%s]\n", *line, line);
			line = remove_space_digit(line, 'd');
			// printf("line inside isdigit after remove digit[%c] [%s]\n", *line, line);
			counter++;
		}
		else if (*line == '\0')
		{
			// printf("line inside else[%c] [%s]\n", *line, line);
			return (0);
		}
	}
	if (counter != 2)
	{
		// printf("problem[01] counter - [%d]\n", counter);
		return (0);
	}
	return (1);
}

int		check_color_line(char *line)
{
	int		counter_d;
	int		counter_c;

	counter_d = 0;
	counter_c = 0;
	if (*line == 'F' || *line == 'C')
		line++;
	while (*line)
	{
		if (ft_isspace_isdigit(*line, 's'))
			line = remove_space_digit(line, 's');
		else if (ft_isspace_isdigit(*line, 'd'))
		{
			line = remove_space_digit(line, 'd');
			counter_d++;
		}
		else if (*line == ',')
		{
			line++;
			counter_c++;
		}
		else
			return (0);
	}
	if (counter_c == 2 && counter_d == 3)
		return (1);
	return (0);
}

int		check_color_order(char *line)
{
	int counter;

	counter = 0;
	if (*line != 'F' && *line != 'C')
	{
		printf("error 0\n");
		return (0);
	}
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
		line++;
	}
	return (1);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


