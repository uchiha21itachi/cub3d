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
# -fsanitize=address

#CFLAGS = -Wall -Werror -Wextra -I. -Ilibft/. -c  # C flags
INCLUDES =  -Isrc -Ignl # C flags

CFLAGS	= -Ofast -D OS=$(OS)  $(INCLUDES)

RM = rm -f   # rm command

#include all your main .c files here
SRCS =	srcs/main.c \
srcs/save.c \
srcs/parsing.c \
srcs/grab_map.c \
srcs/parse_map.c \
srcs/check_map.c \
srcs/draw.c \
srcs/create_game.c \
srcs/render_game.c \
srcs/movement.c \
utils/parse_map_utils.c \
utils/libft_utils.c \
utils/parsing_utils.c \
errors/arg_errors.c \
errors/parse_errors.c \


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
	#make -C $(LIBFT_DIR) fclean
	#make -C $(MLX_DIR) fclean


re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re


# CC = gcc

# FLAGS = -Wall -Wextra -Werror

# # mac compile
# MLXLIB = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

# # linux compile
# # MLXLIB = -L /usr/local/lib -lmlx -lXext -lX11 -lm -lbsd

# NAME = cub3D

# SRCS =	srcs/main.c \
# srcs/save.c \
# srcs/parsing.c \
# srcs/grab_map.c \
# srcs/parse_map.c \
# srcs/check_map.c \
# srcs/draw.c \
# srcs/create_game.c \
# srcs/render_game.c \
# utils/parse_map_utils.c \
# utils/libft_utils.c \
# utils/parsing_utils.c \
# errors/arg_errors.c \
# errors/parse_errors.c \
# gnl/get_next_line.c \
# gnl/get_next_line_utils.c \



# HEADERS =	cube3d.h \
# gnl/get_next_line.h \

# OBJECT = $(SRCS:.c=.o)

# $(NAME): ${OBJECT}
# 	$(CC) $(FLAGS) $(MLXLIB) -o $(NAME) ${OBJECT}

# all:	$(NAME)

# clean:
# 	rm -f $(OBJECT)

# fclean: clean
# 	rm -f $(NAME)

# re : fclean all

# .PHONY:	re clean fclean all








# INC=%%%%

# INCLIB=$(INC)/../lib

# CC=gcc

# FLAGS = -Wall -Wextra -Werror

# CFLAGS= -I$(INC) -O3 -I..

# NAME= cube3d

# SRCS =	srcs/main.c \
# srcs/save.c \
# srcs/parsing.c \
# srcs/grab_map.c \
# srcs/parse_map.c \
# srcs/check_map.c \
# srcs/draw.c \
# srcs/create_game.c \
# srcs/render_game.c \
# utils/parse_map_utils.c \
# utils/libft_utils.c \
# utils/parsing_utils.c \
# errors/arg_errors.c \
# errors/parse_errors.c \
# gnl/get_next_line.c \
# gnl/get_next_line_utils.c \

# HEADERS =	cube3d.h \
# gnl/get_next_line.h \

# OBJ = $(SRC:.c=.o)

# all	:$(NAME)

# $(NAME)	:$(OBJ)
# 	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re : fclean all

# .PHONY:	re clean fclean all


# re	: clean all

