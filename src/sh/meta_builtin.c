/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:50:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/28 15:00:45 by iwordes          ###   ########.fr       */
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

static void	init_(t_exe *exe, int spare[3])
{
	spare[0] = dup(0);
	spare[1] = dup(1);
	spare[2] = dup(2);
	dup2(FD[0], 0);
	dup2(FD[1], 1);
	dup2(FD[2], 2);
	fd_close(FD[0]);
	fd_close(FD[1]);
	fd_close(FD[2]);
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

bool	sh_meta_builtin(t_exe *exe)
{
	void	(*fn)(char**, int);
	int		spare[3];

	if ((fn = find_(exe->argv[0])))
	{
		if (exe->pipe && (exe->pid = fork()))
			return (true);
		init_(exe, spare);
		fn(exe->argv, exe->argv_len);
		uninit_(exe, spare);
		return (true);
	}
	return (false);
}
