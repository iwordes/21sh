/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:02:00 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 22:38:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define LN (in->ln[in->y])

#define BX ((LN.ps_len + in->x) % g_sh.cols)
#define BY ((LN.ps_len + in->x) / g_sh.cols)
#define EX ((LN.ps_len + LN.ln_len) % g_sh.cols)
#define EY ((LN.ps_len + LN.ln_len) / g_sh.cols)

// This probably turned rather redunant. Worth investigating.

bool	in_eol(t_in *in)
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
