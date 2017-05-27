/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:55:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 13:30:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define PS ps->exe[i]
#define PANIC(E) return (panic_(ps, pid, p, E))

static bool		panic_(t_ps *ps, pid_t pid[128], uint8_t pid_len, char *e)
{
	uint8_t		p;

	p = 0;
	while (p < pid_len)
	{
		if (pid[p] > 0)
			kill(pid[p], SIGKILL);
		p += 1;
	}
	if (e)
		g_mn.err = e;
	return (false);
	(void)ps;
}

static pid_t	exec_(t_exe *exe)
{
	pid_t	pid;

	pid = 0;
	if (sh_meta_builtin(exe, &pid))
		return (pid);
	return (sh_meta_exec(exe));
}

static bool		pipeto(t_ps *ps, uint32_t i)
{
	int		fd[2];

	if (PS.pipe)
	{
		if (pipe(fd))
			return (false);
		ps->exe[i].fd[1] = fd[1];
		ps->exe[i + 1].fd[0] = fd[0];
	}
	return (true);
}

/*
** NOTE: Probably needs more managerial work to properly handle pipelines.
*/

bool			shell(t_ps *ps)
{
	pid_t		pid[128];
	uint32_t	i;
	uint8_t		p;

	i = ~0;
	while (++i < ps->exe_len)
	{
		p = 0;
		while (1)
		{
			if (p == 128)
				PANIC("Too many processes in pipeline.");
			if (!pipeto(ps, i))
				PANIC("Could not create pipe.");
			if ((pid[p++] = exec_(ps->exe + i)) < 0)
				PANIC(NULL);
			BREAKIF(!PS.pipe);
			i += 1;
		}
		errno = 0;
		while (errno != ECHILD)
			waitpid(-1, NULL, 0);
	}
	return (true);
}
