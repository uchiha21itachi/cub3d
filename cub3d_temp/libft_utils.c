#include "cub3d.h"

char	*remove_space_digit(char *line, char c)
{
    if (c == 's')
    {
        while (ft_isspace_isdigit(*line, 's'))
		line++;
    }
	else if (c == 'd')
    {
        while (ft_isspace_isdigit(*line, 'd'))
		line++;
    }
	return (line);
}


int		ft_isspace_isdigit(char c, char d)
{
    if (d == 's')
	{
        if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		    return (1);
    }
    else if (d == 'd')
    {
        if (c >= 48 && c <= 57)
		    return (1);
    }
	return (0);
}

int			ft_atoi(const char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (ft_isspace_isdigit(*str, 's'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result *= 10;
			result += (*(str++) - '0');
		}
		else
			return (result * sign);
	}
	return (result * sign);
}

int		get_min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}