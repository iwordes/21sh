/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:01:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/12 14:30:24 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define IS_QUOTE(C) (C == '\'' || C == '\"' || C == '\\')

static void	clear(char *ln)
{
	uint32_t	i;
	char		q;

	i = 0;
	q = 0;
	while (ln[i] != 0)
	{
		if (q == '\\')
		{
			if (ln[i] == '\n')
			{
				ft_strcut(ln, i - 1, 2);
				i -= 2;
			}
			q = 0;
		}
		else if (ln[i] == q)
			q = 0;
		else if (q == 0 && IS_QUOTE(ln[i]))
			q = ln[i];
		else if (ln[i] == '\n')
			ft_strcut(ln, i--, 1);
		i += 1;
	}
}

void		in_hist_add(t_in *in)
{
	char	*tmp;

	if (in->line[0] == 0)
		return ;
	if (g_mn.hist_len > 0 && ft_strequ(in->line, g_mn.hist[g_mn.hist_len - 1]))
		return ;
	if (g_mn.hist_len == g_mn.hist_mem)
	{
		MGUARD(DRALT(g_mn.hist, char*, g_mn.hist_mem * 2, g_mn.hist_mem));
		g_mn.hist_mem *= 2;
	}
	if ((tmp = ft_strdup(in->line)) == NULL)
		return ;
	clear(tmp);
	g_mn.hist[g_mn.hist_len] = tmp;
	g_mn.hist_len += 1;
}
