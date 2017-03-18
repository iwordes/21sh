# Functions for 21sh

SRC       = main.c init.c shell.c uninit.c
SRC      += input.c lex.c parse.c

SRC_BI    = echo.c exit.c

SRC_CMD   = \
init.c        parse.c       push_redir.c  split_args.c  split_pipe.c \
input.c       push_argv.c   split.c       split_logic.c val.c

SRC_CMDS  = grow.c init.c

SRC_ENV   = del.c get.c get_safe.c grow.c list.c pwd.c set.c setkey.c

SRC_EXEC  = bi.c cmd.c cmds.c name.c path.c wait.c

#SRC_IN    = up.c down.c right.c left.c
#SRC_IN   += home.c end.c
#SRC_IN   += bksp.c
#SRC_IN   +=

SRC_LX    = pipe.c redir.c sep.c str.c str1_2.c

SRC_KV    = cmp.c new.c val.c

SRC_TK    = del.c new.c

SRC_TM    = up.c down.c right.c left.c bksp.c
SRC_TM   += clr_eol.c #clr_sol.c clr_ln.c
SRC_TM   += clr_eos.c #clr_sos.c clr_scr.c
SRC_TM   += cur_save.c cur_rest.c
SRC_TM   += putchar.c putstr.c

SRC_ALS   =

SRC_CMD   =

SRC_ENV   = del.c get.c grow.c set.c setkey.c

SRC_VAR   = del.c get.c grow.c set.c setkey.c

SRC_HIST  = add.c grow.c

SRC_INIT  = env.c tty.c var.c hist.c
#           v Bkup v Set
#SRC_INIT += tty1.c tty2.c

#SRC_UNIT  = tty1.c tty2.c

SRC_UNIT  = env.c tty.c var.c hist.c

SRC      += $(addprefix bi/,$(SRC_BI))
SRC      += $(addprefix in/,$(SRC_IN))
SRC      += $(addprefix lx/,$(SRC_LX))
SRC      += $(addprefix kv/,$(SRC_KV))
SRC      += $(addprefix tm/,$(SRC_TM))
SRC      += $(addprefix cmd/,$(SRC_CMD))
SRC      += $(addprefix env/,$(SRC_ENV))
SRC      += $(addprefix var/,$(SRC_VAR))
SRC      += $(addprefix exec/,$(SRC_EXEC))
SRC      += $(addprefix hist/,$(SRC_HIST))
SRC      += $(addprefix init/,$(SRC_INIT))
SRC      += $(addprefix alias/,$(SRC_ALS))
SRC      += $(addprefix uninit/,$(SRC_UNIT))
SRC      := $(addprefix src/,$(SRC))
