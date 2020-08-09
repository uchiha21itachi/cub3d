/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:43:37 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/05 22:43:40 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_error(int fd, char **str, char **line)
{
	if (fd < 0 || fd > FOPEN_MAX || line == NULL
	|| BUFFER_SIZE < 1 || read(fd, *str, 0))
	{
		return (-1);
	}
	if (!*str)
	{
		if (!(*str = ft_strdup("")))
		{
			return (-1);
		}
	}
	return (1);
}

char	*read_line(char **str, int fd, int *ret)
{
	int		n;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	if (check_newline(*str))
		return (*str);
	n = (read(fd, buf, BUFFER_SIZE));
	buf[n] = '\0';
	temp = *str;
	*str = ft_strjoin(temp, buf);
	free(temp);
	temp = NULL;
	if (n == 0)
	{
		*ret = 0;
		return (*str);
	}
	else
	{
		*str = read_line(str, fd, ret);
	}
	return (*str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	int			i;
	char		*temp;

	if (check_error(fd, &str, line) == -1)
		return (-1);
	i = 0;
	ret = 1;
	str = read_line(&str, fd, &ret);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = (i == 0) ? ft_strdup("") : ft_strsub(str, 0, i);
	temp = str;
	str = ft_strsub(temp, i + 1, ft_strlen(temp) - i);
	free(temp);
	temp = NULL;
	if (ret == 0 && (!check_newline(str)))
	{
		free(str);
		str = NULL;
	}
	return (ret);
}
