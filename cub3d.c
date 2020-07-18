/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:13:53 by yassharm          #+#    #+#             */
/*   Updated: 2020/07/11 03:13:55 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"




void	free_parse_data(t_parse  *p_data)
{
	int i;
	int *temp;

	i = 0;
	while (i < p_data->map_y)
	{
		temp = p_data->map[i];
		free(temp);
		i++;
	}	
	free(p_data->map);
	temp = p_data->len_arr;
	free(temp);
	free(p_data);
}

