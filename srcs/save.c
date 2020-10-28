/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:47 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:49 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

int			get_pixel(t_game *g_data, unsigned int x, unsigned int y)
{
	int				ptr;

	ptr = *(int*)(g_data->img->addr +
	(4 * g_data->p_data->res_x *
	(g_data->p_data->res_y - 1 - y)) +
	(4 * x));
	return ((ptr & 0xFF0000) | (ptr & 0x00FF00) | (ptr & 0x0000FF));
}

static void	bmp_pixels(t_game *game, int fd, int pad)
{
	unsigned char	zero[3];
	int				i;
	int				j;
	int				color;
	int				temp;

	i = -1;
	while (++i < 3)
		zero[i] = 0;
	i = 0;
	while (i < game->p_data->res_y)
	{
		j = 0;
		while (j < game->p_data->res_x)
		{
			color = get_pixel(game, j, i);
			temp = write(fd, &color, 3);
			temp = write(fd, &zero, pad);
			j++;
		}
		i++;
	}
	(void)temp;
}

static void	bmp_header(t_game *game, int fd, int filesize)
{
	int				i;
	unsigned char	data[54];
	int				temp;

	i = -1;
	while (++i < 54)
		data[i] = 0;
	data[0] = (unsigned char)('B');
	data[1] = (unsigned char)('M');
	int_to_char(filesize, data + 2);
	data[10] = (unsigned char)(54);
	data[14] = (unsigned char)(40);
	int_to_char(game->p_data->res_x, data + 18);
	int_to_char(game->p_data->res_y, data + 22);
	data[26] = (unsigned char)(1);
	data[28] = (unsigned char)(24);
	temp = write(fd, data, 54);
	(void)temp;
}

void		take_screenshot(t_game *g_data)
{
	int				fd;
	int				filesize;
	int				pad;

	ft_putstr("Taking Screenshot starts...\n");
	pad = (4 - (g_data->p_data->res_x * 3) % 4) % 4;
	filesize = 54 + (3 * (g_data->p_data->res_x + pad) * g_data->p_data->res_y);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT |
					O_TRUNC | O_APPEND, 0666)) < 0)
		return ;
	bmp_header(g_data, fd, filesize);
	bmp_pixels(g_data, fd, pad);
	close(fd);
	ft_putstr("exiting the function take screenshot\n");
}
