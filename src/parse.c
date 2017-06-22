/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:50:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 10:46:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define EXE ps->exe[j]
#define ARG EXE.argv

/*
** 1. Init and allocate for the parsing struct.
** 2. Tokenize the input string.
** 3. Insert $HOME into any token that starts with '~'.
** 4. Parse variables within each token.
** 5. Process escape characters within each token.
** 6. Convert tokens into an array of t_exe structs.
** 7. Clean up, and free memory.
*/

bool	parse(t_ps *ps, const char *in)
{
	if (!ps_init(ps))
		return (false);
	if (!ps_tokens(ps, in))
		return (false);
	if (!ps_home(ps))
		return (false);
	if (!ps_vars(ps))
		return (false);
	if (!ps_escape(ps))
		return (false);
	if (!ps_proc(ps))
		return (false);
	ps_uninit(ps);
	return (true);
}
