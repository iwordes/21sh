/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eoi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:47:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 15:03:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Navigate to the end of input.
*/

#define LN (in->ln[i])

int		sum_lines(t_in *in)
{
	size_t	i;
	int		l;

	i = 0;
	l = 0;
	while (i < in->l)
	{
		l += LN.ps_len + LN.ln_len;
		l += g_sh.cols - (l % g_sh.cols);
		i += 1;
	}
	return (l);
}

bool	in_eoi(t_in *in)
{
	int		dx;
	int		dy;

	dx = sum_lines(in);
	dy = (dx / g_sh.cols) - g_sh.cy;
	dx = (dx % g_sh.cols) - g_sh.cx;
	in->y = in->l - 1;
	in->x = in->ln[in->y].ln_len - 1;
	g_sh.cx += dx;
	g_sh.cy += dy;
	ft_eprintf("goto %d,%d\n", dx, dy);
	tm_gotor(dx, dy);
	return (false);
}
