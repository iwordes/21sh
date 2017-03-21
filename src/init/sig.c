/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:58:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/20 19:07:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define IGN(S) (S == 16 || S == 19 || S == 20 || S == 23 || S == 28 || S == 29)

static void	auto_end(void)
{
	size_t	i;

	i = 1;
	while (i < 32)
	{
		if (!IGN(i) && i != SIGKILL && i != SIGSTOP)
			signal(i, sig_end);
		i += 1;
	}
}

static void	auto_ign(void)
{
	size_t	i;

	i = 1;
	while (i < 32)
	{
		if (IGN(i) && i != SIGKILL && i != SIGSTOP)
			signal(i, SIG_IGN);
		i += 1;
	}
}

void	init_sig(void)
{
	auto_end();
	auto_ign();
	signal(SIGWINCH, sig_winch);
}
