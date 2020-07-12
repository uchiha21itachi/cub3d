CC = gcc

FLAGS = -Wall -Wextra -Werror

MLXLIB = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

NAME = cub3D

SRCS =	main.c \
cub3d.c \
get_next_line.c \
get_next_line_utils.c \
parser_utils.c \
parsing_errors.c \
parsing2.c \
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
# SRC = main.c \
# cub3d.c

# OBJ = $(SRC:.c=.o)

# all	:$(NAME)

# $(NAME)	:$(OBJ)
# 	# $(CC) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
# 	$(CC) -o $(NAME) $(OBJ) -Iincludes -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
# clean	:
# 	rm -f $(NAME) $(OBJ) *~ core *.core


# re	: clean all
