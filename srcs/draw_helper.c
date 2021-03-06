/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:41 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:43 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	get_pixel_color(t_texture *texture, int x, int y, unsigned char *result)
{
	int index;
	int i;

	if (x >= texture->width || y >= texture->height)
		return ;
	if (x < 0 || y < 0)
		return ;
	index = (x + y * texture->width) * 4;
	i = -1;
	while (++i < 4)
		result[i] = (int)texture->data[index + i];
}

void	draw_pix(t_game *g, unsigned int x, unsigned int y, unsigned char c[4])
{
	int index;
	int	i;

	if ((int)x >= g->p_data->res_x || (int)y >= g->p_data->res_y)
		return ;
	index = x * 4 + (y * g->img->line_length);
	i = -1;
	while (++i < 4)
		g->img->addr[index + i] = c[i];
}
