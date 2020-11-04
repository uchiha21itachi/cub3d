/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:30 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:31 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parsing_error_messege(char c, t_parse *p_data)
{
	p_data->parse_error = 1;
	if (c == 'r')
		ft_putstr("Error-\n Wrong map file input in Resolution parsing\n");
	else if (c == 'd')
		ft_putstr("Error-\n Already parsed line is again in file\n");
	else if (c == 'c')
		ft_putstr("Error-\n Wrong map file input in colour parsing\n\n");
	else if (c == 'e')
		ft_putstr("Error-\n Empty line in middle of map (Open map)\n\n");
	else if (c == 'u')
		ft_putstr("Error-\n Invalid Data in Map file (wrong line)\n\n");
	else if (c == 'p')
		ft_putstr("Error-\n Player position twice in the map \n\n");
	else if (c == 't')
		ft_putstr("Error-\n Texture file not opening (Invalid File)\n\n");
	else if (c == 'z')
		ft_putstr("Error-\n Wrong Texture file extension (Invalid File)\n\n");
	else if (c == 'j')
		ft_putstr("Error-\n Color value out of permitted range (0-255)\n\n");
}

void	check_map_error(char c, t_parse *p_data, int x, int y)
{
	p_data->parse_error = 1;
	if (c == 'u')
		ft_putstr("Error-\n Map open at up \n\n");
	else if (c == 'd')
		ft_putstr("Error-\n Map open at down \n\n");
	else if (c == 'r')
		ft_putstr("Error-\n Map open at right \n\n");
	else if (c == 'l')
		ft_putstr("Error-\n Map open at left \n\n");
	(void)x;
	(void)y;
}

void	value_miss_error(char c, t_parse *p_data)
{
	p_data->parse_error = 1;
	if (c == 'r')
		ft_putstr("Error-\n Map file does not contain Resolution \n\n");
	else if (c == 'c')
	{
		ft_putstr("Error-\n Map file does not contain");
		ft_putstr("Floor or Ceiling color \n\n");
	}
	else if (c == 'm')
		ft_putstr("Error-\n Map file does not contain Map \n\n");
	else if (c == 'p')
	{
		ft_putstr("Error- \n Map file does not");
		ft_putstr(" contain player initial position \n\n");
	}
	else if (c == 't')
	{
		ft_putstr("Error-\n Cannot read or get the texture");
		ft_putstr("from specified location\n\n");
	}
	else if (c == 'z')
	{
		ft_putstr("Error-\n One of texture file missing ");
		ft_putstr("from map file\n\n");
	}
}

void	malloc_error_messege(char c, t_parse *p_data)
{
	p_data->parse_error = 2;
	if (c == 'm')
		ft_putstr("Error \n-- while malloc\n Exiting program\n");
	else if (c == 'x')
	{
		ft_putstr("Error \n -- mlx pointer returned NULL");
		ft_putstr("\n Exiting the program\n");
	}
	else if (c == 'x')
	{
		ft_putstr("Error \n -- Problem in creating a new");
		ft_putstr("image \n Exiting the program\n");
	}
}
