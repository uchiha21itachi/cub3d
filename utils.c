#include "cub3d.h"

int		get_map_size(char *line)
{
	line = remove_spaces(line);
	if (ft_isdigit(*line))
		return (1);
	else
		return(0);
}

int		calculate_map_y_size(char *file)
{
	//calculating the size of the map before starting the parsing
	int fd;
	int ret;
	int	map_start_counter;
	int	map_y_size;
	char *line;

	map_start_counter = 0;
	map_y_size = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf ("error in opening file in calculate map size(main.c)\n");
		exit(0);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((map_start_counter = get_map_size(line)) == 1)
			map_y_size++;
		free(line);
	}
	if ((map_start_counter = get_map_size(line)) == 1)
		map_y_size++;
	free(line);
	if (close(fd) < 0)
		printf("error in closing file in calculate map size(main.c)\n\n");
	return(map_y_size);
}