/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:28:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/22 15:02:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** Goals:
** 1. Allow intuitive line editing.
** 2. Allow editing of multiple lines.
**
** Additionally:
** 1. Manage input history.
** 2. Manage a clipboard, because we certainly don't live in a graphical age.
*/

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

	{ "\e[1;2C", in_sel_right },
	{ "\e[1;2D", in_sel_left },

	{ "\e\e[C", in_skip_right },
	{ "\e\e[D", in_skip_left }
};

#define G_KEY_LEN (sizeof(g_key) / sizeof(t_inkey))

static void		input_init(t_in *in)
{
	ft_printf("\e[1;7m%%\e[0m%*c", g_mn.w - 1, '\r');
	ft_bzero(in, sizeof(t_in));
	MGUARD(in->ln = ZALT(t_inline, 1));
	MGUARD(in->ln[0].ln = ZALT(char, 128));
	in->ln[0].mem = 128;
	// TODO: ENV(PS1)
	in->ln[0].ps = "$ ";
	in->ln[0].ps_len = ft_strlen(in->ln[0].ps);
	in->len = 1;
	in->mem = 1;
	ft_putstr(in->ln[0].ps);
	g_mn.x = in->ln[0].ps_len % g_mn.w;
	g_mn.y = in->ln[0].ps_len / g_mn.w;
	g_mn.h = ~0;
	g_mn.in = in;
}

static void		input_loop(t_in *in)
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

#define LN in->ln[i]

static void		input_unit(t_in *in)
{
	uint64_t	skip;
	uint64_t	len;
	uint32_t	i;

	g_mn.in = NULL;
	i = ~0;
	len = 0;
	skip = 0;
	while (++i < in->len)
	{
		len += LN.len + 1;
		skip += LN.ps_len + LN.len;
		skip += g_mn.w - (skip % g_mn.w);
	}
	i = ~0;
	MGUARD(in->line = ZALT(char, len));
	while (++i < in->len)
	{
		if (i > 0)
			ft_strcat(in->line, "\n");
		ft_strcat(in->line, LN.ln);
		free(LN.ln);
	}
	tm_goto(-g_mn.x, (skip / g_mn.w) - (g_mn.y + 1));
	write(1, "\n", 1);
	in_hist_del(in);
	free(in->clip);
	free(in->ln);
	if (in->submit)
		return ;
	free(in->line);
	in->line = (in->cancel) ? ZALT(char, 1) : NULL;
}

char			*input(void)
{
	t_in		in;

	input_init(&in);
	input_loop(&in);
	input_unit(&in);
	if (in.submit)
		in_hist_add(&in);
	return (in.line);
}
