/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:28:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 11:49:19 by iwordes          ###   ########.fr       */
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

	{ "\n", in_submit },
	{ "\r", in_submit },
	{ "\r\n", in_submit },

	{ "\x03", in_ctrl_c },
	/*
	{ "\x04", in_ctrl_d },
	*/
	{ "\x16", in_ctrl_v },
	{ "\x18", in_ctrl_x },

	{ "\x7f", in_delete },
	{ "\e[3~", in_delete },

	/*
	{ "\e[A", in_hist_up },
	{ "\e[B", in_hist_down },
	*/

	{ "\e[C", in_line_right },
	{ "\e[D", in_line_left },

	/*
	{ "\e[...", in_line_up },
	{ "\e[...", in_line_down },
	*/

	{ "\e[1;2C", in_sel_right },
	{ "\e[1;2D", in_sel_left }

	/*
	{ "\e[...", in_skip_right },
	{ "\e[...", in_skip_left }
	*/
};

static void		input_init(t_in *in)
{
	ft_printf("\e[1;7m%%\e[0m%*c", g_sh.w - 1, '\r');
	g_mn.x = 0;
	g_mn.y = 0;
	ft_bzero(in, sizeof(t_in));
	MGUARD(in->ln = ZALT(t_inline, 1));
	in->ln[0].ps = env_get_safe("PS1");
	in->len = 1;
	in->mem = 1;
}

static void		input_loop(t_in *in)
{
	char	buff[9];

	ft_bzero(buff, 9);
	while (read(0, buff, 8) > 0)
	{
		i = ~0;
		while (++i < G_KEY_LEN)
			if (ft_strequ(g_key[i], buff))
			{
				g_key[i].fn(in);
				break ;
			}
		if (i == G_KEY_LEN && ft_strlen(buff) == 1)
			in_sert(in, buff);
		if (in->eot || in->cancel || in->submit)
			return ;
		*(uint64_t*)buff = 0;
	}
}

static void		input_unit(t_in *in)
{
	uint32_t	i;

	i = ~0;
	while (++i < in->len)
		len += LN.len;
	if (len != 0)
		MGUARD(in->line = ZALT(char, len));
	i = ~0;
	while (++i < in->len)
	{
		if (len != 0)
			ft_strcat(in->line, LN.ln);
		free(LN.ln);
	}
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
	return (in->line);
}
