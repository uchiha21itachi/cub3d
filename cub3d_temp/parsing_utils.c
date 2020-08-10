#include "cub3d.h"

int		check_r_line(char *line)
{
	int		counter;

	counter = 0;
	while (*line++)
	{
		if (ft_isspace_isdigit(*line, 's'))
			line = remove_space_digit(line, 's');
		else if (ft_isspace_isdigit(*line, 'd'))
		{
			line = remove_space_digit(line, 'd');
			counter++;
		}
		else
			return (0);
	}
	if (counter != 2)
		return(0);
	return (1);
}