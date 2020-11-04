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

# include "../minilibx/mlx.h"
# include "keys_linux.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../gnl/get_next_line.h"

typedef	struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_mlx {
	void		*mlx;
	void		*mlx_win;
}				t_mlx;

typedef	struct	s_draw {
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	double		step;
	int			tex_x;
	int			tex_y;
	double		texpos;
}				t_draw;

typedef	struct	s_texture {
	int			counter;
	int			width;
	int			height;
	void		*ptr;
	char		*filename;
	char		*data;
}				t_texture;

typedef struct	s_sprite {
	double		posx;
	double		posy;
	t_texture	*texture;
}				t_sprite;

typedef struct	s_parse {
	int			res_x;
	int			res_y;
	int			floor_color;
	int			ceiling_color;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*s_path;
	int			parse_error;
	int			**map;
	int			*x_arr;
	int			map_x;
	int			map_y;
	int			map_start;
	int			temp_posx;
	int			temp_posy;
	char		orient;
	int			textwidth;
	int			textheight;
	void		*temp_mlx;
	int			sprite_size;
	t_texture	*textures[5];
	t_sprite	*sprites;
	int			screenshot;
}				t_parse;

typedef	struct	s_rensp {
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			sscreen_x;
	int			sheight;
	int			swidth;
	int			drawstartx;
	int			drawstarty;
	int			drawendx;
	int			drawendy;
	int			tex_x;
	int			tex_y;
	int			stripe;
	int			y;
	int			d;
	int			*order;
	double		*dist;
	double		*s_first;
	double		*s_second;
	double		tempx;
	double		tempy;
}				t_rensp;

typedef	struct	s_game {
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		old_time;
	int			mapx;
	int			mapy;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			side;
	double		perwalldist;
	double		movespeed;
	double		rotspeed;
	double		rotspeedx;
	int			hit;
	t_parse		*p_data;
	t_draw		*d_data;
	t_rensp		*sp_r;
	t_mlx		*mlx;
	t_img		*img;
}				t_game;

void			parse(char **file, t_parse *p_data);
void			get_resolution(char *line, t_parse *p_data);
void			get_fc_color(char *line, t_parse *p_data);
void			get_tex_path(char *line, t_parse *p_data, char *temp_line);
void			parse_map(char *line, t_parse *p_data);
void			check_map(t_parse *p_data);
void			game_data_init(t_parse *p_data, t_game *game);
void			start_game(t_parse *p_data);
void			draw_texture(t_game *g_data, int x);
void			free_parse_data(t_parse *p_data);
void			free_game_mlx_data(t_game *g_data);
void			free_sprites(t_game *g_data);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			get_pixel_color(t_texture *t, int x, int y, unsigned char *r);
void			draw_pix(t_game *g, unsigned int x, unsigned int y,
				unsigned char c[4]);
int				move_player(int keycode, t_game *g_data);
void			render_map(t_game *g_data);
void			get_sprites(t_game *g_data, int *zbuffer);
void			draw_sprites(t_game *g, int *zbuffer, int i);
void			get_sprite_ren_values(t_game *g, int i);
void			get_order_distance(t_game *g);
int				check_tex_path(char *line);
void			sprite_data_init(t_game *g);
void			fill_sprites_data(t_parse *p_data);
void			sortsprites(t_game *g);
void			draw_check(t_game *g, unsigned char color[4]);
void			move_up(t_game *g_data);
void			move_down(t_game *g_data);
int				check_rgb_range(t_parse *p, int rgb[3], char c);
void			move_right(t_game *g_data);
void			move_left(t_game *g_data);
void			rotate_left(t_game *g_data);
void			rotate_right(t_game *g_data);
int				check_r_line(char *line);
int				check_color_line(char *line);
int				check_color_order(char *line);
int				create_trgb(int t, int r, int g, int b);
int				check_file_exists(char *filename);
void			update_map_size(t_parse *p_data);
void			update_xarr_size(t_parse *p_data);
void			grab_position(t_parse *p_data, char c, int y);
void			set_player_dir(t_game *g_data, t_parse *p_data);
int				check_tex_count(t_parse *p_data);
void			set_pos_north(t_game *g_data);
void			set_pos_south(t_game *g_data);
void			set_pos_west(t_game *g_data);
void			set_pos_east(t_game *g_data);
char			*remove_space_digit(char *line, char c);
int				ft_isspace_isdigit(char c, char d);
int				ft_atoi(const char *str);
int				get_min(int x, int y);
void			ft_putstr(char *str);
void			int_to_char(int n, unsigned char *src);
int				get_pixel(t_game *g_data, unsigned int x, unsigned int y);
void			parsing_error_messege(char c, t_parse *p_data);
void			malloc_error_messege(char c, t_parse *p_data);
void			check_map_error(char c, t_parse *p_data, int x, int y);
void			value_miss_error(char c, t_parse *p_data);
void			print_data_temp(t_parse *p_data);
int				stop_game_all(t_game *g_data);
void			free_parse_data(t_parse *p_data);
void			free_game_mlx_data(t_game *g_data);
void			arg_error(char c);
int				check_args(char **argv, int argc);
void			take_screenshot(t_game *g_data);
int				cross_window(t_game *g_data);

#endif
