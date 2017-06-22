/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:00:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 10:15:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** 1. Set the terminal to use our custom config.
** 2. Protect against using a partial line for input.
** 3. Allocate and setup our input struct.
** 4. Print the first prompt string.
** 5. Reset the virtual cursor position.
** 6. Link our input struct to our main one.
*/

bool	in_init(t_in *in)
{
	if (tcsetattr(0, TCSANOW, &g_mn.tm) == -1)
		return (false);
	ft_printf("\e[1;7m%%\e[0m%*c", g_mn.w - 1, '\r');
	ft_bzero(in, sizeof(t_in));
	MGUARD(in->ln = ZALT(t_inline, 1));
	MGUARD(in->ln[0].ln = ZALT(char, 128));
	in->ln[0].mem = 128;
	in->ln[0].ps = env_gets("PS1");
	in->ln[0].ps_len = ft_strlen(in->ln[0].ps);
	in->len = 1;
	in->mem = 1;
	ft_putstr(in->ln[0].ps);
	g_mn.x = in->ln[0].ps_len % g_mn.w;
	g_mn.y = in->ln[0].ps_len / g_mn.w;
	g_mn.h = ~0;
	g_mn.in = in;
	return (true);
}
