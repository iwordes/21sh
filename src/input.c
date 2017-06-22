/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:28:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 10:24:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static t_inkey	g_key[] =
{
	{ "\t", in_tab },
	{ "\n", in_submit },
	{ "\r", in_submit },
	{ "\r\n", in_submit },

	{ "\x03", in_ctrl_c },
	{ "\x04", in_ctrl_d },
	{ "\x16", in_ctrl_v },
	{ "\x18", in_ctrl_x },

	{ "\x7f", in_delete },
	{ "\e[3~", in_delete },

	{ "\e[A", in_line_up },
	{ "\e[B", in_line_down },
	{ "\e[C", in_line_right },
	{ "\e[D", in_line_left },

	{ "\e[F", in_end },
	{ "\e[H", in_home },

	{ "\e[1;2C", in_sel_right },
	{ "\e[1;2D", in_sel_left },

	{ "\e\e[C", in_skip_right },
	{ "\e\e[D", in_skip_left }
};

#define G_KEY_LEN (sizeof(g_key) / sizeof(t_inkey))

/*
** 1. Init buffer.
** 2. While there are keys to read...
** 2a. If the key has special handling, use it.
** 2b. Otherwise, insert the buffer into our current line.
** 3. If a handler set any EOI flag, exit the loop.
*/

static void		in_loop_(t_in *in)
{
	char	buff[9];
	uint8_t	i;

	ft_bzero(buff, 9);
	while (read(0, buff, 8) > 0)
	{
		i = ~0;
		while (++i < G_KEY_LEN)
			if (ft_strequ(g_key[i].key, buff))
			{
				g_key[i].fn(in);
				break ;
			}
		if (i == G_KEY_LEN && buff[0] != '\e')
			in_sert(in, buff);
		if (in->eot || in->cancel || in->submit)
			return ;
		*(uint64_t*)buff = 0;
	}
}

char			*input(void)
{
	t_in		in;

	if (!in_init(&in))
		return (NULL);
	in_loop_(&in);
	in_uninit(&in);
	if (in.submit)
		in_hist_add(&in);
	return (in.line);
}
