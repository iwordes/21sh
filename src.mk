SRC = global.c has_ws.c heredoc.c init.c input.c lex.c main.c parse.c redir.c redir_new.c shell.c subs_var.c uninit.c update_pwd.c ws_segs.c
#SRC_AC = path.c
SRC_ALIAS = add.c list.c set.c setkv.c
SRC_BI = alias.c echo.c env.c exit.c help.c var.c
SRC_CMD = grow.c init.c push_argv.c push_redir.c
SRC_CMDS = del.c grow.c init.c
SRC_DEBUG = type.c cmds.c tokens.c
SRC_ENV = del.c get.c get_safe.c grow.c list.c pwd.c set.c setkey.c
SRC_EXEC = bi.c cmd.c cmds.c name.c path.c wait.c
SRC_HIST = add.c grow.c history_next.c history_prev.c
SRC_IN = print.c return.c eot.c left.c right.c sert.c del.c sol.c eol.c eoi.c
SRC_IN += wd_left.c wd_right.c backslash.c goto.c up.c down.c
SRC_INIT = env.c hist.c sig.c tty.c tty1.c tty2.c var.c
SRC_KV = cmp.c new.c val.c
SRC_LX = err.c pipe.c redir.c sep.c str.c str1_2.c
SRC_PATT = pipe.c redir.c sep.c str1_2.c
SRC_PS = err.c heredoc.c redir.c str.c
SRC_SH = left.c right.c
SRC_SIG = abrt.c alrm.c bus.c chld.c cont.c emt.c fpe.c hup.c ill.c int.c pipe.c quit.c segv.c sys.c term.c trap.c tstp.c ttin.c ttou.c urg.c winch.c
SRC_SUBSH =
SRC_TK = del.c new.c
SRC_TM    = init.c strnequ.c
SRC_TM   += up.c down.c right.c left.c bksp.c gotor.c nextln.c prevln.c
SRC_TM   += clr_eol.c #clr_sol.c clr_ln.c
SRC_TM   += clr_eos.c #clr_sos.c clr_scr.c
SRC_TM   += cur_save.c cur_rest.c
SRC_TM   += putchar.c putstr.c cols.c rows.c
SRC_UNINIT = env.c hist.c tty.c var.c
SRC_VAR = del.c get.c get_safe.c grow.c list.c set.c setkey.c

SRC := $(addprefix src/,$(SRC))
SRC += $(addprefix src/ac/,$(SRC_AC))
SRC += $(addprefix src/alias/,$(SRC_ALIAS))
SRC += $(addprefix src/bi/,$(SRC_BI))
SRC += $(addprefix src/cmd/,$(SRC_CMD))
SRC += $(addprefix src/cmds/,$(SRC_CMDS))
SRC += $(addprefix src/debug/,$(SRC_DEBUG))
SRC += $(addprefix src/env/,$(SRC_ENV))
SRC += $(addprefix src/exec/,$(SRC_EXEC))
SRC += $(addprefix src/hist/,$(SRC_HIST))
SRC += $(addprefix src/in/,$(SRC_IN))
SRC += $(addprefix src/init/,$(SRC_INIT))
SRC += $(addprefix src/kv/,$(SRC_KV))
SRC += $(addprefix src/lx/,$(SRC_LX))
SRC += $(addprefix src/patt/,$(SRC_PATT))
SRC += $(addprefix src/ps/,$(SRC_PS))
SRC += $(addprefix src/sh/,$(SRC_SH))
SRC += $(addprefix src/sig/,$(SRC_SIG))
SRC += $(addprefix src/subsh/,$(SRC_SUBSH))
SRC += $(addprefix src/tk/,$(SRC_TK))
SRC += $(addprefix src/tm/,$(SRC_TM))
SRC += $(addprefix src/uninit/,$(SRC_UNINIT))
SRC += $(addprefix src/var/,$(SRC_VAR))
SRC := $(SRC)
