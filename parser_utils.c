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

#include <stdio.h>


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

void	parse_error_mes(char c)
{
	if (c == 'u')
	{
		printf ("Error - unexpected character in map file\n");
	}
	
}