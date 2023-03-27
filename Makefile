NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = src/main.c src/list.c src/utils.c

OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))

RM = rm -f

LIBFT = libft.a

LIBFTPATH = includes/libft/

all: $(NAME)
$(NAME): $(OBJ) $(LIBFTPATH)$(LIBFT)
	$(CC) $(CFLAGS) -g -o $(NAME) $(LIBFTPATH)$(LIBFT) $(OBJ)
bin/%.o: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c -o $@ $<
$(LIBFTPATH)$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)
clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFTPATH) fclean
fclean: clean
	@$(RM) $(NAME)
	@$(RM) -rf bin/

re: fclean all