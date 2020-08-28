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


void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}


// void	init_screenshot_data(t_screen *s_win, t_game *g_data)
// {
// 	s_win->width = g_data->p_data->res_x;
// 	s_win->height = g_data->p_data->res_y;
// 	s_win->title = ft_strdup("cub3d Screenshot");
// 	s_win->mlx_ptr = g_data->mlx->mlx;
// 	s_win->win_ptr = NULL;
// }


// int		get_pixel(t_game *g, int x, int y, int result)
// {
// 	int index;
// 	int i;

// 	if (x >= g->p_data->res_x || y >= g->p_data->res_y)
// 		return (0);
// 	if (x < 0 || y < 0)
// 		return (0);
// 	index = (x + y * g->p_data->res_x) * 4;
// 	result = (int)g->img->addr[index + i];
// 	// printf ("result - [%d]\n", result);
// 	return(result);
// }


int		get_pixel(t_game *g_data, unsigned int x, unsigned int y, t_screen *s_win)
{
	int	ptr;

	ptr = *(int*)(g_data->img->addr
			+ (4 * (int)g_data->p_data->res_x * ((int)g_data->p_data->res_x - 1 - y))
			+ (4 * x));
	return ((ptr & 0xFF0000) | (ptr & 0x00FF00) | (ptr & 0x0000FF));
}

static void	bmp_pixels(t_game *game,  int fd, int pad, t_screen *s_win)
{
	unsigned char	zero[3];
	unsigned int	i;
	unsigned int	j;
	int				color;

	i = -1;
	while (++i < 3)
		zero[i] = 0;
	i = 0;
	while (i < game->p_data->res_y)
	{
		j = 0;
		while (j < game->p_data->res_x)
		{
			color = get_pixel(game, j, i, s_win);
			write(fd, &color, 3);
			write(fd, &zero, pad);
			j++;
		}
		i++;
	}
}

static void	bmp_header(t_game *game, int fd, int filesize)
{
	int						i;
	unsigned char			data[54];
	int						temp;

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
}

void			screenshot(t_game *game, t_screen *s_win)
{
	int			fd;
	int			filesize;
	int			pad;

	pad = (4 - (game->p_data->res_x * 3) % 4) % 4;
	filesize = 54 + (3 * (game->p_data->res_x + pad) * game->p_data->res_y);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT |
					O_TRUNC | O_APPEND, 0666)) < 0)
		return ;
	bmp_header(game, fd, filesize);
	bmp_pixels(game, fd, pad, s_win);
	close(fd);
	// return (1);
}

void	take_screenshot(t_game *g_data)
{
	t_screen 	*s_win;
	int			config[3];

	printf("Taking Screenshot starts...\n");

	if (!(s_win = (t_screen *)malloc(sizeof(t_screen) * 1)))
		malloc_error_messege('m', g_data->p_data);
	// init_screenshot_data(s_win, g_data);

	config[0] = 32;
	config[1] = g_data->p_data->res_x * 4;
	config[2] = 0;
	s_win->width = g_data->p_data->res_x;
	s_win->height = g_data->p_data->res_y;
	s_win->title = ft_strdup("cub3d Screenshot");
	s_win->mlx_ptr = g_data->mlx->mlx;
	s_win->win_ptr = NULL;
	s_win->surface = mlx_new_image(s_win->mlx_ptr, s_win->width, s_win->height);
	s_win->data = mlx_get_data_addr(s_win->surface, &config[0], &config[1], &config[2]);
	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);
	
	screenshot(g_data, s_win);
	printf("exiting the function take screenshot\n");
}
