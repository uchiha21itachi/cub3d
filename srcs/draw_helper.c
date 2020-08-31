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

	if (x >= g->p_data->res_x || y >= g->p_data->res_y)
		return ;
	index = x * 4 + (y * g->img->line_length);
	i = -1;
	while (++i < 4)
		g->img->addr[index + i] = c[i];
}

int		move_player(int keycode, t_game *g_data)
{
	if (g_data->posY > g_data->p_data->map_y)
		return (keycode);
	if (g_data->posX > g_data->p_data->map_x[(int)g_data->posY])
		return (keycode);
	if (keycode == KEY_W)
		move_up(g_data);
	if (keycode == KEY_S)
		move_down(g_data);
	if (keycode == KEY_D)
		move_right(g_data);
	if (keycode == KEY_A)
		move_left(g_data);
	if (keycode == KEY_RIGHT)
		rotate_right(g_data);
	if (keycode == KEY_LEFT)
		rotate_left(g_data);
	if (keycode == KEY_ESC)
		mlx_destroy_window(g_data->mlx->mlx, g_data->mlx->mlx_win);
	return (keycode);
}

int		close_window(int keycode, t_game *g_data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(g_data->mlx->mlx, g_data->mlx->mlx_win);
	}
	return (keycode);
}