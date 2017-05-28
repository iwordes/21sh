/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:45:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 19:02:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

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
	{
		if (LN[*i] == '\\')
			*i += 1;
		*i += 1;
	}
	if (LN[*i] != *q)
		PSFAIL("Unmatched quote.");
	return (true);
}

#define LAST_TK (ps->tk[ps->tk_len - 1])
#define LAST_RI2 (LAST_TK.type == TKT_R_I2)

static void	nloop_(const char **ln, uint32_t *i)
{
	while (LN[*i])
	{
		if (LN[*i] == '<' || LN[*i] == '>')
		{
			*i += 1 + (LN[*i] == LN[*i + 1]);
			break ;
		}
		else if (LN[*i] == '\\')
			*i += 1;
		else if (DELIM(LN[*i]))
			break ;
		*i += (LN[*i] != 0);
	}
}

static bool	loop_(t_ps *ps, const char **ln)
{
	uint32_t	i;
	char		q;

	q = 0;
	i = 0;
	if (*LN == ';' || *LN == '|')
		i = 1;
	else if (ps->tk_len > 0 && LAST_RI2)
		return (ps_tokens_ri2(ps, ln));
	else if (QUOTE(*LN) && !qloop_(ps, ln, &i, &q))
		return (false);
	else
		nloop_(ln, &i);
	MGUARD(TK.str = ft_strsub(LN, 0, i));
	LN += i + (q != 0);
	return (true);
}

void		post_(t_ps *ps, const char *ln)
{
	uint32_t	i;

	if (TK.type == TKT_NONE)
	{
		i = ~0;
		while (g_scan[++i].fn)
		{
			if (g_scan[i].fn(TK.str))
				break ;
		}
		TK.type = g_scan[i].type;
		TK.flag |= (TK.type == TKT_NONE) ? (TKF_VAR | TKF_EXP) : (0);
	}
	ps->tk_len += 1;
	if (!SPACE(*ln))
		TK.flag |= TKF_ADJ;
}

bool		ps_tokens(t_ps *ps, const char *ln)
{
	while (*ln)
	{
		ITER(ln, ft_isspace(*ln));
		BREAKIF(*ln == 0);
		if (ps->tk_len == ps->tk_mem)
		{
			MGUARD(DRALT(ps->tk, t_tk, ps->tk_mem * 2, ps->tk_mem));
			bzero(ps->tk + ps->tk_mem, ps->tk_mem * sizeof(t_tk));
		}
		if (!loop_(ps, &ln))
			return (false);
		post_(ps, ln);
	}
	return (true);
}
