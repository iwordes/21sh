/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:05:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/14 14:04:24 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Cheap placeholder for the real input().
*/
/*
char	*input(void)
{
	char	*in;

	if (ft_readln(0, &in) <= 0)
	{
		free(in);
		return (NULL);
	}
	return (in);
}
*/

char	*g_key[] =
{
	"",

	"\n",
	"\r",

	"\b",
	"\x7f",

	//"\e[A",
	//"\e[B",
	"\e[C",
	"\e[D",

	//"\e[H",
	//"\e[F",

	NULL
};

bool	(*g_fn[])(t_in*) =
{
	in_eot,

	in_return,
	in_return,

	in_del,
	in_del,

	//in_up,
	//in_down,
	in_right,
	in_left,

	//in_home,
	//in_end
};

static void	init_(t_in *in)
{
	MGUARD(in->ln = MALT(t_inln, 1));
	in->mem = 1;
	in->l = 1;
	in->x = 0;
	in->y = 0;
	in->q = NULL;
	in->ps1 = env_get_safe("PS1");
	in->ps2 = env_get_safe("PS2");
	in->ps1_len = ft_strlen(in->ps1);
	in->ps2_len = ft_strlen(in->ps2);
	MGUARD(in->ln->ln = ft_strnew(128));
	MGUARD(in->ln->ps = ft_strdup(in->ps1));
	in->ln->ps_len = in->ps1_len;
	in->ln->ln_len = 0;
	in->ln->mem = 128;
	g_sh.cx = in->ps1_len % g_sh.cols;
	g_sh.cy = in->ps1_len / g_sh.cols;
}

static char	*end_(t_in *in)
{
	char	*ln;
	size_t	i;

	i = 0;
	MGUARD(ln = ft_strnew(0));
	while (i < in->l)
	{
		MGUARD(ln = ft_strdjoin(ln, in->ln[i].ln));
		free(in->ln[i].ps);
		free(in->ln[i].ln);
		free(in->ln + i);
		i += 1;
	}
	in_eoi(in);
	tm_nextln();
	// TODO: Append (flat) line to history
	return (ln);
}

// If issues occur with live-reading, invert the lookup table and pattern-search
// each buffer.

#define ZEROBUF (*(uint64_t*)buff = 0)

char		*input(void)
{
	char	buff[8];
	t_in	in;
	size_t	k;

	init_(&in);
	while (ZEROBUF || read(0, buff, 7) >= 0)
	{
		k = ~0;
		while (g_key[k += 1] != NULL)
			if (ft_strequ(g_key[k], buff))
			{
				if (g_fn[k](&in))
					return (end_(&in));
				break;
			}
		if (g_key[k] == NULL && buff[1] == 0)
			in_sert(&in, buff);
	}
	return (end_(&in));
}
