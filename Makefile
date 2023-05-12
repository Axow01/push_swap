NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = src/main.c src/list.c src/utils.c src/list_two.c \
	src/list_three.c src/error.c src/parsing.c src/sort.c

OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))

RM = rm -f

LIBFT = libft.a

LIBFTPATH = includes/libft/

all: $(NAME) logo
$(NAME): $(OBJ) $(LIBFTPATH)$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFTPATH)$(LIBFT) -o $(NAME)
bin/%.o: src/%.c
	@mkdir -p bin
	@$(CC) -c -o $@ $<
$(LIBFTPATH)$(LIBFT):
	@$(MAKE) -C $(LIBFTPATH)
clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFTPATH) fclean
fclean: clean
	@$(RM) $(NAME)
	@$(RM) -rf bin/

bonus: all

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
