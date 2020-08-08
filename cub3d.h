/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:14:00 by yassharm          #+#    #+#             */
/*   Updated: 2020/08/05 22:43:15 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
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

typedef	struct s_player {
	double	posX;
	double	posY;
}				t_player;

typedef	struct s_game
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		old_time;
	int			mapX;
	int			mapY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			side;
	double		perWallDist;
	double		moveSpeed;
	double		rotSpeed;
}				t_game;

typedef	struct s_draw
{
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}				t_draw;

typedef	struct	s_keys
{
	int			k_up;
	int			k_down;
	int			k_left;
	int			k_right;
	int			k_a;
	int			k_s;
	int			k_d;
	int			k_w;
}				t_keys;

typedef struct s_parse {
	int			res_x;
	int			res_y;
	int			**map;
	int			**temp_map;
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
	int			map_check_ret;
	int			map_error;
	t_player	*temp_player;
}				t_parse;

//utils.c
int		calculate_map_y_size(char *file);
void	free_map(t_parse  *p_data);
void	free_temp_map(t_parse  *p_data);


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
int		check_r_line(char *line);
int		count_spaces(char *line);
char	*remove_spaces(char *line);
char	*remove_digits(char *line);
int		get_min(int x, int y);
void	*ft_calloc(size_t count, size_t size);

//parsing_errors.c
void	parsing_error_messege(char c);
void	print_parse_data(t_parse *p_data);
void	print_map(t_parse *p_data);
void	print_temp_map(t_parse *p_data);


//create_game.c
void		create_game(t_parse *p_data);
void		verLine(int x, t_draw *draw, t_mlx mlx, t_img img, int color);


//game.c
void	game(t_parse  *p_data, t_mlx mlx, t_img img);


//ft_atoi.c
int			ft_atoi(const char *str);


#endif
