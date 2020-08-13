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

#include "cub3d.h"

int		main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		arg_error('a');
		exit(0);
	}
	if (check_args(argv, argc) == 1)
		parse(argv);
	else if (check_args(argv, argc) == 2)
		take_screenshot(argv);
	printf("Exiting the simulation.....\n");
	while (1)
	{
	}
	return (0);
}




//check is position should be x y or y x