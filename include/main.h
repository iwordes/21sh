/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:23:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 19:19:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <unistd.h>

# include <libft.h>

# define MGUARD(M) if ((M) == NULL) exit(255)

# define S_TERMIOS struct termios
# define S_WINSIZE struct winsize

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
	char		*line;

	t_inline	*ln;
	uint32_t	len;
	uint32_t	mem;

	char		*clip;
	int64_t		s;

	uint32_t	x;
	uint32_t	y;

	bool		eot;
	bool		cancel;
	bool		submit;
}				t_in;

typedef struct	s_inkey
{
	char		*key;
	void		(*fn)(t_in*);
}				t_inkey;

/*
** =============================================================================
** Structs
*/

typedef struct	s_bi
{
	char		*cmd;
	int			(*fn)(char**);
}				t_bi;

typedef struct	s_ps
{
	//t_tk		*head;
	//t_tk		*tail;

	size_t		i;
}				t_ps;

typedef struct	s_main
{
	char		**env;
	size_t		env_mem;

	uint32_t	w;
	uint32_t	x;
	uint32_t	y;

	S_TERMIOS	tm_cfg;
}				t_main;

/*
** =============================================================================
** Environment
*/

bool			env_grow();

bool			env_del(const char *key);
char			*env_get(const char *key);
char			*env_gets(const char *key);
bool			env_set(const char *keyval);
bool			env_setkv(const char *key, const char *val);

/*
** =============================================================================
** Input
*/

void			in_redraw(t_in *in);

void			in_sert(t_in *in, char *buff);

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

// ...

/*
** =============================================================================
** Execution
*/

// ...

/*
** =============================================================================
** Main
*/

void			init(void);
void			loop(void);
char			*input(void);
/*
bool			parse(t_ps *ps, const char *in);
void			shell(t_ps *ps);
*/
void			uninit(void);

void			init_env(void);
void			init_sig(void);
void			init_tty(void);

extern t_main	g_mn;

#endif
