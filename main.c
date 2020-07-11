/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:14:06 by yassharm          #+#    #+#             */
/*   Updated: 2020/07/11 03:14:07 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 int main (int argc, char **argv)
 {
	printf ("Number of arguments - %d\n", argc);
	if (argc < 2 || argc > 3)
		printf ("Wrong Number of arguments\n");
	else
		parse(argv);
	printf ("Exiting the simulation.....\n");
	return (0);	 
 }