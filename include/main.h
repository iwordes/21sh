/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:23:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 20:16:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <unistd.h>

# include <libft.h>
# include <libfs.h>

# define MGUARD(M) if ((M) == NULL) exit(255)

/*
** =============================================================================
** Structs - Input
*/

typedef struct	s_inkey
{
	char		*key;
	void		(*fn)(t_in*);
}				t_inkey;

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
	int32_t		s;

	uint32_t	x;
	uint32_t	y;

	bool		eot;
	bool		cancel;
	bool		submit;
}				t_in;

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
	t_tk		*head;
	t_tk		*tail;
}				t_ps;

typedef struct	s_main
{
	char		**env;
	size_t		env_len;

	uint32_t	w;
	uint32_t	x;
	uint32_t	y;
}				t_main;

/*
** =============================================================================
** Input
*/

char			*input(void);

void			in_left(t_in *in);
void			in_right(t_in *in);

void			in_skip_left(t_in *in);
void			in_skip_right(t_in *in);

void			in_home(t_in *in);
void			in_end(t_in *in);

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

#endif
