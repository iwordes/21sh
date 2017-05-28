NAME     = 21sh

CC       = gcc
CF      += -Wall -Wextra -Werror
CF      += -I include -I lib/ft/include
CF      += -L lib/ft -lft

SHELL   := /bin/sh

include src.mk

#

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf build
	make -C lib/ft fclean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

#

$(NAME): $(SRC) lib/ft/libft.a
	@$(CC) $(CF) -o $@ $(SRC)
	@echo "[ \x1b[92mOK\x1b[0m ] $@"

%.a:
	@make -C $(@D)
	@echo "[ \x1b[92mOK\x1b[0m ] $@"
