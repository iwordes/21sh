/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:05:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 11:22:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
static char	*g_patt[] =
{
	"",

	"\x1",
	"\x2",
	"\x3",
	"\x4",

	"\n",
	"\r",
	"\b",
	"\x7f",
	"\e[A",
	"\e[B",
	"\e[C",
	"\e[D",
	TM_HOME,
	TM_END,
	NULL
};

static void	(*g_fn[])(char**, size_t*, size_t*) =
{
	in_eot,

	in_home,
	in_left,
	in_reset,
	in_eot,

	in_enter,
	in_enter,
	in_bksp,
	in_bksp,
	in_up,
	in_down,
	in_right,
	in_left,
	in_home,
	in_end
};

static void	in_it(t_in *in, const char *prompt)
{
	in->q = 0;
	in->x = 0;
	in->y = 0;
	in->mem = 4;
	MGUARD(in->ln = ft_memalloc(sizeof(t_inln) * 5));
	in->ps1 = env_get_safe("PS1");
	in->ps2 = env_get_safe("PS2");
	in->ps1_len = ft_strlen(in->ps1);
	in->ps2_len = ft_strlen(in->ps2);
	in->ret = false;
	tm_cur_save();
}

static void	in_grow(t_in *in)
{
	char	*new_put;

	if (in->i < in->m)
		return ;
	while (in->m <= in->i)
		in->m *= 2;
	MGUARD(new_put = ft_strnew(in->m));
	ft_strcpy(new_put, in->put);
	free(in->put);
	in->put = new_put;
}

static void	in_sert(t_in *in, char *buff)
{
	in_grow(in);
	ft_strins(in->put, buff, in->i);
	in->x += ft_strlen(buff);
}

char	*input(void)
{
	char	buff[8];
	t_in	in;
	int		i;

	in_it(&in);
	while ((*(uint64_t*)buff = 0) || read(0, buff, 7) >= 0)
	{
		p = ~0;
		while (g_patt[p += 1] != NULL)
			if (ft_strequ(g_patt[p], buff))
			{
				g_fn[p](&in);
				if (in.ret)
					return (in_join(&in));
				break ;
			}
		if (g_patt[p] != NULL || ft_strlen(buff) != 1)
			continue ;
		in_sert(&in, buff);
		in_print(&in);
	}
	in_dest(&in);
	return (NULL);
}
*/

/*
** Cheap placeholder for the real input().
*/

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
