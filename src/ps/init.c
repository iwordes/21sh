/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:28:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/15 15:19:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	ps_init(t_ps *ps)
{
	bzero(ps, sizeof(t_ps));
	if ((ps->tk = ZALT(t_tk, 64)) == NULL)
		return (false);
	if ((ps->exe = ZALT(t_exe, 1)) == NULL)
		return (false);
	ps->tk_mem = 64;
	ps->exe_mem = 1;
	return (true);
}
