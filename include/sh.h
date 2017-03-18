/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:20:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 11:51:06 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

/*
** #top
*/

# include <fcntl.h>

# include <libfs.h>
# include <libft.h>
# include "libtm.h"

#ifndef ISDIG
# define ISDIG(C) (C >= '0' && C <= '9')
#endif

# define ENV_LEN 256
# define VAR_LEN 256
# define HIST_LEN 128
# define ALIAS_LEN 64

# define MGUARD(M) if ((M) == NULL) exit(12)

# define LX_ERR(M) { *err = true; lx_err(M); return; }
# define PS_ERR(M) { *err = true; ps_err(M); return; }

# define PS_ERRIF(COND, MSG) if (COND) { ps_err(505, MSG); return ; }

/*
** Variables can be replaced after tokenization by simply "inserting" more
** arguments/tokens into the space where the one would have gone.
*/
/*
** STR1 has no variable substitution.
*/
/*
** N(<|>)&N should also work (e.g. 2>&1)
*/

# define RD_IN   0
# define RD_DOC  1
# define RD_OUT  2
# define RD_AOUT 3

# define TK_HDOC  0
# define TK_PIPE  1
# define TK_SEP   2
# define TK_STR   3
# define TK_STR1  4
# define TK_STR2  5
# define TK_RIN   6
# define TK_ROUT  7
# define TK_RAOUT 8
# define TK_REDIR 9

# define TK_ISPIPE(T) (T->type == TK_PIPE)
# define TK_ISREDIR__1(T) (T->type == TK_HDOC || T->type == TK_RIN)
# define TK_ISREDIR__2(T) (T->type == TK_ROUT || T->type == TK_RAOUT)
# define TK_ISREDIR(T) (TK_ISREDIR__1(T) || TK_ISREDIR__2(T))
# define TK_ISSEP(T) (T->type == TK_SEP)
# define TK_ISSTR__1(TK) (TK->type == TK_STR)
# define TK_ISSTR__2(TK) (TK->type == TK_STR1 || TK->type == TK_STR2)
# define TK_ISSTR(TK) (TK_ISSTR__1(TK) || TK_ISSTR__2(TK))

/*
** #parse
*/

typedef struct		s_ps
{
	char			*ln;
	size_t			i;
	size_t			l;
}					t_ps;

/*
** tk.adj: Whether or not the token is adjacent to its prior token.
*/

typedef struct		s_token
{
	uint8_t			type;
	bool			adj;
	char			*val;
	struct s_token	*next;
}					t_token;

typedef struct		s_redir
{
	int				from;
	int				over;
	char			*doc;
	char			*path;
	struct s_redir	*next;
	int				type;
	int				opt;
}					t_redir;

typedef struct		s_cmd
{
	char			**argv;
	long			argc;
	size_t			l;
	t_redir			*redir;
	bool			pipe;
}					t_cmd;

typedef struct		s_cmds
{
	t_cmd			*cmd;
	size_t			l;
}					t_cmds;

/*
*/

/*
** char *ps -- Rendered, cached prompt string
** char *ln -- User-editable line contents
** size_t mem -- Amount of bytes allocated to ln
** size_t ps_len -- Cached length of the prompt string
** size_t ln_len -- Cached length of the input string
*/

typedef struct		s_inln
{
	char			*ps;
	char			*ln;
	size_t			mem;
	size_t			ps_len;
	size_t			ln_len;
}					t_inln;

typedef struct		s_in
{
	t_inln			*ln;
	size_t			mem;
	size_t			l;
	size_t			x;
	size_t			y;
	char			*q;

	char			*ps1;
	char			*ps2;
	size_t			ps1_len;
	size_t			ps2_len;
}					t_in;

/*
** #shell
*/

typedef struct		s_sh
{
	char			**env;
	char			**var;
	char			**hist;
	char			**alias;
	size_t			env_len;
	size_t			var_len;
	size_t			hist_len;
	size_t			alias_len;

	int				cols;
	int				cx;
	int				cy;

	char			**whist;
	char			*ln;

	struct termios	tm_cfg_;
	struct termios	tm_cfg;
}					t_sh;

/*
** #functions
*/

void				debug_cmds(t_cmds *cmds);
void				debug_tokens(t_token *tk);
char				*debug_type(int type);

char				alias_add(const char *name, const char *cmd);
void				alias_list(void);
char				alias_set(const char *name, const char *cmd);
bool				alias_setkv(const char *kv);


int					bi_echo(char **argv);
int					bi_exit(char **argv);

void				cmd_grow(t_cmd *cmd, size_t c);
void				cmd_init(t_cmd *cmd);
void				cmd_push_argv(t_cmd *cmd, char **argv);
void				cmd_push_redir(t_cmd *cmd, int from, int over);

void				cmds_del(t_cmds *cmds);
void				cmds_grow(t_cmds *cmds, size_t c);
void				cmds_init(t_cmds *cmds);

bool				env_del(const char *env);
char				*env_get(const char *env);
char				*env_get_safe(const char *key);
void				env_grow(size_t i);
void				env_list(void);
char				env_set(const char *env);
char				env_setkey(const char *key, const char *val);

int					exec_bi(t_cmd *cmd);
int					exec_cmd(t_cmd *cmd);
void				exec_cmds(t_cmds *cmds);
int					exec_name(t_cmd *cmd);
int					exec_path(t_cmd *cmd, const char *path);
int					exec_wait(pid_t pid);

pid_t				exec_bi_async(t_cmd *cmd);
pid_t				exec_cmd_async(t_cmd *cmd);
pid_t				exec_name_async(t_cmd *cmd);
pid_t				exec_path_async(t_cmd *cmd, const char *path);

void				hist_add(const char *line);
void				hist_grow(size_t i);

void				init(void);
void				init_env(void);
void				init_tty(void);
void				init_var(void);
void				init_hist(void);

char				*input(void);
bool				in_eot(t_in *in);
bool				in_return(t_in *in);

bool				in_backslash(t_in *in);

bool				in_soi(t_in *in);
bool				in_eoi(t_in *in);
bool				in_sol(t_in *in);
bool				in_eol(t_in *in);

bool				in_up(t_in *in);
bool				in_down(t_in *in);
bool				in_left(t_in *in);
bool				in_right(t_in *in);

bool				in_wd_left(t_in *in);
bool				in_wd_right(t_in *in);

void				in_sert(t_in *in, char buff[8]);
bool				in_del(t_in *in);

void				in_goto(t_in *in, int x, int y);
void				in_print(t_in *in);

char				kv_cmp(const char *kv1, const char *kv2);
char				*kv_new(const char *key, const char *val);
bool				kv_val(const char *kv);

t_token				*lex(const char *ln);
void				lx_err(const char *msg);
void				lx_pipe(t_token *tk, const char **str, bool *err);
void				lx_redir(t_token *tk, const char **str, bool *err);
void				lx_sep(t_token *tk, const char **str, bool *err);
void				lx_str(t_token *tk, const char **str, bool *err);
void				lx_str1_2(t_token *tk, const char **str, bool *err);

bool				parse(t_cmds *cmds, t_token *tk);
void				ps_err(const char *msg);
void				ps_pipe(t_cmd *cmd, t_token *tk);
bool				ps_redir(t_cmd *cmd, t_token *tk);
void				ps_str(t_cmd *cmd, t_token *tk);

bool				patt_pipe(const char *str);
bool				patt_redir(const char *str);
bool				patt_sep(const char *str);
bool				patt_str1_2(const char *str);

void				redir(t_redir *r);

void				shell(void);

void				sh_left(void);
void				sh_right(void);

void				sig_abrt(int sig);
void				sig_alrm(int sig);
void				sig_bus(int sig);
void				sig_chld(int sig);
void				sig_cont(int sig);
void				sig_emt(int sig);
void				sig_fpe(int sig);
void				sig_hup(int sig);
void				sig_ill(int sig);
void				sig_int(int sig);
void				sig_pipe(int sig);
void				sig_quit(int sig);
void				sig_segv(int sig);
void				sig_sys(int sig);
void				sig_term(int sig);
void				sig_trap(int sig);
void				sig_tstp(int sig);
void				sig_ttin(int sig);
void				sig_ttou(int sig);
void				sig_urg(int sig);
void				sig_winch(int sig);
/*
int					sig_(int sig);
int					sig_(int sig);
int					sig_(int sig);
int					sig_(int sig);
int					sig_(int sig);
int					sig_(int sig);
int					sig_(int sig);
int					sig_(int sig);
*/

void				tk_del(t_token *tk);
t_token				*tk_new(void);

void				uninit(void);
void				uninit_env(void);
void				uninit_tty(void);
void				uninit_var(void);
void				uninit_hist(void);

bool				var_del(const char *var);
char				*var_get(const char *var);
void				var_grow(size_t i);
void				var_list(void);
char				var_set(const char *var);
char				var_setkey(const char *key, const char *val);

/*
*/

bool				is_bi(const char *name);
int					heredoc(const char *str);
t_redir				*redir_new(void);
char				**subs_var(t_token *tk);
void				update_pwd(void);

/*
*/

extern t_sh			g_sh;

/*
** #bottom
*/

#endif
