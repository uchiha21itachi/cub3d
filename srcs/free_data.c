#include "../includes/cub3d.h"

void	free_parse_data(t_parse *p_data)
{
	int i;

	i = 0;
	if (p_data->map_start >= 0)
	{
		while (i < p_data->map_y)
		{
			free(p_data->map[i]);
			i++;
		}
		free(p_data->map);
		free(p_data->map_x);
	}
	i = 0;
	while (i < 5)
	{
		free(p_data->textures[i]->filename);
		free(p_data->textures[i]);
		i++;
	}
	free(p_data->sprites);
	free(p_data);
}

void	free_game_mlx_data(t_game *g_data)
{
	free(g_data->d_data);
	free(g_data->mlx);
	free(g_data->img);
	free(g_data);
}
