#include "cub3d.h"

void		arg_error(char **argv, char c)
{
	if (c == 'a')
		printf ("Wrong Number of arguments\n");
	else if (c == 'm')
		printf ("wrong map file extention\n");
}

int		check_args(char **argv, int argc)
{
	char	*temp;
	int		len;

	temp = ft_strdup(argv[1]);
	len = ft_strlen(temp);
	if (!(temp[len-4] == '.' && temp[len-3] == 'c' && temp[len-2] == 'u' && temp[len-1] == 'b'))
	{
		arg_error(argv, 'm');
	}
	free(temp);
	if (argc == 3)
	{
		temp = ft_strdup (argv[2]);
		
	}
	return (1);
}