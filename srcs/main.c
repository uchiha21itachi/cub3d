/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:22 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:24 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_parse *p_data;

	ft_putstr("Starting Cub3d...\n");
	if ((p_data = (t_parse *)malloc(sizeof(t_parse))) == NULL)
		arg_error('f');
	if (argc < 2 || argc > 3)
	{
		arg_error('a');
		exit(0);
	}
	if (check_args(argv, argc) == 1)
	{
		p_data->screenshot = 0;
		parse(argv, p_data);
	}
	else if (check_args(argv, argc) == 2)
	{
		p_data->screenshot = 1;
		parse(argv, p_data);
	}
	ft_putstr("Exiting the simulation.....\n");
	while (1)
	{
	}
	return (0);
}
