
INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I..

NAME= mlx-test
SRC = cub3d.c
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	# $(CC) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
	$(CC) -o $(NAME) $(OBJ) -Iincludes -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all
