/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_delim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:26:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 11:00:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define E ps->exe[ps->exe_mem + i]
#define TK ps->tk[*t]
#define EXE ps->exe[ps->exe_len]
#define ARG EXE.argv[EXE.argv_len]

static bool	grow_exe(t_ps *ps)
{
	uint32_t	i;

	if (ps->exe_len + 1 == ps->exe_mem)
	{
		i = 0;
		if (DRALT(ps->exe, t_exe, ps->exe_mem * 2, ps->exe_mem) == NULL)
			PSFAIL("Allocation failure: ps_proc_delim/grow_exe 1");
		bzero(ps->exe + ps->exe_mem, ps->exe_mem * sizeof(t_exe));
		while (i < ps->exe_mem)
		{
			if ((E.argv = ZALT(char*, 4)) == NULL)
				PSFAIL("Allocation failure: ps_proc_delim/grow_exe 2");
			bzero(E.argv, sizeof(char*) * 4);
			E.argv_mem = 4;
			E.fd[1] = 1;
			E.fd[2] = 2;
			i += 1;
		}
		ps->exe_mem *= 2;
	}
	return (true);
}

/*
** 1. Error check when delimiting with a pipe.
** 2. If necessary, allocate more memory for our `t_exe` array.
** 3. Increment the length of the array by one.
** 4. Advance forward by one token.
*/

bool		ps_proc_delim(t_ps *ps, uint32_t *t)
{
	if (TK.type == TKT_PIPE)
	{
		if (EXE.argv_len == 0)
			PSFAIL("Pipe from nowhere.");
		if (*t + 1 == ps->tk_len)
			PSFAIL("Pipe to nowhere.");
		EXE.pipe = true;
	}
	if (!grow_exe(ps))
		return (false);
	ps->exe_len += 1;
	*t += 1;
	return (true);
}
