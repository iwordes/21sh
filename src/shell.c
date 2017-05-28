/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:55:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/28 13:36:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define PS ps->exe[i]
#define FD(N) ((PS.fd[N] > 2) ? PS.fd[N] : -1)
#define FAIL(E) { g_mn.err = E; return (false); }
#define PANIC(E) return (panic_(ps, pid, pl))

static bool		panic_(t_ps *ps, pid_t pid[128], uint8_t pid_len)
{
	uint32_t	i;

	i = ~0;
	while (++i < pid_len)
		if (pid[i] > 0)
			kill(pid[i], SIGKILL);
	i = ~0;
	while (++i < ps->exe_len)
	{
		close(FD(0));
		close(FD(1));
		close(FD(2));
	}
	return (false);
}

static bool		pls_exec(t_ps *ps, pid_t pid[128], uint32_t *i, uint8_t *p)
{
	*p = 0;
	while (1)
	{
		if (*p >= 128)
			FAIL("Too many processes in pipeline.");
		if (!sh_meta_builtin(ps->exe + *i, &pid[*p]))
			pid[*p] = sh_meta_exec(ps->exe + *i);
		if (pid[*p] < 0)
		{
			ft_printf("  [\e[91m%u\e[0m]\n", *i);
			return (false);
		}

		ft_printf("  [\e[92m%u\e[0m]\n", *i);

		*p += 1;
		BREAKIF(!ps->exe[*i].pipe);
		*i += 1;
	}
	return (true);
}

#define EX ps->exe[i - pl + p + 1]
#define EX2 ps->exe[i - pl + p + 2]

static void		pls_wait(t_ps *ps, pid_t pid[128], uint32_t i, uint8_t pl)
{
	uint8_t		p;

	p = ~0;
	while (++p + 1 < pl)
	{

		if (pid[p] > 0)
			waitpid(pid[p], NULL, 0);
		close((EX.fd[0] > 2) ? EX.fd[0] : -1);
		close((EX.fd[1] > 2) ? EX.fd[1] : -1);
		close((EX.fd[2] > 2) ? EX.fd[2] : -1);
		close((EX.pipe) ? EX2.fd[0] : -1);

		ft_printf("  [\e[92m%u\e[0m] %d (%d, %d, %d)\n",
			p, pid[p], EX.fd[0], EX.fd[1], EX.fd[2]);
	}

	ft_printf("  [\e[1m%u\e[0m] %d (%d, %d, %d)\n",
		pl - 1, pid[pl - 1], EX.fd[0], EX.fd[1], EX.fd[2]);

	if (pid[pl - 1] > 0)
		waitpid(pid[pl - 1], NULL, 0);

	ft_printf("  [\e[1;92m%u\e[0m] %d\n", pl - 1, pid[pl - 1]);
}

static void		pls_stop(pid_t pid[128], uint8_t l)
{
	uint8_t		i;

	i = ~0;
	while (++i + 1 < l)
		if (pid[i] > 0)
			kill(pid[i], 9);
}

bool			shell(t_ps *ps)
{
	pid_t		pid[128];
	uint8_t		pl;
	uint32_t	i;

	i = ~0;
	if (ps->exe[0].argv_len == 0)
		return (true);
	while (++i < ps->exe_len)
	{
		if (!sh_meta_pipe(ps, i))
			PANIC();
		ft_putstr("[ \e[92mOK\e[0m ] pipe\n");
		if (!pls_exec(ps, pid, &i, &pl))
			PANIC();
		ft_putstr("[ \e[92mOK\e[0m ] exec\n");
		pls_wait(ps, pid, i, pl);
		ft_putstr("[ \e[92mOK\e[0m ] wait\n");
		pls_stop(pid, pl);
		ft_putstr("[ \e[92mOK\e[0m ] stop\n");
	}
	return (true);
}
