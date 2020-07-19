#include "cub3d.h"

int			array_line_spaces(int *arr, int length)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (i < length)
	{
		if (ft_isspace(arr[i]))
			counter++;
		i++;
	}
	return (counter);
}

int			check_flush_condition(int x, int y, t_parse *p_data)
{
	if ( x > p_data->len_arr[y])
		return (0);
	if (y > p_data->map_y)
		return (0);
	return (1);
}

void		flush_map(int x, int y, t_parse	*p_data)
{
	if (check_flush_condition(x, y, p_data))
	{
		printf ("x - [%d] y - [%d]\n",x, y);
		flush_map(x+1, y, p_data);
		flush_map(x-1, y, p_data);
		flush_map(x, y+1, p_data);
		flush_map(x, y-1, p_data);
	}
}

t_parse		*check_map(t_parse *p_data)
{

	// print_map(p_data);
	flush_map(p_data->temp_player->posX, p_data->temp_player->posY, p_data);
	return(p_data);
}