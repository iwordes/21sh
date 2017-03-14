/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:01:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 19:06:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Safely move the cursor left one character, wrapping
*/

bool	in_left(t_in *in)
{
	if (in->x == 0)
		return (false);
	if (g_sh.cx == 0)
	{
		g_sh.cx = g_sh.cols - 1;
		tm_gotor(-1, g_sh.cx);
		g_sh.cy -= 1;
	}
	else
	{
		tm_left();
		g_sh.cx -= 1;
	}
	in->x -= 1;
	return (false);
}
