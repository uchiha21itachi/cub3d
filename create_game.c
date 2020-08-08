/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:43:00 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/05 22:43:02 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		verLine(int x, t_draw *draw, t_mlx mlx, t_img img, int color)
{
	int i;

	i = draw->drawStart;

	while (i < draw->drawEnd )
	{
		my_mlx_pixel_put(&img, x, i, color);
		i++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
}

void		create_game(t_parse *p_data)
{
	t_mlx	mlx;
	t_img	img;

	if ((mlx.mlx = mlx_init()) == NULL)
		printf("error in initializing the mlx init\n");
	mlx.mlx_win = mlx_new_window(mlx.mlx, 640, 480, "cub3d");
	if ((img.img = mlx_new_image(mlx.mlx, 640, 480)) == NULL)
		printf("error in creating a new image\n");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	game(p_data, mlx, img);
	mlx_loop(mlx.mlx);
}

