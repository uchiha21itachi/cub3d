#include "cub3d.h"

void    get_resolution(char *line, t_parse *p_data)
{
	if (p_data->res_x != -1 || p_data->res_y != -1)
		parsing_error_messege('d', p_data);
	if (check_r_line(line) == 0)
		parsing_error_messege('r', p_data);
	while (*line++ && (p_data->res_y == -1 || p_data->res_x == -1))
	{
		line = remove_space_digit(line, 's');
		p_data->res_x = get_min(ft_atoi(line), 2560);
		line = remove_space_digit(line, 'd');
		p_data->res_y = get_min(ft_atoi(line), 1440);
	}
	if (p_data->res_x == -1 || p_data->res_y == -1)
		parsing_error_messege('r', p_data);
}

void	get_fc_color(char *line, t_parse *p_data)
{
	int 	r;
	int		g;
	int		b;
	char	c;

	if (check_color_line(line) == 0 || check_color_order(line) == 0)
		parsing_error_messege('c', p_data);	
	c = *line;
	line++;
	line = remove_space_digit(line, 's');
	r = ft_atoi(line);
	line = remove_space_digit(line, 'd');
	line = remove_space_digit(line, 's');
	line++;
	line = remove_space_digit(line, 's');
	g = ft_atoi(line);
	line = remove_space_digit(line, 'd');
	line = remove_space_digit(line, 's');
	line++;
	line = remove_space_digit(line, 's');
	b = ft_atoi(line);
	if (c == 'F')
		p_data->floor_color = create_trgb(0,r,g,b);
	else if (c == 'C')
		p_data->ceiling_color = create_trgb(0,r,g,b);
}