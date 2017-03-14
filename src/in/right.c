/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:33:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 19:08:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

bool	in_right(t_in *in)
{
	if (in->x + 1 == in->ln[in->y].ln_len)
		return (false);
	if (g_sh.cx + 1 == g_sh.cols)
	{
		tm_nextln();
		g_sh.cy += 1;
		g_sh.cx = 0;
	}
	else
	{
		tm_right();
		g_sh.cx += 1;
	}
	in->x += 1;
	return (false);
}
