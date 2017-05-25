/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_ri2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:07:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/25 11:20:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static bool	cmp_(const char *lhs, const char *rhs)
{
	uint32_t	i;
	uint32_t	n;

	i = 0;
	while (rhs[i])
	{
		n = ft_struntil(rhs + i, '\n');
		if (ft_strnequ(lhs, rhs + i, n))
			return (true);
		i += n + (rhs[i + n] != 0);
	}
	return (false);
}

bool	ps_tokens_ri2(t_ps *ps, const char *ln, uint32_t *i)
{
	char		*eof;
	uint32_t	n;

	n = 0;
	ITER(*i, ft_isspace(ln[*i]));
	eof = (char*)(ln + *i);
	ITER(*i, ln[*i] && ln[*i] != '\n');
	while (ln[*i + n] && !cmp_(eof, ln + *i + n))
	{
		ITER(n, ln[*i + n] && ln[*i + n] != '\n');
		n += (ln[*i + n] != 0);
	}
	if (!cmp_(eof, ln + *i + n))
		PSFAIL("Bad heredoc.");
	*i += n;
	return (true);
}
