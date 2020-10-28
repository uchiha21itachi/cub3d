UNAME_S				:= $(shell uname -s)
OS					= 0

ifeq ($(UNAME_S), Linux)
	OS = 1
	LGL := -lGL -lm
	LGL_INC := -I/usr/include/
	MLXFLAG := -lXext -lX11 -lbsd
else ifeq ($(UNAME_S), Darwin)
	OS = 2
	MLXFLAG := -framework OpenGL -framework Appkit
endif

$(info    VAR is $(MLXFLAG))

CC=gcc


NAME = cub3D
CC = gcc  # C compiler
# -fsanitize=address -g3

#CFLAGS = -Wall -Werror -Wextra -I. -Ilibft/. -c  # C flags
INCLUDES =  -Isrc -Ignl # C flags

CFLAGS	= -Wall -Werror -Wextra -D OS=$(OS)  $(INCLUDES)

RM = rm -f   # rm command


SRCS =	srcs/main.c \
srcs/save.c \
srcs/parsing.c \
srcs/grab_map.c \
srcs/parse_map.c \
srcs/check_map.c \
srcs/sprites_helper.c \
srcs/draw.c \
srcs/draw_helper.c \
srcs/create_game.c \
srcs/render_game.c \
srcs/sprites.c \
srcs/movement.c \
srcs/rotate.c \
srcs/free_data.c \
srcs/window.c \
utils/parse_map_utils.c \
utils/libft_utils.c \
utils/parsing_utils.c \
utils/parsing_utils_2.c \
utils/position_utils.c \
errors/arg_errors.c \
errors/parse_errors.c \
#include all your main .c files here



GNL_SRCS = gnl/get_next_line.c \
gnl/get_next_line_utils.c \

GNL_OBJS = $(GNL_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)


all:  $(LIBFT)  $(NAME)
	@printf "Makefile starts\n"

$(NAME): $(OBJS) $(GNL_OBJS)
	@printf "$(OBJS)\n"
	$(CC) $(CFLAGS) $^ -o $@  -lmlx $(LGL_INC) $(MLXFLAG) -lm


clean:
	rm -f $(OBJS) $(GNL_OBJS)
	#make -C $(LIBFT_DIR) clean
	#make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f screenshot.bmp
	#make -C $(LIBFT_DIR) fclean
	#make -C $(MLX_DIR) fclean


re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re
