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
// # include "keys.h"
# include "keys_linux.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
#include "../gnl/get_next_line.h"

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
}				t_mlx;

typedef	struct s_draw {
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		wallX;
	double		step;
	int			texX;
	int			texY;
	double		texPos;
}				t_draw;

typedef	struct	s_texture {
	int			counter;
	int			width;
	int			height;
	void		*ptr;
	char		*filename;
	char		*data;
}				t_texture;

typedef struct s_sprite{
	double		posX;
	double		posY;
	t_texture	*texture;
}			t_sprite;

typedef struct s_parse {
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
	int			*map_x;
	int			map_y;
	int			map_start;
	int			temp_posX;
	int			temp_posY;
	char		orient;
	int			textwidth;
	int			textheight;
	void		*temp_mlx;
	int			sprite_size;
	t_texture	*textures[6];
	t_sprite	*sprites;
}				t_parse;

typedef	struct	s_rensp {
	double		spriteX;
	double		spriteY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			sScreenX;
	int			sHeight;
	int			sWidth;
	int			drawStartX;
	int			drawStartY;
	int			drawEndX;
	int			drawEndY;
	int			texX;
	int			texY;
	int			stripe;
	int			y;
	int			d;
	int			*order;
	double		*dist;
}				t_rensp;


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
	double		rotSpeedX;
	int			hit;
	t_parse		*p_data;
	t_draw		*d_data;
	t_rensp		*sp_r;
	t_mlx		*mlx;
	t_img		*img;
}				t_game;


//parsing.c
void	parse(char **argv);

//grab_map.c
void	get_resolution(char *line, t_parse *p_data);
void	get_fc_color(char *line, t_parse *p_data);
void	get_tex_path(char *line, t_parse *p_data);


//parse_map.c
void		parse_map(char *line, t_parse *p_data);

//check_map.c
void		check_map(t_parse *p_data);

//create_game.c
void        game_data_init(t_parse  *p_data, t_game *game);
void		draw_texture(t_game *g_data, int x);
void		start_game(t_parse *p_data);




//draw.c

//draw_helper.c
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		get_pixel_color(t_texture *texture, int x, int y, unsigned char *result);
void		draw_pix(t_game *g, unsigned int x, unsigned int y, unsigned char c[4]);
int			move_player(int keycode, t_game *g_data);


//render_map.c
void		render_map(t_game *g_data);

//sprites.c
void        get_sprites(t_game *g_data, int x, int *zbuffer);
void		draw_sprites(t_game *g, int *zbuffer, int i);
void		get_sprite_ren_values(t_game *g, int i);
void		get_order_distance(t_game *g);
void		sprite_data_init(t_game *g);



// sprite_helper.c 
void		fill_sprites_data(t_parse *p_data);
void 		sortSprites(t_game *g_data);



//movement.c
void        move_up(t_game  *g_data);
void        move_down(t_game *g_data);
void        move_right(t_game *g_data);
void        move_left(t_game *g_data);

//rotate.c
void    	rotate_left(t_game *g_data);
void    	rotate_right(t_game *g_data);



//parsing_utils.c
int			check_r_line(char *line);
int			check_color_line(char *line);
int			check_color_order(char *line);
int			create_trgb(int t, int r, int g, int b);
int			check_file_exists(char *filename);


// parse_map_utils.c
void		update_map_size(t_parse *p_data);
void		update_mapx_size(t_parse *p_data);
void		grab_position(t_parse *p_data, char c, int y);
void		set_player_dir(t_game *g_data, t_parse *p_data);




//libft_utils.c
char		*remove_space_digit(char *line, char c);
int			ft_isspace_isdigit(char c, char d);
int			ft_atoi(const char *str);
int			get_min(int x, int y);


//parse_errors.c
void		parsing_error_messege(char c, t_parse *p_data);
void		malloc_error_messege(char c, t_parse *p_data);
void		check_map_error(char c, t_parse *p_data, int x, int y);
void		value_miss_error(char c, t_parse *p_data);

void		print_data_temp(t_parse *p_data);
void		free_parse_data(t_parse *p_data);
void		free_game_mlx_data(t_game *g_data);

//arg_errors.c
void		arg_error(char c);
int			check_args(char **argv, int argc);


//save.c
void		take_screenshot(char **argv);

#endif
