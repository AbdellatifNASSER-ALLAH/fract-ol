CC=cc
CFLAGS= -Wall -Wextra -Werror
LFLAGS = -I/usr/local/include -L/usr/local/lib -lmlx -lXext -lX11 -lm

NAME=fractol

SRC=events.c  init.c  main.c  math.c  render.c  utils.c
OBJ=$(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ) header.h
	$(CC) $(OBJ) $(LFLAGS) $(CFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
