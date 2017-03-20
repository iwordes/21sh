/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:19:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/20 13:17:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** c_iflag:
** - Nothing.
**
** c_oflag:
** - Enable output processing.
** - Interpret '\n' as "\r\n" (return cursor to beginning of line)
**
** c_lflag:
** - Only enable signals (e.g. ^C)
**
** c_cc:
** - Don't wait for input.
** - Return at least 1 character (keypress?) at a time.
*/

void	init_tty(void)
{
	if (tcgetattr(0, &g_sh.tm_cfg_) == -1)
		exit(1);
	g_sh.tm_cfg = g_sh.tm_cfg_;
	g_sh.tm_cfg.c_iflag = 0;
	g_sh.tm_cfg.c_oflag = OPOST | ONLCR;
	g_sh.tm_cfg.c_lflag = 0; //ISIG;
	g_sh.tm_cfg.c_cc[VTIME] = 0;
	g_sh.tm_cfg.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSANOW, &g_sh.tm_cfg) == -1)
		exit(1);
	tm_init();
	g_sh.cols = tm_cols();
}
