SRC       = init.c input.c loop.c main.c parse.c shell.c uninit.c
SRC_IN    = in_sert.c in_submit.c in_delete.c \
			in_ctrl_c.c in_ctrl_d.c in_ctrl_v.c in_ctrl_x.c \
			in_line_left.c in_line_right.c
			in_sel_del.c in_sel_left.c in_sel_right.c

SRC_INIT  = env.c sig.c tty.c

SRC += $(addprefix in/,$(SRC_IN))
SRC := $(addprefix src/,$(SRC))
