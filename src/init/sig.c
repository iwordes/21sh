/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:07:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/25 16:35:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** static void	sig_none(int sig)
** {
** 	(void)sig;
** }
*/

static void	sig_winch(int sig)
{
	struct winsize	ws;
	uint32_t		i;

	signal(SIGWINCH, SIG_IGN);
	ioctl(1, TIOCGWINSZ, &ws);
	i = g_mn.w * g_mn.y + g_mn.x;
	g_mn.w = ws.ws_col;
	g_mn.x = i / g_mn.w;
	g_mn.y = i % g_mn.w;
	signal(SIGWINCH, sig_winch);
	(void)sig;
}

static void	sig_nal(int sig)
{
	(void)sig;
}

void		init_sig(void)
{
	uint8_t	sig;

	sig = 1;
	while (sig < 32)
		signal(sig, sig_nal);
	signal(SIGWINCH, sig_winch);
}
