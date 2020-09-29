#include "../includes/cub3d.h"

void	set_pos_north(t_game *g_data)
{
	g_data->dirx = -1;
	g_data->diry = 0;
	g_data->planex = 0;
	g_data->planey = 0.66;
}

void	set_pos_south(t_game *g_data)
{
	g_data->dirx = 1;
	g_data->diry = 0;
	g_data->planex = 0;
	g_data->planey = -0.66;
}

void	set_pos_west(t_game *g_data)
{
	g_data->dirx = 0;
	g_data->diry = 1;
	g_data->planex = 0.66;
	g_data->planey = 0;
}

void	set_pos_east(t_game *g_data)
{
	g_data->dirx = 0;
	g_data->diry = -1;
	g_data->planex = -0.66;
	g_data->planey = 0;
}
