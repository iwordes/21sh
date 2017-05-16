/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:24:05 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/16 15:19:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** TODO: Intuitive Up/Down (Not Like Vim)
*/

#define LN in->ln[0]
#define HIST g_mn.hist[g_mn.hist_len - 1 - g_mn.h]

void	in_line_up(t_in *in)
{
	if (in->len > 1)
	{
		if (in->y > 0)
		{
			in->x += in->s;
			in->s = 0;
			in->y -= 1;
			in->x = MIN(in->x, in->ln[in->y].len);
			in_redraw(in);
		}
	}
	else if (g_mn.hist_len > 0 && g_mn.h + 1 < g_mn.hist_len)
	{
		if (g_mn.h == ~0U && in->hist == NULL)
			MGUARD(in->hist = ft_strdup(LN.ln));
		g_mn.h += 1;
		ft_bzero(LN.ln, LN.len);
		LN.len = ft_strlen(HIST);
		while (LN.mem < LN.len)
		{
			MGUARD(DRALT(LN.ln, char, LN.mem * 2, LN.mem));
			bzero(LN.ln + LN.mem, LN.mem);
			LN.mem *= 2;
		}
		ft_strcat(LN.ln, HIST);
		in->x = LN.len;
		in_redraw(in);
	}
}
