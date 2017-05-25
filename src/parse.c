/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:50:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/25 14:30:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define EXE ps->exe[j]
#define ARG EXE.argv

bool	parse(t_ps *ps, const char *in)
{
	ft_printf("\e[1;95m:\e[0m \e[92m\"%s\"\e[0m\n", in);

	if (!ps_init(ps))
		return (false);
	if (!ps_tokens(ps, in))
		return (false);
	if (!ps_home(ps))
		return (false);
	//if (!ps_wild(ps))
	//	return (false);
	if (!ps_escape(ps))
		return (false);

	///
	for (uint32_t i = 0; i < ps->tk_len; i += 1)
		ft_printf("\e[1;93m:\e[0;1m {\e[0m \e[92m\"%s\"\e[0m, \e[94m%u\e[0m, \e[95m%u\e[0m \e[1m}\e[0m\n", ps->tk[i].str, ps->tk[i].flag, ps->tk[i].type);
	///

	if (!ps_proc(ps))
		return (false);

	///
	for (uint32_t j = 0; j < ps->exe_len; j += 1)
	{
		ft_printf("\e[1;92m:\e[0;1m {\e[0m\n    \e[1m%u/%u\e[0m: {\n", EXE.argv_len, EXE.argv_mem);
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
