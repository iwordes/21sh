/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:45:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/22 18:20:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** 1. Discard whitespace.
** 2. Identify known types.
**
** Notes:
** - Special parsing is disabled within quotes.
*/

t_pscan		g_scan[] =
{
	{ TKT_PIPE, ps_is_pipe },
	{ TKT_SEMI, ps_is_semi },
	{ TKT_R_O1, ps_is_ro1 },
	{ TKT_R_O2, ps_is_ro2 },
	{ TKT_R_I1, ps_is_ri1 },
	{ TKT_R_I2, ps_is_ri2 },
	{ TKT_NONE, NULL }
};

#define LN (*ln)
#define TK ps->tk[ps->tk_len]
#define SPACE(C) ft_isspace(C)
#define QUOTE(C) (C == '\'' || C == '\"')
#define DELIM(C) (C == 0 || QUOTE(C) || C == ';' || C == '|' || SPACE(C))

static bool	qloop_(t_ps *ps, const char **ln, uint32_t *i, char *q)
{
	*q = *LN;
	LN += 1;
	TK.type = TKT_QUOT;
	if (*q == '\"')
		TK.flag |= TKF_VAR;
	while (LN[*i] && LN[*i] != *q)
		*i += 1 + (LN[*i] == '\\' && LN[*i + 1] == *q);
	return (LN[*i] == *q);
}

static bool	loop_(t_ps *ps, const char **ln)
{
	uint32_t	i;
	char		q;

	q = 0;
	i = 0;
	if (ps->tk_len == ps->tk_mem)
	{
		MGUARD(DRALT(ps->tk, t_tk, ps->tk_mem * 2, ps->tk_mem));
		bzero(ps->tk + ps->tk_mem, ps->tk_mem * sizeof(t_tk));
	}
	if (*LN == ';' || *LN == '|')
		i = 1;
	else if (QUOTE(LN[i]) && !qloop_(ps, ln, &i, &q))
		return (false);
	else
		while (LN[i])
		{
			if (LN[i] == '\\')
				i += 1;
			i += (LN[i] != 0);
			if (DELIM(LN[i]))
				break ;
		}
	MGUARD(TK.str = ft_strsub(LN, 0, i - (q != 0)));
	LN += i;
	return (true);
}

/*
** TODO: Break at end of /[0-9]*(<<?|>>?)/
** TODO: Heredoc handling
*/

bool		ps_tokens(t_ps *ps, const char *ln)
{
	uint32_t	i;

	while (*ln)
	{
		ITER(ln, ft_isspace(*ln));
		if (*ln == 0)
			break ;
		if (!loop_(ps, &ln))
			return (false);

		i = ~0;
		if (TK.type == TKT_NONE)
		{
			while (g_scan[++i].fn)
				if (g_scan[i].fn(TK.str))
					break ;
			TK.type = g_scan[i].type;
			if (TK.type == TKT_NONE)
				TK.flag |= TKF_VAR | TKF_EXP;
			if (TK.type == TKT_R_I2 && !ps_tokens_ri2(ps, ln, &i))
				return (false);
		}

		ps->tk_len += 1;
		if (!SPACE(*ln))
			TK.flag |= TKF_ADJ;
	}
	return (true);
}
