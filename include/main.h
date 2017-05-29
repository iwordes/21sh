/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:23:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/28 19:38:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <termios.h>
# include <unistd.h>

# include <libft.h>

# define W (g_mn.w - 1)
# define MAX_HIST 64

# define S_TERMIOS struct termios
# define S_WINSIZE struct winsize

# define PSFAIL(M) { ps->err = M; return (false); }
# define MGUARD(M) if ((M) == NULL) exit(255)

/*
** =============================================================================
** Structs - Input
*/

typedef struct	s_inline
{
	char		*ln;
	char		*ps;
	uint32_t	len;
	uint32_t	mem;
	uint32_t	ps_len;
}				t_inline;

typedef struct	s_inquote
{
	char		*s;
	char		*e;
}				t_inquote;

typedef struct	s_in
{
	char		*clip;
	char		*hist;
	char		*line;

	t_inline	*ln;
	uint32_t	len;
	uint32_t	mem;

	int64_t		s;
	uint32_t	x;
	uint32_t	y;

	bool		eot;
	bool		cancel;
	bool		submit;
	bool		debug;
}				t_in;

typedef struct	s_inkey
{
	char		*key;
	void		(*fn)(t_in*);
}				t_inkey;

/*
** =============================================================================
** Structs - Parser
*/

/*
** Flags
** F_ADJ: Token is adjacent to previous token.
** F_VAR: Token should be scanned for variables.
** F_EXP: Variables should expand to multiple arguments.
**  NOTE: First in series inherits flags and type.
*/

# define TKF_ADJ 1
# define TKF_VAR 2
# define TKF_EXP 4

# define TK_ADJ(T) (((T).flag & TKF_ADJ) != 0)
# define TK_VAR(T) (((T).flag & TKF_VAR) != 0)
# define TK_EXP(T) (((T).flag & TKF_EXP) != 0)

# define TKT_NONE 0
# define TKT_QUOT 1
# define TKT_R_O1 2
# define TKT_R_O2 3
# define TKT_R_I1 4
# define TKT_R_I2 5
# define TKT_PIPE 6
# define TKT_SEMI 7

typedef struct	s_pscan
{
	uint8_t		type;
	bool		(*fn)(const char*);
}				t_pscan;

typedef struct	s_tk
{
	char		*str;
	uint8_t		flag;
	uint8_t		type;
}				t_tk;

typedef struct	s_exe
{
	char		**argv;
	uint32_t	argv_len;
	uint32_t	argv_mem;

	int			fd[4];
	pid_t		pid;
	bool		pipe;
}				t_exe;

typedef struct	s_ps
{
	t_tk		*tk;
	uint32_t	tk_len;
	uint32_t	tk_mem;

	char		*err;

	t_exe		*exe;
	uint32_t	exe_len;
	uint32_t	exe_mem;
}				t_ps;

/*
** =============================================================================
** Structs
*/

typedef struct	s_bi
{
	char		*cmd;
	void		(*fn)(char**, int);
}				t_bi;

typedef struct	s_main
{
	char		**env;
	uint32_t	env_len;
	uint32_t	env_mem;

	char		**hist;
	uint32_t	hist_len;
	uint32_t	hist_mem;

	char		*err;
	t_in		*in;

	uint32_t	h;

	uint32_t	w;
	uint32_t	x;
	uint32_t	y;

	S_TERMIOS	tm_cfg;
	S_TERMIOS	tm;
}				t_main;

/*
** =============================================================================
** Environment
*/

bool			env_grow();

bool			env_cmp(const char *lhs, const char *rhs);
void			env_del(const char *key);
char			*env_get(const char *key);
char			*env_gets(const char *key);
bool			env_set(const char *keyval);
bool			env_set2(const char *key, const char *val);

/*
** =============================================================================
** Input
*/

void			in_redraw(t_in *in);

void			in_debug(t_in *in);

bool			in_init(t_in *in);
void			in_sert(t_in *in, char *buff);
void			in_uninit(t_in *in);

void			in_tab(t_in *in);

void			in_submit(t_in *in);
void			in_delete(t_in *in);

void			in_ctrl_c(t_in *in);
void			in_ctrl_d(t_in *in);
void			in_ctrl_v(t_in *in);
void			in_ctrl_x(t_in *in);

void			in_line_up(t_in *in);
void			in_line_down(t_in *in);
void			in_line_left(t_in *in);
void			in_line_right(t_in *in);

void			in_sel_del(t_in *in);
void			in_sel_left(t_in *in);
void			in_sel_right(t_in *in);

void			in_skip_left(t_in *in);
void			in_skip_right(t_in *in);

void			in_hist_add(t_in *in);
void			in_hist_del(t_in *in);

/*
** =============================================================================
** Terminal
*/

void			tm_goto(int16_t x, int16_t y);
void			tm_left(void);
void			tm_right(void);

/*
** =============================================================================
** Parsing
*/

bool			parse(t_ps *ps, const char *ln);

bool			ps_init(t_ps *ps);
bool			ps_tokens(t_ps *ps, const char *ln);
bool			ps_home(t_ps *ps);
bool			ps_escape(t_ps *ps);
bool			ps_proc(t_ps *ps);
void			ps_uninit(t_ps *ps);
bool			ps_vars(t_ps *ps);

bool			ps_proc_delim(t_ps *ps, uint32_t *t);
bool			ps_proc_plain(t_ps *ps, uint32_t *t);
bool			ps_proc_redir(t_ps *ps, uint32_t *t);

bool			ps_tokens_ri2(t_ps *ps, const char **ln);

bool			ps_is_pipe(const char *tk);
bool			ps_is_ri1(const char *tk);
bool			ps_is_ri2(const char *tk);
bool			ps_is_ro1(const char *tk);
bool			ps_is_ro2(const char *tk);
bool			ps_is_semi(const char *tk);

/*
** =============================================================================
** Execution
*/

bool			shell(t_ps *ps);

void			sh_cd(char **argv, int argc);
void			sh_env(char **argv, int argc);
void			sh_echo(char **argv, int argc);
void			sh_exit(char **argv, int argc);
void			sh_setenv(char **argv, int argc);
void			sh_unsetenv(char **argv, int argc);

bool			sh_meta_exec(t_exe *exe);
char			*sh_meta_path(const char *bin);
bool			sh_meta_builtin(t_exe *exe);

// ...

/*
** =============================================================================
** Main
*/

void			clean(t_ps *ps, char *ln);
void			init(void);
void			loop(void);
char			*input(void);
void			uninit(void);

void			init_hist(void);
void			init_env(void);
void			init_sig(void);
void			init_tty(void);

void			fd_close(int fd);

extern t_main	g_mn;

#endif
