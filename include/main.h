/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:23:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 15:37:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <unistd.h>

# include <libft.h>
# include <libfs.h>

# define MGUARD(M) if ((M) == NULL) exit(255)

typedef void	(*t_infn)(t_in*);

/*
** =============================================================================
** Structs
*/

typedef struct	s_in
{
	char		*line;

	char		**ln;
	char		**ps;
	uint32_t	ln_cnt;
	uint32_t	ln_mem;
	uint32_t	ps_mem;

	uint32_t	x;
	uint32_t	y;
}				t_in;

typedef struct	s_inkey
{
	char		*key;
	t_infn		fn;
}				t_inkey;

typedef struct	s_inq
{
	char		*s;
	char		*e;
}				t_inq;

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
