#--- DEFAULT VALUES ---#

NAME = push_swap

SRC = src/main.c src/error.c src/list.c src/list_two.c src/list_three.c \
	src/parsing.c src/sort.c src/utils.c src/cost.c src/sort_part_two.c \
	src/final_sort.c

OBJS = $(patsubst src/%.c, bin/%.o, $(SRC))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFTPATH = includes/libft/

LIBFT = libft.a

LIBMMS = includes/libmms/

#---   RULES   ---#

all: $(NAME) logo

$(NAME): $(OBJS) $(LIBFTPATH)$(LIBFT) $(LIBMMS)libmms.a
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTPATH) -lft -L$(LIBMMS) -lmms -o $(NAME)

bin/%.o: src/%.c
	@mkdir -p bin/
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFTPATH)$(LIBFT):
	@$(MAKE) -C $(LIBFTPATH)
	@$(MAKE) -C $(LIBFTPATH) bonus

$(LIBMMS)libmms.a:
	$(MAKE) -C $(LIBMMS)

clean:
	@rm -rf bin/
	@$(MAKE) -C $(LIBFTPATH) clean
	$(MAKE) -C $(LIBMMS) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTPATH) fclean
	$(MAKE) -C $(LIBMMS) fclean

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
