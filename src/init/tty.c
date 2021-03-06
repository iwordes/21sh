/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:00:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 14:55:04 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	init_tty(void)
{
	S_WINSIZE	ws;

	if (tcgetattr(0, &g_mn.tm_cfg) == -1)
		exit(31);
	g_mn.tm = g_mn.tm_cfg;
	g_mn.tm.c_iflag = 0;
	g_mn.tm.c_oflag = OPOST | ONLCR;
	g_mn.tm.c_lflag = 0;
	g_mn.tm.c_cc[VMIN] = 1;
	g_mn.tm.c_cc[VTIME] = 0;
	if (ioctl(1, TIOCGWINSZ, &ws))
		exit(33);
	g_mn.w = ws.ws_col;
}
