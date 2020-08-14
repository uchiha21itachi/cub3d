#include "../includes/cub3d.h"

void		update_map_size(t_parse *p_data)
{
	int		**temp_map;
	int		i;

	i = 0;
	
	//create temp map of correct size
	if (!(temp_map = (int **)malloc(sizeof(int *) * p_data->map_y)))
		malloc_error_messege('m', p_data);
	while (i < p_data->map_y)
	{
		if(!(temp_map[i] = (int *)malloc(sizeof(int) * p_data->map_x[i])))
			malloc_error_messege('m', p_data);
		i++;
	}

	//copy content of map to temp map
	int j;
	j = 0;
	i = 0;
	while (i < p_data->map_y)
	{
		while (j < p_data->map_x[i])
		{
			temp_map[i][j] = p_data->map[i][j];
			j++;
		}
		j = 0;
		i++;
	}

	// free map
	i = -1;
	while (++i < p_data->map_y)
		free(p_data->map[i]);
	free(p_data->map);

	//create map with new size
	i = 0;
	if (!(p_data->map = (int **)malloc(sizeof(int *) * (p_data->map_y + 1))))
		malloc_error_messege('m', p_data);
	while (i < p_data->map_y)
	{
		if(!(p_data->map[i] = (int *)malloc(sizeof(int) * p_data->map_x[i])))
			malloc_error_messege('m', p_data);
		i++;
	}

	//copy the content back
	j = 0;
	i = 0;
	while (i < p_data->map_y)
	{
		while (j < p_data->map_x[i])
		{
			p_data->map[i][j] = temp_map[i][j];
			j++;
		}
		j = 0;
		i++;
	}

	//free temp map
	i = -1;
	while (++i < p_data->map_y)
		free(temp_map[i]);
	free(temp_map);
}



void		update_mapx_size(t_parse *p_data)
{
	int		*temp_mapx;
	int		i;

	i = 0;
	if (!(temp_mapx = (int*)malloc((p_data->map_y) * sizeof(int))))
		malloc_error_messege('m', p_data);
	while (i < p_data->map_y)
	{
		temp_mapx[i] = p_data->map_x[i];
		i++;
	}
	free(p_data->map_x);
	if (!(p_data->map_x = (int*)malloc((p_data->map_y + 1) * sizeof(int))))
		malloc_error_messege('m', p_data);
	i = 0;
	while (i < p_data->map_y)
	{
		p_data->map_x[i] = temp_mapx[i];
		i++;
	}
	free(temp_mapx);
}


void	grab_position(t_parse *p_data, char c, int y)
{
	if (p_data->temp_posX != -1 || p_data->temp_posY != -1 ||
		p_data->orient != 32)
	{
		parsing_error_messege('p', p_data);
		return;
	}
	p_data->temp_posX = y;
	p_data->temp_posY = p_data->map_y;
	p_data->orient = c;
	p_data->map[p_data->map_y][y] = 0;
}