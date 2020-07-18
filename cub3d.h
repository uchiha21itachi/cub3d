/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:14:00 by yassharm          #+#    #+#             */
/*   Updated: 2020/07/11 03:14:01 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
#include "get_next_line.h"

typedef	struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}				t_mlx;

typedef struct s_parse {
	int			res_x;
	int			res_y;
	int			**map;
	int			map_x;
	int			map_y;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*s_path;
	int			map_start;
	int			temp_counter;
	int			*len_arr;
}				t_parse;

//utils.c
int		calculate_map_y_size(char *file);
void	free_parse_data(t_parse  *p_data);

//parsing.c
void		parse(char **file, int map_y_size);
t_parse		*parse_data_init(t_parse *p_data, int map_y_size);
t_parse		*check_line(char *line, t_parse *p_data);
t_parse		*get_resolution(char *line, t_parse *p_data);

//parsing_texture.c
t_parse		*get_tex_path(char *line, t_parse *p_data);


//parsing_map.c
t_parse		*parse_map(char *line, t_parse *p_data);

//parsing_map_check.c
t_parse		*check_map(t_parse *p_data);

//parser_utils.c
int		ft_isspace(char c);
int		ft_isdigit(int c);
int		count_spaces(char *line);
char	*remove_spaces(char *line);
char	*remove_digits(char *line);
int		get_min(int x, int y);
void	*ft_calloc(size_t count, size_t size);

//parsing_errors.c
void	parsing_error_messege(char c);
void	print_parse_data(t_parse *p_data);
void	print_map(t_parse *p_data);



//ft_atoi.c
int			ft_atoi(const char *str);


#endif