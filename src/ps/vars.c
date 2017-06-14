/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 18:24:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/13 20:11:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define DELIM(C) (ft_ispunct(C) || ft_isspace(C))
#define C STR[n + 1]

#define REQUIRED (l - (n + 1) + ft_strlen(val))

/*
** TODO: Variable expansion.
*/

static bool	seterr(const char *err)
{
	g_mn.err = (char*)err;
	return (false);
}

static bool	ins_(t_tk *tk, uint32_t o)
{
	char		*key;
	char		*val;
	uint32_t	l;
	uint32_t	n;

	n = 0;
	ITER(n, !DELIM(tk->str[o + n + 1]));
	if (n == 0)
		return (seterr("Bad variable inclusion."));
	if ((key = ft_strsub(tk->str, o + 1, n)) == NULL)
		return (false);
	val = env_gets(key);
	free(key);
	l = ft_strlen(tk->str);
	if (REQUIRED > l)
	{
		if ((key = MALT(char, REQUIRED)) == NULL)
			return (false);
		ft_memcpy(key, tk->str, l + 1);
		free(tk->str);
		tk->str = key;
	}
	ft_strcut(tk->str, o, n + 1);
	ft_strins(tk->str, val, o);
	return (true);
}

#define TK ps->tk[t]

bool		ps_vars(t_ps *ps)
{
	uint32_t	t;
	uint32_t	o;

	t = 0;
	while (t < ps->tk_len)
	{
		if (TK.flag & TKF_VAR)
		{
			o = 0;
			while (TK.str[o] != 0)
			{
				if (TK.str[o] == '\\')
					o += 1;
				else if (TK.str[o] == '$' && !ins_(ps->tk + t, o))
					return (false);
				o += 1;
			}
		}
		t += 1;
	}
	return (true);
}
