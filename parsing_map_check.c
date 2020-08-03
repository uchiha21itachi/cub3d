#include "cub3d.h"

t_parse		*fill_temp_map(t_parse *p_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p_data->map_y)
	{
		while (j < p_data->len_arr[i])
		{
			p_data->temp_map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return(p_data);
}


t_parse		*get_temp_map(t_parse *p_data)
{
	int i;

	i = 0;
	p_data->temp_map = (int **)malloc(sizeof(int *) * p_data->map_y);
	if (p_data->temp_map == NULL)
		printf("error in malloc in temp map\n");
	while (i < p_data->map_y)
	{
		p_data->temp_map[i] = (int *)malloc(sizeof(int) * p_data->len_arr[i]);
		if (p_data->temp_map[i] == NULL)
			printf("error in malloc in temp map\n");
		i++;
	}
	p_data = fill_temp_map(p_data);
	return (p_data);
}


int		check_right(int x, int y, t_parse *p_data)
{
	if (y+1 < p_data->len_arr[x])
	{
		if (p_data->map[x][y+1] == 9)
			return (0);
	}
	else
		return (0);
	return (1);
}


int		check_left(int x, int y, t_parse *p_data)
{
	if (y-1 >= 0)
	{
		if (p_data->map[x][y-1] == 9)
			return (0);
	}
	else
		return (0);
	return (1);
}

int		check_down(int x, int y, t_parse *p_data)
{
	if (x+1 < p_data->map_y && y < p_data->len_arr[x+1])
	{
		if (p_data->map[x+1][y] == 9)
			return (0);
	}
	else
		return (0);
	return (1);
}

int		check_up(int x, int y, t_parse *p_data)
{
	if (x-1 >= 0 && y < p_data->len_arr[x-1])
	{
		if (p_data->map[x-1][y] == 9)
			return (0);
	}
	else
		return (0);
	return (1);
}


int		check_diagonal_upl(int x, int y, t_parse *p_data)
{
	if (x-1 >= 0 && y-1 >= 0 && y-1 < p_data->len_arr[x-1])
	{
		if (p_data->map[x-1][y-1] == 9)
			return (0);
	}
	else
		return (0);
	return (1);
}

int		check_diagonal_upr(int x, int y, t_parse *p_data)
{
	if (x-1 >= 0  && y+1 < p_data->len_arr[x-1])
	{
		if (p_data->map[x-1][y+1] == 9)
			return (0);		
	}
	else
		return (0);
	return (1);
}

int		check_diagonal_downr(int x, int y, t_parse *p_data)
{
	if (x+1 < p_data->map_y  && y+1 < p_data->len_arr[x+1])
	{
		if (p_data->map[x+1][y+1] == 9)
			return (0);		
	}
	else
		return (0);
	return (1);
}

int		check_diagonal_downl(int x, int y, t_parse *p_data)
{
	if (x+1 < p_data->map_y  && y-1 >= 0 && y-1 < p_data->len_arr[x+1])
	{
		if (p_data->map[x+1][y-1] == 9)
			return (0);		
	}
	else
		return (0);
	return (1);
}

t_parse			*check_position(int x, int y, t_parse *p_data)
{
	int i;

	i = 1;
	if (p_data->map[x][y] == 0)
	{
		if ((i = check_up(x, y, p_data)) == 0)
		{
			printf("inside the check function check up - x y [%d] [%d]\n",x ,y);
			p_data->map_check_ret = 0;
			return (p_data);
		}
		if ((i = check_down(x, y, p_data)) == 0)
		{
			printf("inside the check function check down x y [%d] [%d]\n",x ,y);
			p_data->map_check_ret = 0;
			return (p_data);
		}
		if ((i = check_left(x, y, p_data)) == 0)
		{
			printf("inside the check function check left x y [%d] [%d]\n",x ,y);
			p_data->map_check_ret = 0;
		 	return (p_data);
		}
		if ((i = check_right(x, y, p_data)) == 0)
		{
			printf("inside the check function check right x y [%d] [%d]\n",x ,y);
			p_data->map_check_ret = 0;
			return (p_data);
		}
		if ((i = check_diagonal_upl(x, y, p_data)) == 0)
		{
			printf("inside the check function diag up left x y [%d] [%d]\n",x ,y);
			p_data->map_check_ret = 0;
			return (p_data);
		}
		if ((i = check_diagonal_upr(x, y, p_data)) == 0)
		{
			printf("inside the check function diag up right x y [%d] [%d]\n",x ,y);
			p_data->map_check_ret = 0;
			return (p_data);
		}
		if ((i = check_diagonal_downr(x, y, p_data)) == 0)
		{
			printf("inside the check function diag down right x y [%d] [%d]\n",x ,y);
			p_data->map_check_ret = 0;
			return (p_data);
		}
		if ((i = check_diagonal_downl(x, y, p_data)) == 0)
		{
			printf("inside the check function diag down left x y [%d] [%d]\n",x ,y);
			p_data->map_check_ret = 0;
			return (p_data);
		}
	}
	return (p_data);
}


t_parse		*flood_fill(int x, int y, t_parse *p_data)
{
	if (x >= 0 && x < p_data->map_y && y >= 0 && y < p_data->len_arr[x])
	{
		if (p_data->temp_map[x][y] == 0)
		{
			p_data = check_position(x, y, p_data);
			p_data->temp_map[x][y] = 1;
			flood_fill(x+1, y, p_data);
			flood_fill(x-1, y, p_data);
			flood_fill(x, y+1, p_data);
			flood_fill(x, y-1, p_data);
		}
	}
	return (p_data);
}

t_parse		*check_map(t_parse *p_data)
{
	print_map(p_data);
	p_data = get_temp_map(p_data);
	printf("player starting position id [%d] [%d]\n", p_data->temp_player->posX, p_data->temp_player->posY);
	p_data = flood_fill(p_data->temp_player->posX, p_data->temp_player->posY, p_data);
	if (p_data->map_check_ret == 0)
		printf("ERRORR WRONG MAP\n\n");
	free_temp_map(p_data);
	return(p_data);
}


