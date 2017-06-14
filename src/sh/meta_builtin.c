/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:50:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/13 18:51:04 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_bi	g_bi[] =
{
	{ "cd", sh_cd },
	{ "env", sh_env },
	{ "echo", sh_echo },
	{ "exit", sh_exit },
	{ "setenv", sh_setenv },
	{ "unsetenv", sh_unsetenv }
};

void	*find_(const char *bi)
{
	uint8_t		i;

	i = ~0;
	while (g_bi[++i].fn)
		if (ft_strequ(bi, g_bi[i].cmd))
			return (g_bi[i].fn);
	return (NULL);
}

/*
** 0: No such builtin.
** 1: Success.
** 2: Error.
*/

#define FD exe->fd
#define EXE ps->exe[i]

static void	init_(t_ps *ps, uint32_t i, int spare[3])
{
	spare[0] = dup(0);
	spare[1] = dup(1);
	spare[2] = dup(2);
	dup2(EXE.fd[0], 0);
	dup2(EXE.fd[1], 1);
	dup2(EXE.fd[2], 2);
	fd_close(EXE.fd[0]);
	fd_close(EXE.fd[1]);
	fd_close(EXE.fd[2]);
	if (EXE.pipe)
	{
		i = ~0;
		while (++i < ps->exe_len)
		{
			fd_close(EXE.fd[0]);
			fd_close(EXE.fd[1]);
			fd_close(EXE.fd[2]);
		}
	}
}

static void	uninit_(t_exe *exe, int spare[3])
{
	if (exe->pipe)
		exit(0);
	dup2(spare[0], 0);
	dup2(spare[1], 1);
	dup2(spare[2], 2);
	close(spare[0]);
	close(spare[1]);
	close(spare[2]);
}

bool	sh_meta_builtin(t_ps *ps, uint32_t i)
{
	void	(*fn)(char**, int);
	int		spare[3];

	if ((fn = find_(EXE.argv[0])))
	{
		if (EXE.pipe && (EXE.pid = fork()))
			return (true);
		init_(ps, i, spare);
		fn(EXE.argv, EXE.argv_len);
		uninit_(&EXE, spare);
		return (true);
	}
	return (false);
}
