/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:20:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 12:39:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <libft.h>
# include "libtm.h"

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

# define TK_AND
# define TK_BG
# define TK_HEREDOC
# define TK_OR
# define TK_PIPE
# define TK_SEP
# define TK_STR
# define TK_STR1
# define TK_STR2
# define TK_RIN
# define TK_ROUT
# define TK_RAOUT

# define MGUARD(MEM) if ((MEM) == NULL) exit(12)

typedef struct		s_token
{
	char			*cont;
	uint8_t			type;
}					t_token;

typedef struct		s_cmd
{
	char			**argv;
	int				stdin;
	int				stdout;
	int				stderr;
}					t_cmd;

/*
** 1. Create pipes.
** 2. Set each command's std{in,out,err} to the required one (if not redir)
*/

typedef struct		s_pipeline
{
	t_cmd			*cmd;
	size_t			len;
}					t_pipeline;

typedef struct		s_job
{
	int				jid;
	pid_t			*pid;
	size_t			pcount;
}					t_job;

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

	struct termios	tm_cfg_;
	struct termios	tm_cfg;
}					t_sh;

char				*input(void);

void				in_up(char **cmd, size_t *i, size_t *l);
void				in_down(char **cmd, size_t *i, size_t *l);
void				in_right(char **cmd, size_t *i, size_t *l);
void				in_left(char **cmd, size_t *i, size_t *l);

void				in_bksp(char **cmd, size_t *i, size_t *l);

void				init_tty(void);

void				uninit_tty(void);

extern t_sh			g_sh;

#endif
