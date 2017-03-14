/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:19:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 19:30:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** c_iflag:
** - Don't ignore break conditions.
** - Don't send a SIGINT when a break condition is detected.
** - Don't mark parity errors.
** - Don't strip the most significant bit from input bytes.
** - Don't convert newlines to carriage returns.
** - Don't ignore carriage returns.
** - Don't convert carriage returns to newlines.
** - Don't use start/stop input control.
**
** c_oflag:
** - Enable processing.
** - Interpret '\n' as "\r\n" (return cursor to beginning of line)
**
** c_lflag:
** - Disable echoing of input to terminal display
** - Disable echoing of newlines to terminal display
** - Disable canonical mode
** - Disable handling for Ctrl signaling
** - Disable special input handling
*/

void	init_tty(void)
{
	if (tcgetattr(0, &g_sh.tm_cfg_) == -1)
		exit(1);
	g_sh.tm_cfg = g_sh.tm_cfg_;
	g_sh.tm_cfg.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR
							| ICRNL | IXON);
	g_sh.tm_cfg.c_oflag = OPOST | ONLCR;
	g_sh.tm_cfg.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN);
	//g_sh.tm_cfg.c_cc[VTIME] = 0
	//g_sh.tm_cfg.c_cc[VMIN] = 1
//	if (tcsetattr(0, TCSANOW, &g_sh.tm_cfg) == -1)
//		exit(1);
	g_sh.cols = tm_cols();
}
