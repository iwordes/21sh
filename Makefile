NAME     = 21sh
VERSION  = 1.0.0
AUTHOR   = iwordes

CC       = gcc
CF       = -Wall -Wextra -Werror
CF      += -L libfs -L libft -l fs -l ft
CF      += -I include -I libfs/include -I libft/include

SRC_BI   = echo.c

SRC_IN   = up.c down.c right.c left.c bksp.c
SRC_IN  += sert.c

SRC_TM   = up.c down.c right.c left.c bksp.c
SRC_TM  += clr_sol.c clr_ln.c  clr_eol.c
SRC_TM  += clr_sos.c clr_scr.c clr_eos.c
SRC_TM  += cur_save.c cur_rest.c

#          v Bkup v Set
SRC_INIT = tty1.c tty2.c
SRC_UNIT = tty1.c tty2.c

SRC      = main.c
SRC     += bi_echo.c
SRC     += init_tty.c uninit_tty.c
SRC     += input.c
SRC     += in_up.c in_down.c in_right.c in_left.c in_bksp.c in_sert.c
SRC     += tm_up.c tm_down.c tm_right.c tm_left.c tm_bksp.c tm_clr_eol.c
SRC     += tm_cur_save.c tm_cur_rest.c tm_clr_eos.c
SRC     += tm_putstr.c
SRC     := $(addprefix src/,$(SRC))

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
