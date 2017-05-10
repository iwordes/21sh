/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:00:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 13:32:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	init_tty(void)
{
	S_TERMIOS	tio;
	S_WINSIZE	ws;

	if (tcgetattr(0, &g_mn.tm_cfg) == -1)
		exit(31);
	tio = g_mn.tm_cfg;
	tio.c_iflag = 0;
	tio.c_oflag = OPOST | ONLCR;
	tio.c_lflag = 0;
	tio.c_cc[VMIN] = 1;
	tio.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &tio) == -1)
		exit(32);
	if (ioctl(1, TIOCGWINSZ, &ws))
		exit(33);
	g_mn.w = ws.ws_col;
}
