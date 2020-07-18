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

t_parse		*check_map(t_parse *p_data)
{
	int i;

	i = 0;

	while (i < p_data->map_y)
	{
		printf("line number - %d\n", i);
		printf("  line - %d\n", p_data->len_arr[i]);
		printf("spaces - %d\n",array_line_spaces(p_data->map[i], p_data->len_arr[i]));
		i++;
	}
	return(p_data);
}