#include "cub3d.h"

int			*init_len_arr(t_parse *p_data)
{
	int		*len_arr;

	if (!(len_arr = (int *)malloc(sizeof(int) * p_data->map_y)))
	{
		printf("error in malloc parsing the length array");
		exit(0);
	}
	return(len_arr);
}

t_parse		*fill_map_array(t_parse *p_data, char *line)
{
	int counter;

	counter = 0;
	while (counter < p_data->len_arr[p_data->temp_counter])
	{
		if (line[counter] == 32)
			p_data->map[p_data->temp_counter][counter] = -1;
		else
			p_data->map[p_data->temp_counter][counter] = line[counter] - 48;
		counter++;
	}
	return(p_data);
}

t_parse		*parse_map(char *line, t_parse *p_data)
{
	if (p_data->temp_counter == 0)
	{	
		p_data->len_arr = init_len_arr(p_data);
		p_data->map = (int **)malloc(sizeof(int) * p_data->map_y);
		if (p_data->map == NULL)
			printf("error in malloc\n");
	}
	p_data->len_arr[p_data->temp_counter] = ft_strlen(line);
	p_data->map[p_data->temp_counter] = (int *)malloc(sizeof(int) * p_data->len_arr[p_data->temp_counter]);
	if (p_data->map[p_data->temp_counter] == NULL)
			printf("error in malloc\n");
	p_data = fill_map_array(p_data, line);
	p_data->temp_counter++;
	return (p_data);
}