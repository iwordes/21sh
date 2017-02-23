/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:20:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/22 16:19:36 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <fcntl.h>

# include <libft.h>
# include "libtm.h"

# define ENV_LEN 256
# define VAR_LEN 256
# define HIST_LEN 128
# define ALIAS_LEN 64

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
# define RD_OUT  1
# define RD_AOUT 2
# define RD_HDOC 3

# define TK_HDOC  0
# define TK_PIPE  1
# define TK_SEP   2
# define TK_STR   3
# define TK_STR1  4
# define TK_STR2  5
# define TK_RIN   6
# define TK_ROUT  7
# define TK_RAOUT 8

# define TK_ISSTR__1(TK) (TK->type == TK_STR)
# define TK_ISSTR__2(TK) (TK->type == TK_STR1 || TK->type == TK_STR2)
# define TK_ISSTR(TK) (TK_ISSTR__1(TK) || TK_ISSTR__2(TK))

# define MGUARD(MEM) if ((MEM) == NULL) exit(12)

/*
** Parse phase
** ===========
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
	char			*path;
	int				opt;
	struct s_redir	*next;
}					t_redir;

typedef struct		s_cmd
{
	char			**argv;
	int				argc;
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
** Input phase
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
	size_t			x;
	size_t			y;
	char			*q;

	char			*ps1;
	char			*ps2;
	size_t			ps1_len;
	size_t			ps2_len;
}					t_in;

/*
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

	int				last_status;

	int				rows;
	int				cols;

	char			**whist;
	char			*ln;

	struct termios	tm_cfg_;
	struct termios	tm_cfg;
}					t_sh;

int					bi_exit(char **argv);

void				cmd_exec(t_cmd *cmd);

bool				env_del(const char *env);
char				*env_get(const char *env);
void				env_grow(size_t i);
void				env_list(void);
char				env_set(const char *env);
char				env_setkey(const char *key, const char *val);

int					exec_bi(t_cmd *cmd);
int					exec_cmd(t_cmd *cmd);
int					exec_cmds(t_cmds *cmds);
int					exec_name(t_cmd *cmd);
int					exec_path(t_cmd *cmd, const char *path);

pid_t				exec_bi_async(t_cmd *cmd);
pid_t				exec_cmd_async(t_cmd *cmd);
pid_t				exec_name_async(t_cmd *cmd);
pid_t				exec_path_async(t_cmd *cmd, const char *path);

void				hist_add(const char *line);
void				hist_grow(size_t i);

/*
** Naming schema (mostly consistent):
** in_KEY_(alt:a)(ctrl:c)(shift:s)
*/
char				*input(void);
void				in_up(char **cmd, size_t *i, size_t *l);
void				in_down(char **cmd, size_t *i, size_t *l);
void				in_right(char **cmd, size_t *i, size_t *l);
void				in_left(char **cmd, size_t *i, size_t *l);
void				in_bksp(char **cmd, size_t *i, size_t *l);
void				in_home(char **cmd, size_t *i, size_t *l);
void				in_end(char **cmd, size_t *i, size_t *l);

void				init(void);
void				init_env(void);
void				init_tty(void);
void				init_var(void);
void				init_hist(void);

char				kv_cmp(const char *kv1, const char *kv2);
char				*kv_new(const char *key, const char *val);
bool				kv_val(const char *kv);

void				shell(void);

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

extern t_sh			g_sh;

#endif
