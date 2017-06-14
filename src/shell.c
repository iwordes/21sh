/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:55:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/13 18:52:01 by iwordes          ###   ########.fr       */
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

	ft_putstr("\e[95mpls_pipe\e[0m\n");
	while (PS.pipe)
	{
		if (pipe(p))
		{
			ft_putstr("\e[91mpls_pipe\e[0m\n");
			return (false);
		}
		fd_close(P_STDOUT);
		fd_close(P_STDIN);
		P_STDOUT = p[1];
		P_STDIN = p[0];

		ft_printf("  %u \e[92m|\e[0m %u\n", i, i + 1);

		i += 1;
	}

	ft_putstr("\e[92mpls_pipe\e[0m\n");
	return (true);
}

static bool		pls_exec(t_ps *ps, uint32_t i)
{
	while (1)
	{
		if (!sh_meta_builtin(ps, i))
			if (!sh_meta_exec(ps, i))
				return (false);
		if (PS.pid < 0)
			return (false);
		BREAKIF(!PS.pipe);
		i += 1;
	}
	return (true);
}

static void		pls_wait(t_ps *ps, uint32_t i)
{
	while (1)
	{
		fd_close(PS.fd[0]);
		fd_close(PS.fd[1]);
		fd_close(PS.fd[2]);
		if (PS.pid > 0)
			waitpid(PS.pid, NULL, 0);

		ft_printf("  [\e[92m%u\e[0m] %d "
			"(\e[1m%d\e[0m, \e[1m%d\e[0m, \e[1;91m%d\e[0m)\n",
			i, PS.pid, PS.fd[0], PS.fd[1], PS.fd[2]);

		BREAKIF(!PS.pipe);
		i += 1;
	}
}

bool			shell(t_ps *ps)
{
	uint32_t	i;

	i = ~0;
	while (++i < ps->exe_len)
	{
		ITER(i, i < ps->exe_len && PS.argv_len == 0);
		BREAKIF(i >= ps->exe_len);
		if (!pls_pipe(ps, i))
			PANIC();
		if (!pls_exec(ps, i))
			PANIC();
		pls_wait(ps, i);
		ITER(i, PS.pipe);
	}
	return (true);
}
