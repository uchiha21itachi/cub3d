#include "../includes/cub3d.h"

void		copy_1(t_parse *p_data, int **temp_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
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
}

void		copy_2(t_parse *p_data, int **temp_map)
{
	int		i;
	int		j;

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
}

void		update_s(t_parse *p_data)
{
	int i;

	i = -1;
	while (++i < p_data->map_y)
		free(p_data->map[i]);
	free(p_data->map);
	if (!(p_data->map = (int **)malloc(sizeof(int *) *
		(p_data->map_y + 1))))
		malloc_error_messege('m', p_data);
	i = 0;
	while (i < p_data->map_y)
	{
		if (!(p_data->map[i] = (int *)malloc(sizeof(int) * p_data->map_x[i])))
			malloc_error_messege('m', p_data);
		i++;
	}
}

void		update_map_size(t_parse *p_data)
{
	int		**temp_map;
	int		i;
	int		j;

	i = 0;
	if (!(temp_map = (int **)malloc(sizeof(int *) * p_data->map_y)))
		malloc_error_messege('m', p_data);
	while (i < p_data->map_y)
	{
		if (!(temp_map[i] = (int *)malloc(sizeof(int) * p_data->map_x[i])))
			malloc_error_messege('m', p_data);
		i++;
	}
	copy_1(p_data, temp_map);
	update_s(p_data);
	copy_2(p_data, temp_map);
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
