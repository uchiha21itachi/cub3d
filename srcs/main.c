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

// void	test()
// {
// 	void	*mlx;
// 	int		height;
// 	int		width;
// 	void	*ret_ptr;
// 	char 	*file;

// 	if ((mlx = mlx_init()) == NULL)
// 		printf("error in initializing the mlx init\n");
// 	file = ft_strdup("./pics/wall.xpm");
// 	printf("path - [%s]\n", file);
// 	ret_ptr = mlx_xpm_file_to_image(mlx, file, &width, &height);
// 	if (ret_ptr == NULL)
// 		printf("Null pointer babes\n");
// 	printf("height -%d width - %d\n", width, height);
// }


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
	printf("testint===========\n");
	printf("Exiting the simulation.....\n");
	while (1)
	{
	}
	return (0);
}




//check is position should be x y or y x