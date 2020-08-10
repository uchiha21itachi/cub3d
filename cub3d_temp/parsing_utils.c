#include "cub3d.h"

int		check_r_line(char *line)
{
	int i;

	i = 0;
	if (line[i] == 'R')
		i++;
	while(line[i] != '\0')
	{
		if (ft_isspace_isdigit(line[i], 'd') == 0 && ft_isspace_isdigit(line[i], 's') == 0)
			return(0);
		i++;
	}
	return (1);
}