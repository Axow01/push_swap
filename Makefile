NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = src/main.c

OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))

RM = rm -f

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
bin/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all