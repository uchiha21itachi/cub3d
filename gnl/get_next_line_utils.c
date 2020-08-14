/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:02:56 by yassharm          #+#    #+#             */
/*   Updated: 2020/01/21 22:03:00 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	char	*ans;
	int		len;

	len = ft_strlen(s1) + ft_strlen((char *)s2);
	if (!(ans = (char *)malloc(len + 1)))
		return (NULL);
	while (*s1)
		*ans++ = *s1++;
	while (*s2)
		*ans++ = *s2++;
	*ans = '\0';
	if (*s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (ans - len);
}

char		*ft_strdup(char *s1)
{
	char		*p;
	size_t		length;
	size_t		i;

	i = 0;
	length = ft_strlen(s1);
	p = (char *)malloc((length + 1) * sizeof(char));
	p[length] = '\0';
	if (p == 0)
		return (NULL);
	else
	{
		while (i < length)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

int			check_newline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	sub[len] = '\0';
	if (sub == NULL)
		return (NULL);
	while (i != len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
