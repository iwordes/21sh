/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:55:49 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 10:58:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define E ps->exe[i]
#define TK ps->tk[t]
#define EXE ps->exe[ps->exe_len]
#define ARG EXE.argv[EXE.argv_len]

static bool	init_(t_ps *ps)
{
	uint32_t	i;

	i = 0;
	while (i < ps->exe_mem)
	{
		if ((E.argv = ZALT(char*, 4)) == NULL)
			PSFAIL("Allocation failure: ps_proc/init_");
		E.argv_mem = 4;
		E.fd[0] = 0;
		E.fd[1] = 1;
		E.fd[2] = 2;
		i += 1;
	}
	return (true);
}

/*
** 1. Allocate and initialize each t_exe.
** 2. For each token...
** 2a. Identify and process the token.
** 2b. If processing failed, cleanup and exit. (failure)
** 3. Increment the final number of t_exes in our array to match the real one.
*/

bool		ps_proc(t_ps *ps)
{
	uint32_t	t;
	bool		o;

	t = 0;
	if (!init_(ps))
		return (false);
	while (t < ps->tk_len)
	{
		if (TK.type >= TKT_R_O1 && TK.type <= TKT_R_I2)
			o = ps_proc_redir(ps, &t);
		else if (TK.type == TKT_PIPE || TK.type == TKT_SEMI)
			o = ps_proc_delim(ps, &t);
		else
			o = ps_proc_plain(ps, &t);
		if (!o)
		{
			ps_uninit(ps);
			return (false);
		}
	}
	ps->exe_len += 1;
	return (true);
}
