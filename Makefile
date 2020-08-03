CC = gcc

FLAGS = -Wall -Wextra -Werror

# mac compile
MLXLIB = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

# linux compile
# MLXLIB = -L /usr/local/lib -lmlx -lXext -lX11 -lm -lbsd

NAME = cub3D

SRCS =	main.c \
cub3d.c \
utils.c \
parsing.c \
parsing_texture.c \
parsing_map.c \
parsing_map_check.c \
parsing_utils.c \
parsing_errors.c \
create_game.c \
get_next_line.c \
get_next_line_utils.c \
ft_atoi.c \


HEADERS =	cube3d.h \
			get_next_line.h \

OBJECT = $(SRCS:.c=.o)

$(NAME): ${OBJECT}
	$(CC) $(FLAGS) $(MLXLIB) -o $(NAME) ${OBJECT}

all:	$(NAME)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:	re clean fclean all

















# INC=%%%%

# INCLIB=$(INC)/../lib

# CC=gcc

# CFLAGS= -I$(INC) -O3 -I..

# NAME= mlx-test
# SRCS =	main.c \
# cub3d.c \
# utils.c \
# parsing.c \
# parsing_texture.c \
# parsing_map.c \
# parsing_map_check.c \
# parsing_utils.c \
# parsing_errors.c \
# get_next_line.c \
# get_next_line_utils.c \
# ft_atoi.c \


# OBJ = $(SRC:.c=.o)

# all	:$(NAME)

# $(NAME)	:$(OBJ)
# 	$(CC) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
# 	# $(CC) -o $(NAME) $(OBJ) -Iincludes -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
# clean	:
# 	rm -f $(NAME) $(OBJ) *~ core *.core


# re	: clean all
