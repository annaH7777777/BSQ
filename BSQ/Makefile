NAME = bsq

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = find_solution.c verify_map.c ft_libhelp.c main.c
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
