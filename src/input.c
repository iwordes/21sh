/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:28:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 15:42:07 by iwordes          ###   ########.fr       */
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
	{ "\e[D", in_left },
	{ "\e[C", in_right },
};

static void		input_init(t_in *in)
{
	// % protection
	// ft_printf("\e[7m%%\e[0m%.*c\n", g_mn., ' ');

	
}

static void		input_loop(t_in *in)
{
	char	buff[8];

	while (read(0, buff, 8) >= 0)
	{
		// ...
	}
}

static void		input_unit(t_in *in)
{
	// 1. Join lines
	// 2. Free lines
	// 3. ???
}

char			*input(void)
{
	t_in		in;

	input_init(&in);
	input_loop(&in);
	input_unit(&in);
	return (in->line);
}
