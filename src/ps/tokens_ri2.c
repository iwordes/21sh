/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_ri2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:07:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/25 14:35:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN (*ln)
#define TK ps->tk[ps->tk_len]
#define L (l - (l > 0 && eof[l] && eof[l - 1] == '\\'))
#define CMP (ft_strncmp(eof, LN + n, L) == 0)

bool	ps_tokens_ri2(t_ps *ps, const char **ln)
{
	const char	*eof;
	uint32_t	l;
	uint32_t	n;

	n = 0;
	eof = LN;
	l = ft_struntil(eof, '\n');
	ITER(LN, *LN && *LN != '\n');
	LN += (*LN != 0);
	while (LN[n] && !CMP)
	{
		ITER(n, LN[n] && LN[n] != '\n');
		n += (LN[n] != 0);
	}

	ft_printf("  ... (%u)\n", n);

	if (!LN[n])
		PSFAIL("Bad heredoc.");
	if ((TK.str = ft_strsub(LN, 0, n - (n > 0))) == NULL)
		PSFAIL("Allocation failure: heredoc.");
	LN += n + l;
	return (true);
}
