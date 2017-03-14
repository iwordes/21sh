/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:40:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 22:40:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Navigate to the start of the current line.
*/

#define LN (in->ln[in->y])

#define BX ((LN.ps_len + in->x) % g_sh.cols)
#define BY ((LN.ps_len + in->x) / g_sh.cols)
#define EX ((LN.ps_len) % g_sh.cols)
#define EY ((LN.ps_len) / g_sh.cols)

// This probably turned rather redunant. Worth investigating.

bool	in_sol(t_in *in)
{
	int		dx;
	int		dy;

	dx = EX - BX;
	dy = EY - BY;
	in->x = LN.ln_len - 1;
	g_sh.cx += dx;
	g_sh.cy += dy;
	tm_gotor(dx, dy);
	return (false);
}