/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:50:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/15 16:39:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool			parse(t_ps *ps, const char *in)
{
	if (!ps_init(ps))
		return (false);
	if (!ps_tokens(ps, in))
		return (false);

	//if (!ps_escape(ps))
	//	return (false);

	//if (!ps_proc(ps))
	//	return (false);

	// ps_unit(ps);
	return (true);
}
