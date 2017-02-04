NAME     = 21sh
VERSION  = 1.0.0
AUTHOR   = iwordes

CC       = gcc
CF       = -Wall -Wextra -Werror
CF      += -L libfs -L libft -l fs -l ft
CF      += -I include -I libfs/include -I libft/include

include src.mk

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	make -C fclean lib/fs
	make -C fclean lib/ft

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

$(NAME): libfs/libfs.a libft/libft.a $(SRC)
	$(CC) $(CF) -o $@ $(SRC)

libfs/libfs.a:
	make -C libfs

libft/libft.a:
	make -C libft
