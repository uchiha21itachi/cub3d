/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:18:06 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/12 20:18:07 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arg_error(char c)
{
	if (c == 'a')
		printf("Wrong Number of arguments\n");
	else if (c == 'm')
		printf("wrong map file extention/type \n");
	else if (c == 's')
		printf("wrong second argument (not --save) \n");
	else if (c == 'f')
		printf("Error opening the file fd < 0 \n");
	else if (c == 'c')
		printf("Error while malloc \n");
	else if (c == 'e')
		printf("Error while Parsing.. Exiting the interface... .\n");
}

int		check_dot(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i] != 0)
	{
		if (line[i] == '.')
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		check_save(char *line)
{
	if (ft_strlen(line) == 6)
	{
		if (line[0] == '-' && line[1] == '-' && line[2] == 's' &&
			line[3] == 'a' && line[4] == 'v' && line[5] == 'e')
			return (1);
	}
	return (-1);
}

int		check_cub(char *temp, int len)
{
	int		ret;

	ret = 0;
	if (temp[len - 4] == '.' && temp[len - 3] == 'c' &&
		temp[len - 2] == 'u' && temp[len - 1] == 'b')
		ret = 1;
	return (ret);
}

int		check_args(char **argv, int argc)
{
	char	*temp;
	int		len;

	temp = ft_strdup(argv[1]);
	len = ft_strlen(temp);
	if (!(check_cub(temp, len)))
	{
		arg_error('m');
		free(temp);
		return (-1);
	}
	free(temp);
	if (argc == 3)
	{
		temp = ft_strdup(argv[2]);
		if (check_save(temp) == 1)
		{
			free(temp);
			return (2);
		}
		arg_error('s');
		free(temp);
		return (-1);
	}
	return (1);
}
