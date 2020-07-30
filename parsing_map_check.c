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

void		flood_fill(int x, int y, t_parse *p_data)
{
	//up and down working but not for the corners
	//right working but not for spaces in start or end
	if (x >= 0 && x < p_data->map_y && y >= 0 && y < p_data->len_arr[x])
	{
	
		if (p_data->map[x][y] == 0)
		{
			//upper
			if (x - 1 >= 0 && y <= p_data->len_arr[x - 1] - 1)
			{
				if (p_data->map[x-1][y] == 9)
				{
					printf ("wrong map (up1)\n");
					printf ("x - [%d] y - [%d] len - [%d]\n", x, y, p_data->len_arr[x-1]);
				}
			}
			else
			{
				printf ("wrong map (up2)\n");
				printf ("x - [%d] y - [%d] len - [%d]\n", x, y, p_data->len_arr[x-1]);
			}

			//down
			if (x+1 < p_data->map_y && y <= p_data->len_arr[x+1] - 1)
			{
				if (p_data->map[x+1][y] == 9)
				{
					printf ("wrong map (down1)\n");
					printf ("x - [%d] y - [%d] len - [%d]\n", x, y, p_data->len_arr[x-1]);
				}
			}
			else
			{
				printf ("wrong map (down2)\n");
				printf ("x - [%d] y - [%d] len - [%d]\n", x, y, p_data->len_arr[x+1]);
			}

			//right
			if (p_data->map[x][0] != 1 || p_data->map[x][p_data->len_arr[x] - 1] != 1)
			{
				printf ("wrong map (left right2)\n");
				printf ("x - [%d] y - [%d] len - [%d]\n", x, y, p_data->len_arr[x+1]);
			}

		}
		// && p_data->map[x][y] != 1
		if (p_data->temp_map[x][y] == 0 )
		{
			p_data->temp_map[x][y] = 1;
			flood_fill(x+1, y, p_data);
			flood_fill(x-1, y, p_data);
			flood_fill(x, y+1, p_data);
			flood_fill(x, y-1, p_data);
		}
	}
}

t_parse		*check_map(t_parse *p_data)
{

	print_map(p_data);
	printf ("\n\n");
	p_data = get_temp_map(p_data);
	// print_temp_map(p_data);
	printf ("\n\n");
	printf ("\n\n");
	flood_fill(p_data->temp_player->posX, p_data->temp_player->posY, p_data);
	print_temp_map(p_data);
	
	return(p_data);
}





















// int			array_line_spaces(int *arr, int length)
// {
// 	int i;
// 	int counter;

// 	i = 0;
// 	counter = 0;
// 	while (i < length)
// 	{
// 		if (ft_isspace(arr[i]))
// 			counter++;
// 		i++;
// 	}
// 	return (counter);
// }



// int			check_down(int x, int y, t_parse *p_data)
// {
// 	int ret;

// 	ret = -1;
// 	if (x <= p_data->map_y && y <= p_data->len_arr[x])
// 	{
// 		// printf("x or y going outside parsed map\n");
// 		// printf("x - [%d] map x -[%d] \n", x, p_data->map_x);
// 		// printf("y - [%d] map y -[%d] \n", x, p_data->len_arr[x]);


// 		if (p_data->map[x][y] == 1)
// 		{
// 			printf("found One at x [%d] y [%d]\n",x, y);
// 			ret = 1;
// 		}
// 		else if (p_data->map[x][y] == 0)
// 		{
// 			printf("found Zero at x [%d] y [%d]\n",x, y);
// 			ret = 0;
// 		}
// 		else if (p_data->map[x][y] == 9)
// 		{
// 			printf("found space at x [%d] y [%d]\n",x, y);
// 			check_down(x+1, y, p_data);
// 		}
// 		else
// 		{
// 			printf("found something else not 1 0 or 9\n");
// 		}
// 	}
// 	printf ("ret after one cycle = %d\n", ret);
// 	return (ret);
// }

// void		check_upper_line(t_parse *p_data)
// {
// 	int i;
// 	int c;

// 	i = 0;
// 	printf("upper line length - %d\n", p_data->len_arr[0]);
// 	while (i < p_data->len_arr[0])
// 	{
// 		if (p_data->map[0][i] == 1)
// 		{
// 			i++;
// 		}
// 		else if (p_data->map[0][i] == 9)
// 		{
// 			c = check_down(0, i, p_data);
// 			printf("c - %d\n", c);
// 		}
// 		i++;
// 	}
// }