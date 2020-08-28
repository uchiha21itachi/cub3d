#include "../includes/cub3d.h"

void	set_pos_north(t_game *g_data)
{
	g_data->dirX = -1;
	g_data->dirY = 0;
	g_data->planeX = 0;
	g_data->planeY = 0.66;
}

void	set_pos_south(t_game *g_data)
{
	g_data->dirX = 1;
	g_data->dirY = 0;
	g_data->planeX = 0;
	g_data->planeY = -0.66;
}

void	set_pos_west(t_game *g_data)
{
	g_data->dirX = 0;
	g_data->dirY = 1;
	g_data->planeX = 0.66;
	g_data->planeY = 0;
}

void	set_pos_east(t_game *g_data)
{
	g_data->dirX = 0;
	g_data->dirY = -1;
	g_data->planeX = -0.66;
	g_data->planeY = 0;
}
