#include "cub3d.h"

t_parse		*parse_data_init(t_parse *p_data)
{
	p_data->res_x = 0;
	p_data->res_y = 0;
	p_data->map_x = 0;
	return (p_data);
}


t_parse		*parse_map(char *line, t_parse *p_data, int spaces)
{
	printf("x - %d\n", p_data->map_x);
	
	//need to malloc the map
	//need to know exact number of Y in order to do it
	//map_x and map_y are to malloc the map exactly as it is
	
	
	while (spaces-- > 0)
		printf("*");
	printf ("%s\n", line);
	p_data->map_x += 1;
	return (p_data);
}