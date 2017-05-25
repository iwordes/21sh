SRC       = clean.c init.c input.c loop.c main.c parse.c shell.c uninit.c

SRC_IN    = redraw.c tab.c sert.c submit.c delete.c \
			ctrl_c.c ctrl_d.c ctrl_v.c ctrl_x.c \
			line_up.c line_down.c line_left.c line_right.c \
			sel_del.c sel_left.c sel_right.c \
			skip_left.c skip_right.c \
			hist_add.c hist_del.c

SRC_PS    = escape.c home.c init.c is_pipe.c is_ri1.c is_ri2.c is_ro1.c is_ro2.c is_semi.c tokens.c proc.c proc_delim.c proc_plain.c proc_redir.c tokens_ri2.c uninit.c

SRC_TM    = goto.c left.c right.c

SRC_INIT  = env.c hist.c sig.c tty.c

SRC += $(addprefix in/,$(SRC_IN))
SRC += $(addprefix ps/,$(SRC_PS))
SRC += $(addprefix tm/,$(SRC_TM))
SRC += $(addprefix init/,$(SRC_INIT))
SRC := $(addprefix src/,$(SRC))
