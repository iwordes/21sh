/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:37:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/14 15:01:17 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[0]
#define HIST g_mn.hist[g_mn.hist_len - 1 - g_mn.h]

static void	line_down(t_in *in)
{
	if (in->y + 1 < in->len)
	{
		in->x += in->s;
		in->s = 0;
		in->y += 1;
		in->x = MIN(in->x, in->ln[in->y].len);
		in_redraw(in);
	}
}

static void	hist_down(t_in *in)
{
	char	*tmp;

	g_mn.h -= 1;
	in->s = 0;
	if (g_mn.h == ~0U)
		tmp = in->hist;
	else
		tmp = HIST;
	ft_bzero(LN.ln, LN.len);
	LN.len = ft_strlen(tmp);
	while (LN.mem < LN.len)
	{
		MGUARD(DRALT(LN.ln, char, LN.mem * 2, LN.mem));
		bzero(LN.ln + LN.mem, LN.mem);
		LN.mem *= 2;
	}
	ft_strcat(LN.ln, tmp);
	in->x = LN.len;
	in_redraw(in);
}

void		in_line_down(t_in *in)
{
	if (in->len > 1)
		line_down(in);
	else if (g_mn.h != ~0U)
		hist_down(in);
}
