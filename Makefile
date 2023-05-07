NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC = src/main.c src/list.c src/utils.c src/list_two.c \
	src/list_three.c src/error.c src/parsing.c src/sort.c

OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))

RM = rm -f

LIBFT = libft.a

LIBFTPATH = includes/libft/

all: $(NAME) logo
$(NAME): $(OBJ) $(LIBFTPATH)$(LIBFT)
	@$(CC) $(CFLAGS) -fsanitize=address -o $(NAME) $(LIBFTPATH)$(LIBFT) $(OBJ)
bin/%.o: src/%.c
	@mkdir -p bin
	@$(CC) $(CFLAGS) -c -o $@ $<
$(LIBFTPATH)$(LIBFT):
	@$(MAKE) -C $(LIBFTPATH)
clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFTPATH) fclean
fclean: clean
	@$(RM) $(NAME)
	@$(RM) -rf bin/

re: fclean all

logo:
	@echo "\033[32;1m"
	@echo "███▄ ▄███▓ ███▄ ▄███▓ ▄▄▄       ██▀███   ▄████▄   ▒█████  ▄▄▄█████▓▄▄▄█████▓"
	@echo "▓██▒▀█▀ ██▒▓██▒▀█▀ ██▒▒████▄    ▓██ ▒ ██▒▒██▀ ▀█  ▒██▒  ██▒▓  ██▒ ▓▒▓  ██▒ ▓▒"
	@echo "▓██    ▓██░▓██    ▓██░▒██  ▀█▄  ▓██ ░▄█ ▒▒▓█    ▄ ▒██░  ██▒▒ ▓██░ ▒░▒ ▓██░ ▒░"
	@echo "▒██    ▒██ ▒██    ▒██ ░██▄▄▄▄██ ▒██▀▀█▄  ▒▓▓▄ ▄██▒▒██   ██░░ ▓██▓ ░ ░ ▓██▓ ░ "
	@echo "▒██▒   ░██▒▒██▒   ░██▒ ▓█   ▓██▒░██▓ ▒██▒▒ ▓███▀ ░░ ████▓▒░  ▒██▒ ░   ▒██▒ ░ "
	@echo "░ ▒░   ░  ░░ ▒░   ░  ░ ▒▒   ▓▒█░░ ▒▓ ░▒▓░░ ░▒ ▒  ░░ ▒░▒░▒░   ▒ ░░     ▒ ░░   "
	@echo "░  ░      ░░  ░      ░  ▒   ▒▒ ░  ░▒ ░ ▒░  ░  ▒     ░ ▒ ▒░     ░        ░    "
	@echo "░      ░   ░      ░     ░   ▒     ░░   ░ ░        ░ ░ ░ ▒    ░        ░      "
	@echo "       ░          ░         ░  ░   ░     ░ ░          ░ ░                    "
	@echo "                                         ░                                   \033[0m"
