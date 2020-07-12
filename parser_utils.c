/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 06:50:22 by yassharm          #+#    #+#             */
/*   Updated: 2020/07/11 06:50:24 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else 
		return (0);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		count_spaces(char *line)
{
	int counter;

	counter = 0;
	while (ft_isspace(line[counter]))
		counter++;
	return (counter);
}

char	*remove_spaces(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

char	*remove_digits(char *line)
{
	while (ft_isdigit(*line))
		line++;
	return (line);
}

int		get_min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total;

	total = count * size;
	p = malloc(total);
	if (p == 0)
		return (NULL);
	else
		ft_bzero(p, total);
	return (p);
}

