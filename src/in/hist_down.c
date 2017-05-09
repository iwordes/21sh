/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:38:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/20 19:17:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define LN in->ln[in->y]

// TODO THIS
bool	in_hist_down(t_in *in)
{
	if (/* ... */)
		return (false);
	// ...
	if (g_sh.hi == g_sh.hist_len)
		g_sh.hist_cache = LN.ln;
	else
		free(LN.ln);
	g_sh.hi += 1;
	if (g_sh.hi == g_sh.hist_len)
		LN.ln = g_sh.hist_cache;
	else
		MGUARD(LN.ln = ft_strdup(g_sh.hist[g_sh.hi]));
	ln
	in_print(in);
	in_goto(in, in->ln[in->y].ln_len - 1, in->y);
	return (false);
}
