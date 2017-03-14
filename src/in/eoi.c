/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eoi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:47:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 21:39:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Navigate to the end of input.
*/

#define LN (in->ln[y])

bool	in_eoi(t_in *in)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	in->y = in->l - 1;
	in->x = in->ln[in->y].ln_len - 1;
	while (y < in->l)
	{
		x += LN.ps_len + LN.ln_len;
		y += 1;
	}
	y += x / g_sh.cols;
	x %= g_sh.cols;
	tm_gotor(y - g_sh.cx, x - g_sh.cy);
	return (false);
}
