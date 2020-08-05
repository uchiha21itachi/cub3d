/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:14:06 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/05 22:43:46 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 int main (int argc, char **argv)
 {
	int		map_y_size;

	if (argc < 2 || argc > 3)
		printf ("Wrong Number of arguments\n");
	else
	{
		map_y_size = calculate_map_y_size(argv[1]);
		printf("map y count - %d\n\n\n\n", map_y_size);
		parse(argv, map_y_size);
	}
	printf ("Exiting the simulation.....\n");
	while (1);
	return (0);	 
 }
