#include "cub3d.h"

t_parse		*get_resolution(char *line, t_parse *p_data)
{
	p_data->res_x = 0;
	p_data->res_y = 0;
	while (*line && (p_data->res_y == 0 || p_data->res_x == 0))
	{
		line = remove_spaces(line);
		p_data->res_x = get_min(ft_atoi(line), 2560);
		line = remove_digits(line);
		p_data->res_y = get_min(ft_atoi(line), 1440);
		line++;
	}
	if (p_data->res_x == 0 || p_data->res_y == 0)
		parsing_error_messege('i');
	// printf ("Resolution X - %d\n", p_data->res_x);
	// printf ("Resolution Y - %d\n", p_data->res_y);
	return (p_data);
}


t_parse		*check_line(char *line, t_parse *p_data)
{
	int			i;
	char		*temp_line;

	temp_line = ft_strdup(line);
	line = remove_spaces(line);
	if(*line == 'R')
		p_data = get_resolution(line, p_data);		
	else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		p_data = get_tex_path(line, p_data);
	else if (ft_isdigit(*line))
		p_data = parse_map(temp_line, p_data);
	else
		printf ("Unexpected error occured in check line while parsing \n\n");	
	free(temp_line);
	return (p_data);
}

t_parse		*parse_data_init(t_parse *p_data, int map_y_size)
{
	p_data->res_x = 0;
	p_data->res_y = 0;
	p_data->map_x = 0;
	p_data->map_y = map_y_size;
	p_data->temp_counter = 0;	
	return (p_data);
}

void	parse(char **file, int map_y_size)
{
	int		fd;
	char	*line;
	int 	ret;
	t_parse	*p_data;

	fd = open(file[1], O_RDONLY);
	if (fd < 0)
	{
		printf ("unable to open the file \n");
		exit (0);
	}
	p_data = ft_calloc(sizeof(t_parse), 1);
	p_data = parse_data_init(p_data, map_y_size);
	printf ("fd is = %d\n", fd);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		p_data = check_line (line, p_data);
		free (line);
	}
	p_data = check_line (line, p_data);
	free (line);
	print_map(p_data);
	// free(p_data->len_arr);
	// free_map(p_data->map, p_data->len_arr);
	free(p_data);
}