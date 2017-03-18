/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 11:20:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 11:38:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Internal function for navigating the input feed.
*/

#define LN (in->ln[i])
#define DX (c % g_sh.cols)
#define DY (c / g_sh.cols)

void	in_goto(t_in *in, int x, int y)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while ((size_t)i < in->l)
	{
		c += LN.ps_len;
		if (i != y)
		{
			c += LN.ln_len;
			c += g_sh.cols - DX;
		}
		else
		{
			c += MIN(LN.ln_len, x);
			break;
		}
		i += 1;
	}
	in->x = x;
	in->y = y;
	tm_gotor(DX - g_sh.cx, DY - g_sh.cy);
	g_sh.cx = DX;
	g_sh.cy = DY;
}
