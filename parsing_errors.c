#include "cub3d.h"


void	parsing_error_messege(char c)
{
	if (c == 'i')
	{
		printf ("Error - Invalid entry in map file \n");
	}	
}


void	print_parse_data(t_parse *p_data)
{
	printf ("Resolution X - %d\n", p_data->res_x);
	printf ("Resolution Y - %d\n", p_data->res_y);
	printf ("Map size Y - %d\n", p_data->map_y);

	int i = 0;
	int j = 0;
	while(i < p_data->temp_counter)
	{
		while (j < p_data->len_arr[i])
		{
			printf(" [i] [j] => [%d] [%d] = %d\n", i, j, p_data->map[i][j]);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}

	// printf ("path North = %s\n", p_data.no_path);
	// printf ("path South = %s\n", p_data.so_path);
	// printf ("path West = %s\n", p_data.we_path);
	// printf ("path East = %s\n", p_data.ea_path);
	// printf ("path Sprite = %s\n", p_data.s_path);
}


void	print_map(t_parse *p_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (i < p_data->map_y)
	{
		while (j < p_data->len_arr[i])
		{
			if (p_data->map[i][j] == 9)
				printf("* ");
			else
				printf("%d ", p_data->map[i][j]);
			j++;
		}
		printf ("\n");
		j = 0;
		i++;
	}
}
