NAME     = 21sh
VERSION  = 1.0.0
AUTHOR   = iwordes

CC       = gcc
CF       = -Wall -Wextra -Werror
CL       = -L libfs -L libft -l fs -l ft -ltermcap
CI      += -I include -I libfs/include -I libft/include

CLI      = $(CC) $(CF) $(CI)

include src.mk
OBJ     := $(subst src,build,$(SRC:.c=.o))

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf build
	make -C libfs fclean
	make -C libft fclean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(OBJ) libfs/libfs.a libft/libft.a
	$(CLI) $(CL) -o $@ $(OBJ)

build/%.o: src/%.c
	mkdir -p $(@D)
	$(CLI) -c -o $@ $<

libfs/libfs.a:
	make -j7 -C libfs

libft/libft.a:
	make -j7 -C libft
