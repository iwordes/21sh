/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:19:16 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/20 14:52:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	sig_winch(int sig)
{
	struct winsize	w;
	int				i;

	signal(SIGWINCH, SIG_IGN);
	;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	i = (g_sh.cy * g_sh.cols) + g_sh.cx;
	g_sh.cols = w.ws_col;
	g_sh.cy = i / g_sh.cols;
	g_sh.cx = i % g_sh.cols;
	;
	signal(SIGWINCH, sig_winch);
	(void)sig;
}
