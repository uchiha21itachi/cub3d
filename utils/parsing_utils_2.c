#include "../includes/cub3d.h"

void	grab_position(t_parse *p_data, char c, int y)
{
	if (p_data->temp_posX != -1 || p_data->temp_posY != -1 ||
		p_data->orient != 32)
	{
		parsing_error_messege('p', p_data);
		return ;
	}
	p_data->temp_posX = y;
	p_data->temp_posY = p_data->map_y;
	p_data->orient = c;
	p_data->map[p_data->map_y][y] = 0;
}

void	set_player_dir(t_game *g_data, t_parse *p_data)
{
	if (p_data->orient == 'N')
		set_pos_north(g_data);
	else if (p_data->orient == 'S')
		set_pos_south(g_data);
	else if (p_data->orient == 'E')
		set_pos_east(g_data);
	else if (p_data->orient == 'W')
		set_pos_west(g_data);
}
