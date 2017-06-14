/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:50:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/14 10:51:22 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define EXE ps->exe[j]
#define ARG EXE.argv

bool	parse(t_ps *ps, const char *in)
{
	if (!ps_init(ps))
		return (false);
	if (!ps_tokens(ps, in))
		return (false);
	if (!ps_vars(ps))
		return (false);
	if (!ps_home(ps))
		return (false);
	if (!ps_escape(ps))
		return (false);
	if (!ps_proc(ps))
		return (false);
	ps_uninit(ps);
	return (true);
}
