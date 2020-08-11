#include "cub3d.h"

void		init_map(t_parse *p_data)
{
	if (p_data->temp_counter == 0)
	{
		if (!(p_data->map = (int**)malloc(1 * sizeof(int *))))
			malloc_error_messege('m', p_data);
		if (!(p_data->map_x = (int*)malloc(1 * sizeof(int))))
			malloc_error_messege('m', p_data);
	}
	// // else
	// // {
	// if (!(p_data->map = (int**)malloc((p_data->temp_counter) * sizeof(int *))))
	// 	malloc_error_messege('m', p_data);
	// if (!(p_data->map_x = (int*)malloc((p_data->temp_counter ) * sizeof(int))))
	// 	malloc_error_messege('m', p_data);
	// // }
	
}
	
void		update_map_size(t_parse *p_data)
{
	int		*temp_mapX;
	int		i;

	if (!(temp_mapX = (int*)malloc((p_data->temp_counter) * sizeof(int))))
		malloc_error_messege('m', p_data);
	i = 0;

	while (i < p_data->temp_counter - 1)
	{
		temp_mapX[i] = p_data->map_x[i];
		i++;
	}
	free(p_data->map_x);
	if (!(p_data->map_x = (int*)malloc((p_data->temp_counter) * sizeof(int))))
		malloc_error_messege('m', p_data);
	i = 0;
	while (i < p_data->temp_counter - 1)
	{
		p_data->map_x[i] = temp_mapX[i];
		i++;
	}
}

void		fill_map(char *line, t_parse *p_data)
{
    // printf("temp counter is - %d \n", p_data->temp_counter);
	p_data->map_x[p_data->temp_counter] = (int)ft_strlen(line);
}

void		parse_map(char *line, t_parse *p_data)
{
	if (p_data->temp_counter == 0)
		init_map(p_data);
	else
		update_map_size(p_data);
	fill_map(line, p_data);

	p_data->temp_counter++;
}