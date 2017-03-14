/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:44:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 22:54:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define LN in->ln[0]

bool	in_soi(t_in *in)
{
	int		dx;
	int		dy;

	dx = (LN.ps_len % g_sh.cols) - g_sh.cx;
	dy = (LN.ps_len / g_sh.cols) - g_sh.cy;
	in->x = 0;
	in->y = 0;
	g_sh.cx += dx;
	g_sh.cy += dy;
	tm_gotor(dx, dy);
	return (false);
}
