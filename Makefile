#--- DEFAULT VALUES ---#

NAME = push_swap

SRC = src/main.c src/error.c src/list.c src/list_two.c src/list_three.c \
	src/parsing.c src/sort.c src/utils.c

OBJS = $(patsubst src/%.c, bin/%.o, $(SRC))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFTPATH = includes/libft/

LIBFT = libft.a

#---   RULES   ---#

all: $(NAME) logo

$(NAME): $(OBJS) $(LIBFTPATH)$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTPATH) -lft -o $(NAME)

bin/%.o: src/%.c
	@mkdir -p bin/
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFTPATH)$(LIBFT):
	@$(MAKE) -C $(LIBFTPATH)
	@$(MAKE) -C $(LIBFTPATH) bonus

clean:
	@rm -rf bin/
	@$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	@rm $(NAME)
	@$(MAKE) -C $(LIBFTPATH) fclean

bonus: all

re: fclean all

logo:
	@echo "\033[32;1m		--- BUILD COMPLETE ---"
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
