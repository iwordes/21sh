/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:58:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 11:35:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void	sig_1(void)
{
	// Signals 1-15
}

void	init_sig(void)
{
	sig_1();
	signal(SIGHUP, sig_hup);
	signal(SIGINT, sig_int);
	signal(SIGQUIT, sig_quit);
	signal(SIGILL, sig_ill);
	signal(SIGTRAP, sig_trap);
	signal(SIGABRT, sig_abrt);
	signal(SIGEMT, sig_emt);
	signal(SIGFPE, sig_fpe);
	signal(SIGBUS, sig_bus);
	signal(SIGSEGV, sig_segv);
	signal(SIGSYS, sig_sys);
	signal(SIGPIPE, sig_pipe);
	signal(SIGALRM, sig_alrm);
	signal(SIGTERM, sig_term);
	signal(SIGURG, sig_urg);
	signal(SIGTSTP, sig_tstp);
	signal(SIGCONT, sig_cont);
	signal(SIGCHLD, sig_chld);
	signal(SIGTTIN, sig_ttin);
	signal(SIGTTOU, sig_ttou);
}
