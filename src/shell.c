/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:55:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/28 15:04:37 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define PS ps->exe[i]
#define FAIL(E) { g_mn.err = E; return (false); }
#define PANIC(E) return (panic_(ps, i))

static bool		panic_(t_ps *ps, uint32_t i)
{
	while (PS.pipe)
	{
		if (PS.pid > 0)
			kill(PS.pid, SIGKILL);
		fd_close(PS.fd[0]);
		fd_close(PS.fd[1]);
		fd_close(PS.fd[2]);
		BREAKIF(!PS.pipe);
		i += 1;
	}
	return (false);
}

#define FD(N) ps->exe[i + N].fd[!N]

#define P_STDOUT ps->exe[i].fd[1]
#define P_STDIN ps->exe[i + 1].fd[0]

static bool		pls_pipe(t_ps *ps, uint32_t i)
{
	int			p[2];

	while (PS.pipe)
	{
		if (pipe(p))
			return (false);
		fd_close(P_STDOUT);
		fd_close(P_STDIN);
		P_STDOUT = p[1];
		P_STDIN = p[0];
		i += 1;
	}
	return (true);
}

static bool		pls_exec(t_ps *ps, uint32_t i)
{
	while (1)
	{
		if (!sh_meta_builtin(ps->exe + i))
			sh_meta_exec(ps->exe + i);
		if (PS.pid < 0)
			return (false);
		BREAKIF(!PS.pipe);
		i += 1;
	}
	return (true);
}

/*
** NOTE: May need to use method 1: Wait for last proc, kill the rest
*/

static void		pls_wait(t_ps *ps, uint32_t i)
{
	while (PS.pipe)
	{
		fd_close(PS.fd[0]);
		fd_close(PS.fd[1]);
		fd_close(PS.fd[2]);

		if (PS.pid > 0)
			waitpid(PS.pid, NULL, 0);

		ft_printf("  [\e[92m%u\e[0m] %d (%d, %d, %d)\n",
			i, PS.pid, PS.fd[0], PS.fd[1], PS.fd[2]);

		i += 1;
	}

	fd_close(PS.fd[0]);
	fd_close(PS.fd[1]);
	fd_close(PS.fd[2]);

	ft_printf("  [\e[1m%u\e[0m] %d (%d, %d, %d)\n",
		i, PS.pid, PS.fd[0], PS.fd[1], PS.fd[2]);

	if (PS.pid > 0)
		waitpid(PS.pid, NULL, 0);

	ft_printf("  [\e[1;92m%u\e[0m] %d\n", i, PS.pid);
}

bool			shell(t_ps *ps)
{
	uint32_t	i;

	i = ~0;
	while (++i < ps->exe_len)
	{
		// 1. Skip runs of ;
		ITER(i, PS.argv_len == 0);
		BREAKIF(i >= ps->exe_len);

		ft_printf(":: %u ::\n", i);

		// 2. Initiate IPC
		ft_putstr("\e[95mpipe\e[0m\n");
		if (!pls_pipe(ps, i))
			PANIC();
		ft_putstr("\e[92mpipe\e[0m\n");

		// 3. Execute processes
		ft_putstr("\e[95mexec\e[0m\n");
		if (!pls_exec(ps, i))
			PANIC();
		ft_putstr("\e[92mexec\e[0m\n");

		// 4. Wait for processes
		ft_putstr("\e[95mwait\e[0m\n");
		pls_wait(ps, i);
		ft_putstr("\e[92mwait\e[0m\n");

		// 5. Skip
		ITER(i, PS.pipe);
	}
	return (true);
}
