NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror 
FCLAGS = libmlx_Linux.a -Lmlx_linux  -Imlx_linux -lXext -lX11 -lm

SRC =\
	fract_ol.c \
	fractol_utils.c \
	handle_mouse.c \
	julia.c \
	mandelbrot.c \
	parsing.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FCLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
