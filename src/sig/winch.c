/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:19:16 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/14 13:52:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	sig_winch(int sig)
{
	int		i;

	i = (g_sh.cy * g_sh.cols) + g_sh.cx;
	g_sh.cols = tm_cols();
	g_sh.cy = i / g_sh.cols;
	g_sh.cx = i % g_sh.cols;
	(void)sig;
}
