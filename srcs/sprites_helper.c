#include "../includes/cub3d.h"

void	sort(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < g->p_data->sprite_size - 1)
	{
		while (j < g->p_data->sprite_size - i - 1)
		{
			if (g->sp_r->s_first[j] > g->sp_r->s_first[j + 1])
			{
				g->sp_r->tempx = g->sp_r->s_first[j];
				g->sp_r->s_first[j] = g->sp_r->s_first[j + 1];
				g->sp_r->s_first[j + 1] = g->sp_r->tempx;
				g->sp_r->tempy = g->sp_r->s_second[j];
				g->sp_r->s_second[j] = g->sp_r->s_second[j + 1];
				g->sp_r->s_second[j + 1] = g->sp_r->tempy;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	sortsprites(t_game *g)
{
	int		i;
	int		j;

	if (!(g->sp_r->s_first = (double *)malloc(g->p_data->sprite_size *
		(sizeof(double)))))
		malloc_error_messege('m', g->p_data);
	if (!(g->sp_r->s_second = (double *)malloc(g->p_data->sprite_size *
		(sizeof(double)))))
		malloc_error_messege('m', g->p_data);
	i = 0;
	while (i < g->p_data->sprite_size)
	{
		g->sp_r->s_first[i] = g->sp_r->dist[i];
		g->sp_r->s_second[i] = g->sp_r->order[i];
		i++;
	}
	sort(g);
	i = 0;
	while (i < g->p_data->sprite_size)
	{
		g->sp_r->dist[i] = g->sp_r->s_first[g->p_data->sprite_size - i - 1];
		g->sp_r->order[i] = g->sp_r->s_second[g->p_data->sprite_size - i - 1];
		i++;
	}
	i = 0;
	// while (i < g->p_data->sprite_size)
	// {
		// printf("order[%d] - [%d]\n", i, g->sp_r->order[i]);
		// printf("dist[%d] - [%f]\n", i, g->sp_r->dist[i]);
		// i++;
	// }
	// printf("\n");
	free(g->sp_r->s_first);
	free(g->sp_r->s_second);
}

int		fill(t_parse *p, int y, int x, int i)
{
	if (p->map[y][x] == 2)
	{
		if (i < p->sprite_size)
		{
			p->sprites[i].texture = p->textures[4];
			p->sprites[i].posX = x + 0.5;
			p->sprites[i].posY = y + 0.5;
			i++;
		}
	}
	return (i);
}

void	fill_sprites_data(t_parse *p_data)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	if (!(p_data->sprites = (t_sprite *)malloc(sizeof(t_sprite) *
		p_data->sprite_size)))
		malloc_error_messege('m', p_data);
	while (y < p_data->map_y)
	{
		while (x < p_data->map_x[y])
		{
			i = fill(p_data, y, x, i);
			x++;
		}
		x = 0;
		y++;
	}
}
