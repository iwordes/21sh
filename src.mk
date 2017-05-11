SRC       = init.c input.c loop.c main.c parse.c shell.c uninit.c

SRC_IN    = redraw.c sert.c submit.c delete.c \
			ctrl_c.c ctrl_d.c ctrl_v.c ctrl_x.c \
			line_up.c line_down.c line_left.c line_right.c \
			sel_del.c sel_left.c sel_right.c \
			skip_left.c skip_right.c \
			hist_del.c

SRC_TM    = goto.c left.c right.c

SRC_INIT  = env.c sig.c tty.c

SRC += $(addprefix in/,$(SRC_IN))
SRC += $(addprefix tm/,$(SRC_TM))
SRC += $(addprefix init/,$(SRC_INIT))

SRC := $(addprefix src/,$(SRC))
