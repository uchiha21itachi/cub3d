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

	if((p_data = (t_parse *)malloc(sizeof(t_parse))) == NULL)
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
	printf("testint===========\n");
	printf("Exiting the simulation.....\n");
	while (1)
	{
	}
	return (0);
}



//Things left
//1. Memory free
//2. Sprite bug
//3. Keys linux mac
//4. Norminiette
//5. Clean Exit
//6. map opening when sprites