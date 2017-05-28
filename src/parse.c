/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:50:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/28 15:57:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define EXE ps->exe[j]
#define ARG EXE.argv

#define FAILIF(C) if (C) return (false);

bool	parse(t_ps *ps, const char *in)
{
	ft_printf("\e[1;95mi\e[0m \e[92m\"%s\"\e[0m\n", in);

	FAILIF(!ps_init(ps));
	FAILIF(!ps_tokens(ps, in));
	// FAILIF(!ps_var(ps));
	FAILIF(!ps_home(ps));
	// FAILIF(!ps_glob(ps));
	FAILIF(!ps_escape(ps));

	///
	for (uint32_t i = 0; i < ps->tk_len; i += 1)
		ft_printf("\e[1;93mt\e[0;1m {\e[0m \e[92m\"%s\"\e[0m, \e[94m%u\e[0m, \e[95m%u\e[0m \e[1m}\e[0m\n", ps->tk[i].str, ps->tk[i].flag, ps->tk[i].type);
	///

	FAILIF(!ps_proc(ps));

	///
	for (uint32_t j = 0; j < ps->exe_len; j += 1)
	{
		ft_printf("\e[1;92mx\e[0;1m {\e[0m\n    \e[1m%u/%u\e[0m: {\n", EXE.argv_len, EXE.argv_mem);
		for (uint32_t k = 0; k < ps->exe[j].argv_len; k += 1)
			ft_printf("        \e[92m\"%s\"\e[0m%s\n", EXE.argv[k], (k + 1 < EXE.argv_len) ? "," : "");
		ft_printf("    },\n    { \e[1m%d\e[0m, \e[1m%d\e[0m, \e[1;91m%d\e[0m },\n    \e[1;93m%s\e[0m\n", EXE.fd[0], EXE.fd[1], EXE.fd[2], ps->exe[j].pipe ? "true" : "false");
		ft_printf("  \e[1m}\e[0m\n");
	}
	write(1, "\n", 1);
	///

	ps_uninit(ps);
	return (true);
}
