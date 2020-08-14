#include "../includes/cub3d.h"

void		check_init_values(t_parse *p_data)
{
	if (p_data->res_x == -1 || p_data->res_y == -1)
		value_miss_error('r', p_data);
	if (p_data->floor_color == -1 || p_data->ceiling_color == -1)
		value_miss_error('c', p_data);
	if (p_data->map_start == -1)
		value_miss_error('m', p_data);
	if (p_data->temp_posX == -1 || p_data->temp_posY == -1 || p_data->orient == 32)
		value_miss_error('p', p_data);

}

void		check_lr(int x, int y, t_parse *p_data)
{
	if (x+1 < p_data->map_x[y] && y < p_data->map_y)
	{
		if (p_data->map[y][x+1] == 3)
			check_map_error('r', p_data, x, y);
	}
	else
		check_map_error('r', p_data, x, y);
	if (x-1 >= 0 && y < p_data->map_y)
	{
		if (p_data->map[y][x-1] == 3)
			check_map_error('l', p_data, x, y);
	}
	else
		check_map_error('l', p_data, x, y);
}

void		check_ud(int x, int y, t_parse *p_data)
{

	if (y+1 < p_data->map_y)
	{
		if (p_data->map[y+1][x] == 3)
			check_map_error('d', p_data, x, y);
	}
	else
		check_map_error('d', p_data, x, y);
	if (y - 1 >= 0)
	{
		if (p_data->map[y-1][x] == 3)
			check_map_error('u', p_data, x, y);
	}
	else
		check_map_error('u', p_data, x, y);
}

void		check_map(t_parse *p_data)
{
	int x;
	int y;
	
	x = 0;
	y = 0;

	while (y < p_data->map_y)
	{
		while (x < p_data->map_x[y])
		{
			if (p_data->map[y][x] == 0)
			{
				check_lr(x, y, p_data);
				check_ud(x, y, p_data);
			}
			x++;
		}
		x = 0;
		y++;
	}
	check_init_values(p_data);
}