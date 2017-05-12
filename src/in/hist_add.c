/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:01:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/11 18:14:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define IS_QUOTE(C) (C == '\'' || C == '\"' || C == '\\')

static void	clear(char *ln)
{
	char	q;

	q = 0;
	while (*ln)
	{
		if (q == '\\')
		{
			if (*ln == '\n')
				ft_strcut(ln - 1, 0, 2);
			q = 0;
		}
		else if (*ln == q)
			q = 0;
		else if (IS_QUOTE(*ln))
			q = *ln;
		ln += 1;
	}
}

void		in_hist_add(t_in *in)
{
	char	*tmp;

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
