#include "cub3d.h"

void    get_resolution(char *line, t_parse *p_data)
{
	if (check_r_line(line) == 0)
    {
		p_data->map_error = 1;
		parsing_error_messege('r', p_data);
    }
	while (*line++ && (p_data->res_y == -1 || p_data->res_x == -1))
	{
		line = remove_space_digit(line, 's');
		p_data->res_x = get_min(ft_atoi(line), 2560);
		line = remove_space_digit(line, 'd');
		p_data->res_y = get_min(ft_atoi(line), 1440);
	}
	if (p_data->res_x == -1 || p_data->res_y == -1)
	{
		p_data->map_error = 1;
		parsing_error_messege('r', p_data);
	}
}
