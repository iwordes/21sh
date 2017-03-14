/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:40:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 22:01:26 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Navigate to the start of the current line.
*/

#define LEN (in->ln[in->y].ps_len + in->x)

// Will this always work?

bool	in_sol(t_in *in)
{
	int		x;
	int		y;

	x = -LEN % g_sh.cols;
	y = -LEN / g_sh.cols;
	g_sh.cx += x;
	g_sh.cy += y;
	tm_gotor(x, y);
	return (false);
}
