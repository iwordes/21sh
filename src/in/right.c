/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:33:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/15 14:47:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

bool	in_right(t_in *in)
{
	if (in->x == in->ln[in->y].ln_len)
		return (false);
	g_sh.cx += 1;
	in->x += 1;
	if (g_sh.cx != g_sh.cols)
		tm_right();
	else
	{
		write(1, "\r\n", 2);
		g_sh.cy += 1;
		g_sh.cx = 0;
	}
	return (false);
}
