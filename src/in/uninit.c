/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uninit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:59:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 14:05:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[i]

void	in_uninit(t_in *in)
{
	uint64_t	skip;
	uint64_t	len;
	uint32_t	i;

	g_mn.in = NULL;
	tcsetattr(0, TCSANOW, &g_mn.tm_cfg);
	i = ~0;
	len = 0;
	skip = 0;
	while (++i < in->len)
	{
		len += LN.len + 1;
		skip += LN.ps_len + LN.len;
		skip += g_mn.w - (skip % g_mn.w);
	}
	i = ~0;
	MGUARD(in->line = ZALT(char, len));
	while (++i < in->len)
	{
		if (i > 0)
			ft_strcat(in->line, "\n");
		ft_strcat(in->line, LN.ln);
		free(LN.ln);
	}
	tm_goto(-g_mn.x, (skip / g_mn.w) - (g_mn.y + 1));
	write(1, "\n", 1);
	in_hist_del(in);
	free(in->clip);
	free(in->ln);
	if (in->submit)
		return ;
	free(in->line);
	in->line = (in->cancel) ? ZALT(char, 1) : NULL;
}
