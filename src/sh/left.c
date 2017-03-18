/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:11:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/16 16:37:39 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	sh_left(void)
{
	if (g_sh.cx != 0)
		tm_left();
	else
	{
		tm_gotor(g_sh.cols - 1, -1);
		g_sh.cx = g_sh.cols;
		g_sh.cy -= 1;
	}
	g_sh.cx -= 1;
}
