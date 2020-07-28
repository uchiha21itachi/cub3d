#include "cub3d.h"

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

int			check_down(int x, int y, t_parse *p_data)
{
	int ret;
	int line_one[p_data->len_arr[0]];

	ret = -1;
	if (x <= p_data->map_y && y <= p_data->len_arr[x])
	{
		// printf("x or y going outside parsed map\n");
		// printf("x - [%d] map x -[%d] \n", x, p_data->map_x);
		// printf("y - [%d] map y -[%d] \n", x, p_data->len_arr[x]);


		if (p_data->map[x][y] == 1)
		{
			printf("found One at x [%d] y [%d]\n",x, y);
			line_one[y] = 1;
			ret = 1;
		}
		else if (p_data->map[x][y] == 0)
		{
			printf("found Zero at x [%d] y [%d]\n",x, y);
			line_one[y] = 0;
			ret = 0;
		}
		else if (p_data->map[x][y] == 9)
		{
			printf("found space at x [%d] y [%d]\n",x, y);
			check_down(x+1, y, p_data);
		}
		else
		{
			printf("found something else not 1 0 or 9\n");
		}
	}
	printf ("ret after one cycle = %d\n", ret);
	return (ret);
}

void		check_upper_line(t_parse *p_data)
{
	int i;
	int c;

	i = 0;
	printf("upper line length - %d\n", p_data->len_arr[0]);
	while (i < p_data->len_arr[0])
	{
		if (p_data->map[0][i] == 1)
		{
			i++;
		}
		else if (p_data->map[0][i] == 9)
		{
			c = check_down(0, i, p_data);
			printf("c - %d\n", c);
		}
		i++;
	}
}

t_parse		*check_map(t_parse *p_data)
{
	print_map(p_data);
	printf ("\n\n");
	check_upper_line(p_data);
	return(p_data);
}