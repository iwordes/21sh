/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:16:04 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 17:45:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[y]

static void	in_redraw_cur(t_in *in, uint32_t y)
{
	if (in->s < 0)
	{
		write(1, LN.ln, in->x + in->s);
		write(1, "\e[7m", 4);
		write(1, LN.ln + in->x + in->s, -in->s);
		write(1, "\e[0m" "\e[s", 7);
		if (y + 1 < in->len)
			ft_putendl(LN.ln + in->x);
		else
			ft_putstr(LN.ln + in->x);
	}
	else
	{
		write(1, LN.ln, in->x);
		write(1, "\e[s" "\e[7m", 7);
		write(1, LN.ln + in->x, in->s);
		write(1, "\e[0m", 4);
		if (y + 1 < in->len)
			ft_putendl(LN.ln + in->x + in->s);
		else
			ft_putstr(LN.ln + in->x + in->s);
	}
}

void		in_redraw(t_in *in)
{
	uint32_t	i;
	uint32_t	y;

	i = 0;
	y = 0;
	tm_goto(-g_mn.x, -g_mn.y);
	while (y < in->len)
	{
		i += LN.ps_len;
		ft_putstr(LN.ps);
		if (y != in->y)
			ft_putendl(LN.ln);
		else
		{
			in_redraw_cur(in, y);
			g_mn.x = (LN.ps_len + in->x) % g_mn.w;
			g_mn.y = (i + in->x) / g_mn.w;
		}
		i += LN.len;
		if (y + 1 < in->len)
			i += g_mn.w - (i % g_mn.w);
		y += 1;
	}
	write(1, "\e[J" "\e[u", 6);
}
