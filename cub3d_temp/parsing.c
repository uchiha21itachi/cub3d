#include "cub3d.h"

void    parse_data_init(t_parse *p_data)
{
    p_data->res_x = -1;
	p_data->res_y = -1;
	p_data->floor_color = -1;
	p_data->ceiling_color = -1;
	p_data->map_x = -1;
	p_data->map_y = -1;
	p_data->temp_counter = 0;
	p_data->temp_posX = -1;
	p_data->temp_posY = -1;
	p_data->map_check_ret = 1;
	p_data->map_error = 0;
    p_data->parse_error = 0;
}

void    check_line(char *line, t_parse *p_data)
{
	int			i;
	char		*temp_line;

	// temp_line = ft_strdup(line);
	line = remove_space_digit(line, 's');
	if(*line == 'R')
        get_resolution(line, p_data);		
	else if (*line == 'F' || *line == 'C')
	{
		if ((*line == 'F' && p_data->floor_color != -1) ||
			(*line == 'C' && p_data->ceiling_color != -1))
			parsing_error_messege('d', p_data);
		else
			get_fc_color(line, p_data);
	}
	// else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		// p_data = get_tex_path(line, p_data);
	// else if (ft_isdigit(*line))
		// p_data = parse_map(temp_line, p_data);
	// else
		// printf ("Unexpected error occured in check line while parsing \n\n");	
	// free(temp_line);
}

void    parse(char **file)
{
    printf("parsing starts...\n");
 
    int		fd;
	char	*line;
	int 	ret;
	t_parse	*p_data;

	if ((fd = open(file[1], O_RDONLY)) < 0 || 
        (p_data = (t_parse *)malloc(sizeof(t_parse))) == NULL)
    {
        arg_error('f');
        exit(0);
    }
	parse_data_init(p_data);
    while ((ret = get_next_line(fd, &line) > 0))
	{
		check_line(line, p_data);
		free (line);
	}
	check_line(line, p_data);
	free (line);
    printf("resx - [%d] resy - [%d], parse error - [%d]\n", p_data->res_x, p_data->res_y, p_data->parse_error);
    printf("floor color - [%d] ceiling color - [%d], parse error - [%d]\n", p_data->floor_color, p_data->ceiling_color, p_data->parse_error);
}