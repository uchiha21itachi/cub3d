#include "cub3d.h"


void	parsing_error_messege(char c)
{
	if (c == 'i')
	{
		printf ("Error - Invalid entry in map file \n");
	}	
}


void	print_parse_data(t_parse p_data)
{
	printf ("Resolution X - %d\n", p_data.res_x);
	printf ("Resolution Y - %d\n", p_data.res_y);
	// printf ("path North = %s\n", p_data.no_path);
	// printf ("path South = %s\n", p_data.so_path);
	// printf ("path West = %s\n", p_data.we_path);
	// printf ("path East = %s\n", p_data.ea_path);
	// printf ("path Sprite = %s\n", p_data.s_path);
}